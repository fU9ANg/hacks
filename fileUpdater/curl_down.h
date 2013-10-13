
#ifndef _CURL_DOWNFILE_H
#define _CURL_DOWNFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>



extern CURLcode get_data (const char *filename,char *url);

#endif  //_CURL_DOWNFILE_H
