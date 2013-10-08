
// compiling: g++ md5_calc.cc -lcrypto -lssl
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <openssl/md5.h>

#include "md5_calc.h"

using namespace std;

#define BUFF_SIZE   4096

int calcmd5 (string filename)
{
    MD5_CTX ctx;
    unsigned char outmd[16] = {0};
    int i = 0;
    int fd = 0;
    char block[BUFF_SIZE];
    int nread = 0;

    if ((fd = open (filename.c_str(), O_RDONLY)) <= 0)
    {
        printf ("[ERROR]: open function.\n");
        exit (1);
    }
    MD5_Init (&ctx);
    while ((nread = read (fd, block, sizeof (block))) > 0)
    {
        MD5_Update (&ctx, block, nread);
    }
    MD5_Final (outmd, &ctx);

    if (fd) close (fd);
    for (i = 0; i < 16; i++)
        printf ("%02x", outmd[i]);

    //printf ("\n");

    return (0);
}

#if 0
int main ()
{
    return (calcmd5 ("/home/sxkj7/hacks/fileUpdater/build/server-7.13.tar.gz"));
    
}
#endif