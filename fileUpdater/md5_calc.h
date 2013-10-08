
#ifndef _MD5_CALC_H
#define _MD5_CALC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <openssl/md5.h>
using namespace std;

extern string calcmd5 (string filename);

#endif  //_MD5_CALC_H
