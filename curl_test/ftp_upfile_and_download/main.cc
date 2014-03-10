 
#include <stdio.h>
 
#include "fud.h"
 
int main()
{
    FTP_OPT ftp_opt;
#if 0
    ftp_opt.url = (char*)"ftp://192.168.0.254//SOURCES/aaaaa/upload.tar.gz";
    ftp_opt.user_key = (char*)"anonymous:";
    ftp_opt.file = (char*)"/home/sxkj23/hacks/curl_test/ftp_upfile_and_download/upload.tar.gz";
 
    if(FTP_UPLOAD_SUCCESS == ftp_upload(ftp_opt))
        printf("Upload success.\n");
    else
        printf("Upload failed.\n");
#endif    
    
    
    
#if 1 
    ftp_opt.url = (char*)"ftp://192.168.0.254//SOURCES/aaaaa/upload.tar.gz";
    ftp_opt.user_key = (char*)"anonymous:";
    ftp_opt.file = (char*)"/home/sxkj23/hacks/curl_test/ftp_upfile_and_download/upload_download.tar.gz";
 
    if(FTP_DOWNLOAD_SUCCESS == ftp_download(ftp_opt))
        printf("Download success.\n");
    else
        printf("Download failed.\n");
#endif 
    
    
    
    
    
    return 0;
}
