#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

static int send_data (char *filename, char *url)
{
    CURL *curl;
    CURLcode rc;

    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr  = NULL;
    struct curl_slist *headerlist  = NULL;
    static const char buf[] = "Expect:";

    rc = curl_global_init (CURL_GLOBAL_ALL);
    if (rc != CURLE_OK) {
        printf ("[ERROR]: init libcurl failed.");
        return (CURLE_FAILED_INIT);
    }

    /* Fill in the file upload field */
    curl_formadd (&formpost,
                  &lastptr,
                  CURLFORM_COPYNAME, "myfile",
                  CURLFORM_FILE, filename,
                  CURLFORM_END);

    /* Fill in the filename field */
    curl_formadd (&formpost,
                  &lastptr,
                  CURLFORM_COPYNAME, "filename",
                  CURLFORM_COPYCONTENTS, filename,
                  CURLFORM_END);


    /* Fill in the submit field too, even if this is rarely needed */
    curl_formadd (&formpost,
                  &lastptr,
                  CURLFORM_COPYNAME, "submit",
                  CURLFORM_COPYCONTENTS, "send",
                  CURLFORM_END);

    curl = curl_easy_init ();
    /* initalize custom header list (stating that Expect: 100-continue is not
       wanted */
    headerlist = curl_slist_append (headerlist, buf);
    if (curl)
    {
        /* what URL that receives this POST */
        curl_easy_setopt (curl, CURLOPT_URL, url);
        curl_easy_setopt (curl, CURLOPT_HTTPHEADER, headerlist);
        curl_easy_setopt (curl, CURLOPT_HTTPPOST, formpost);

        /* Perform the request, rc will get the return code */
        rc = curl_easy_perform (curl);

        /* Check for errors */
        if (rc != CURLE_OK) {
            fprintf (stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror (rc));
            return (CURLE_FAILED_INIT);
        }

        /* always cleanup */
        curl_easy_cleanup (curl);

        /* then cleanup the formpost chain */
        curl_formfree (formpost);

        /* free server list */
        curl_slist_free_all (headerlist);
    }
    return (0);
}

int main (int argc, char* argv[])
{
    if (argc != 3) {
        printf ("usage: %s 'filename', 'server address'\n", argv[0]);
        exit (1);
    }

    send_data (argv[1], argv[2]);
    exit (0);
}
