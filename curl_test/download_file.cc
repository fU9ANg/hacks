#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <curl/curl.h>

using namespace std;

long local_file_size = 0;

static size_t write_data (void *buffer, size_t size, size_t num, void *server_data);

static int rename_file (const char *oldpath, const char *newpath)
{
    if (oldpath == NULL || newpath == NULL)
        return (1);
    return (rename (oldpath, newpath));
}

static long get_local_file_size (const char* localpath)
{
    long filesize;
    struct stat statbuf;
    if (stat (localpath, &statbuf) < 0) {
        filesize = 0;
    }
    else {
        filesize = statbuf.st_size;
    }

    return (filesize);
}

static long get_file_size (const char* path)
{
    long filesize;
    FILE* fp;
    if ((fp = fopen (path, "r")) == NULL)
        filesize = 0;
    else {
        fseek (fp, 0L, SEEK_END);
        filesize = ftell (fp);
        fclose (fp);
    }
    return filesize;
}

static int progress_func (void* ptr, double total, double now, double uitotal, double uinow)
{
    static int progress_value = 0;
    if ((int)total == 0 && (int)now == 0) {
        progress_value = 0;
    }
    else 
    {
        int current_progress = 0;
        //printf ("[DEBUG]: total=%f, now=%f, uitotal=%f, uinow=%f\n", total, now, uitotal, uinow);
        current_progress = (int) (100.0 * ((now+local_file_size) / (total+local_file_size)));
        //printf ("[DEBUG]: current_progress=%d%%\n", current_progress);
        if (current_progress > progress_value) {
            progress_value = current_progress;
            printf ("progress=%d%%\n", progress_value);
        }
    }
    return (0);
}

static CURLcode get_data (const char* filename, char* url)
{
    CURLcode rc;

    local_file_size = get_file_size (filename);

    rc = curl_global_init (CURL_GLOBAL_ALL);
    if (rc != CURLE_OK) {
        printf ("[ERROR]: init libcurl failed.");
        return (CURLE_FAILED_INIT);
    }
    CURL* handler = curl_easy_init ();
    if (handler == NULL) {
        printf ("[ERROR]: init curl easy handler failed.");
        curl_global_cleanup ();
        return (CURLE_FAILED_INIT);
    }
    FILE *fp = fopen (filename, "ab+");

    printf ("filesize=%lu\n", local_file_size); 
    curl_easy_setopt (handler, CURLOPT_URL, url);
    curl_easy_setopt (handler, CURLOPT_RESUME_FROM_LARGE, (curl_off_t)local_file_size);
    curl_easy_setopt (handler, CURLOPT_WRITEFUNCTION, &write_data);
    curl_easy_setopt (handler, CURLOPT_WRITEDATA, fp);
    //curl_easy_setopt (handler, CURLOPT_TIMEOUT_MS, 3000); // Set timeout by ms
    curl_easy_setopt (handler, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt (handler, CURLOPT_PROGRESSFUNCTION, progress_func);
    //curl_easy_setopt (handler, CURLOPT_VERBOSE, 1L);
    
    // execute request
    rc = curl_easy_perform (handler);

    // free resources
    fclose (fp);
    curl_easy_cleanup (handler);
    curl_global_cleanup ();

    return (rc);
}

int main (int argc, char** argv)
{
    if (argc != 3) {
        printf ("usage: %s 'filename', 'server address'\n", argv[0]);
        exit (1);
    }

    get_data (argv[1], argv[2]);
    std::string tmpfilename = argv[1];
    tmpfilename += ".tmp";
    rename_file (argv[1], tmpfilename.c_str());

    size_t idx;
    if ((idx = tmpfilename.find (".tmp")) != string::npos) {
        //tmpfilename = tmpfilename.substr (0, idx);
        //cout << "tempfilename = '" << tmpfilename << "'" << endl;
        rename_file (tmpfilename.c_str(), argv[1]);
    }

    exit (0);
}

size_t write_data (void *buffer, size_t size, size_t num, void *server_data)
{
    FILE  *fp = (FILE *) server_data;
    size_t n = fwrite (buffer, size, num, fp);

    return (n);
}
