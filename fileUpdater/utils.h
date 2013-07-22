
#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
#include <string>

#include <stdlib.h>

#include <curl/curl.h>

#define MAX_VERSION_NUMBER  5
#define MAX_FILE_NUMBER     3
#define FILENAME(i)    "http://222.186.50.76:9090/static/test"".zip"

using namespace std;

extern void setnonblock (int fd);
extern void setreuseaddr(int fd);
extern void setnodelay  (int fd);

// parser xml file 
extern bool buildXML (string& fname);
extern bool dumpXML (string& fname);

extern size_t write_data (void *buffer, size_t size, size_t num, void *server_data);
extern CURLcode get_data (const char *filename, const char *url);

#endif //_UTILS_H