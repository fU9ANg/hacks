
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>

#include "utils.h"
#include "md5_calc.h"

using namespace std;

#define DIRNAME_SIZE    100

void dir_scan (string path, string file);
int count = 0;

int main (int argc, char **argv)
{
    struct stat s;

    if (argc != 2)
    {
        printf ("usage: %s <direction path>.\n", argv[0]);
        exit (1);
    }

    if (lstat (argv[1], &s) < 0)
    {
        printf ("[error]: lstat function.\n");
        exit (2);
    }

    if (!S_ISDIR (s.st_mode))
    {
        printf ("%s is not a direction name.\n", argv[1]);
        exit (3);
    }

    dir_scan ("", (char*) argv[1]);

    printf ("total: %d files\n", count);

    exit (0);
}

void dir_scan (string path, string file)
{
    struct   stat s;
    DIR*     dir;
    struct   dirent *dt;
    string   dirname;
    string   dirfile;
    string   md5string;

    dirname = path;

    if (lstat (file.c_str(), &s) < 0)
    {
        printf ("lstat error\n");
    }

    if (S_ISDIR (s.st_mode))
    {
        dirname += file;
        dirname += "/";
        if ((dir = opendir (file.c_str())) == NULL)
        {
            printf ("opendir %s/%s error\n", dirname.c_str(), file.c_str());
            exit (4);
        }

        if (chdir (file.c_str()) < 0)
        {
            printf ("chdir error\n");
            exit (5);
        }

        while ((dt = readdir (dir)) != NULL)
        {
            if (dt->d_name[0] == '.')
            {
                continue;
            }

            dir_scan (dirname, dt->d_name);
        }

        if (chdir ("..") < 0)
        {
            printf ("chdir error\n");
            exit (6);
        }
    }
    else
    {
        dirfile = dirname + file;
        md5string = calcmd5 (dirfile);
        string xmlfile = "./text.xml";
        string major = "1";
        string minor = "10";
        printf ("MD5: %s\tFile: %s\n", md5string.c_str(), dirfile.c_str());
        autoCreateXML (xmlfile, major, minor, md5string, dirfile);
        count++;
    }
}
