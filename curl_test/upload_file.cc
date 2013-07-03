#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>

static size_t write_data (void *buffer, size_t size, size_t num, void *server_data);


static CURLcode get_data (const char *filename,char *url)
{
    CURLcode rc;

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
    FILE *fp = fopen (filename, "wb");

    
    curl_easy_setopt (handler,CURLOPT_URL, url);
    curl_easy_setopt (handler,CURLOPT_WRITEFUNCTION, &write_data);
    curl_easy_setopt (handler, CURLOPT_WRITEDATA, fp);
    //curl_easy_setopt (handler, CURLOPT_TIMEOUT_MS, 3000); // Set timeout by ms
    
    // execute request
    rc = curl_easy_perform(handler);

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
    exit (0);
}

size_t write_data (void *buffer, size_t size, size_t num, void *server_data)
{
    FILE  *fp = (FILE *) server_data;
    size_t n = fwrite (buffer, size, num, fp);

    return (n);
}
