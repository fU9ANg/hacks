
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include <curl/curl.h>

void setnonblock (int fd)
{
    fcntl (fd, F_SETFL, fcntl (fd, F_GETFL, 0) | O_NONBLOCK);
}

void setreuseaddr (int fd)
{
    int reuse = 1;
    setsockopt (fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof (reuse));
}

void setnodelay (int fd)
{
    int nodelay = 1;
    setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, &nodelay, sizeof (nodelay));
}

// XML

bool autoCreateXML (string& fname, string& major, string& minor, string& md5, string& filename)
{
    int i, j;
    try {
        TiXmlDocument* doc = new TiXmlDocument ();
        TiXmlElement* root = new TiXmlElement ("xml");
        doc->LinkEndChild (root);

        for (i = 0; i < MAX_VERSION_NUMBER; i++) {
            TiXmlElement* version = new TiXmlElement ("version");
            version->SetAttribute ("major", major.c_str());
            version->SetAttribute ("minor", minor.c_str());
            root->LinkEndChild (version);

            for (j = 0; j < MAX_FILE_NUMBER; j++) {
                TiXmlElement* file = new TiXmlElement ("File");
                file->SetAttribute ("md5sum", md5.c_str ());
                version->LinkEndChild (file);

                TiXmlText* file_content = new TiXmlText (filename.c_str ());
                file->LinkEndChild (file_content);
            }
        }
        doc->SaveFile (fname.c_str());
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}

bool buildXML (string& fname)
{
    int i, j;
    try {
        TiXmlDocument* doc = new TiXmlDocument ();
        TiXmlElement* root = new TiXmlElement ("Updates");
        doc->LinkEndChild (root);

        for (i = 0; i < MAX_VERSION_NUMBER; i++) {
            TiXmlElement* version = new TiXmlElement ("Version");
            version->SetAttribute ("major", "1");
            version->SetAttribute ("minor", "2");
            root->LinkEndChild (version);

            for (j = 0; j < MAX_FILE_NUMBER; j++) {
                TiXmlElement* file = new TiXmlElement ("File");
                file->SetAttribute ("size", "130k");
                file->SetAttribute ("date", "2013/7/13 12:10:10");
                version->LinkEndChild (file);

                TiXmlText* file_content = new TiXmlText (FILENAME (10));
                file->LinkEndChild (file_content);
            }
        }
        doc->SaveFile (fname.c_str());
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}

bool dumpXML (string& fname)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument (fname.c_str());
        doc->LoadFile ();
        TiXmlElement* root = doc->RootElement ();
        
        cout << root->Value () << endl;

        TiXmlElement* version = root->FirstChildElement ();
        TiXmlAttribute* atti_major = version->FirstAttribute ();
        TiXmlAttribute* atti_minor = version->LastAttribute ();

        TiXmlElement* file = version->FirstChildElement ();
        TiXmlAttribute* atti_size = file->FirstAttribute ();
        TiXmlAttribute* atti_date = file->LastAttribute ();

        cout << version->FirstChild ()->Value() << endl;
        cout << atti_major->Name () << ": " << atti_major->Value () << ", " <<
        atti_minor->Name () << ": " << atti_minor->Value () << endl;
        cout << file->FirstChild ()->Value() << endl;
        cout << atti_size->Name () << ": " << atti_size->Value () << ", " << \
        atti_date->Name () << ": " << atti_date->Value () << endl;

    }
    catch (string& e) {
        return (false);
    }

    return true;
}

CURLcode get_data (const char *filename, const char *url)
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

    
    curl_easy_setopt (handler, CURLOPT_URL, url);
    curl_easy_setopt (handler, CURLOPT_WRITEFUNCTION, &write_data);
    curl_easy_setopt (handler, CURLOPT_WRITEDATA, fp);
    //curl_easy_setopt (handler, CURLOPT_TIMEOUT_MS, 3000); // Set timeout by ms
    
    // execute request
    rc = curl_easy_perform (handler);

    // free resources
    fclose (fp);
    curl_easy_cleanup (handler);
    curl_global_cleanup ();

    return (rc);
}

size_t write_data (void *buffer, size_t size, size_t num, void *server_data)
{
    FILE  *fp = (FILE *) server_data;
    size_t n = fwrite (buffer, size, num, fp);

    return (n);
}
