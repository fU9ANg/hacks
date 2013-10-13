
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

#define BUFF_SIZE   8192

string calcmd5 (string filename)
{
    MD5_CTX ctx;
    unsigned char outmd[16] = {0};
    int i  = 0;
    int fd = 0;
    int nread = 0;
    char block[BUFF_SIZE];
    string sresult;

    //printf ("filename='%s'\n", filename.c_str()); 
    if ((fd = open (filename.c_str(), O_RDONLY)) <= 0)
    {
        printf ("[ERROR%d]: open function.\n", fd);
        perror ("open");
        exit (1);
    }
    MD5_Init (&ctx);
    while ((nread = read (fd, block, sizeof (block))) > 0)
    {
        MD5_Update (&ctx, block, nread);
    }
    MD5_Final (outmd, &ctx);

    if (fd)
        close (fd);
    for (i = 0; i < 16; i++)
    {
        sprintf (&sresult[2*i], "%02x", outmd[i]);
    }

    return (sresult);
}
