   
#include "MD5ChecksumDefines.h"  
#include "CMD5Checksum.h"  

int main (int argc, char** argv)
{
    if (argc != 2) {
        printf ("[usage]: %s <filename>.\n", argv[0]);
        return (1);
    }

    std::string filename = argv[1];
    std::string strFileMD5 = CMD5Checksum::GetMD5 (filename);

    printf ("MD5='%s'\t\t\t -- \tFILE='%s'.\n", strFileMD5.c_str(), filename.c_str());

    return (0);
} 
