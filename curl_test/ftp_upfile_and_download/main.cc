 
#include <stdio.h>
 
#include "fud.h"
 
int main()
{
    FTP_OPT ftp_opt;
    ftp_opt.url = (char*)"ftp://127.0.0.1//SOURCES/aaaaa/ServerComponent.zip";
    ftp_opt.user_key = (char*)"anonymous:";
    ftp_opt.file = (char*)"/home/sxkj2/Public/hacks/curl_test/ftp_upfile_and_download/ServerComponent.zip";
 
    if(FTP_UPLOAD_SUCCESS == ftp_upload(ftp_opt))
        printf("Upload success.\n");
    else
        printf("Upload failed.\n");
    
    
    
    
    
#if 1 
    ftp_opt.url = (char*)"ftp://127.0.0.1//SOURCES/aaaaa/ServerComponent.zip";
    ftp_opt.file = (char*)"/home/sxkj2/Public/hacks/curl_test/ftp_upfile_and_download/ServerComponent_Download.zip";
 
    if(FTP_DOWNLOAD_SUCCESS == ftp_download(ftp_opt))
        printf("Download success.\n");
    else
        printf("Download failed.\n");
#endif 
    
    
    
    
    
    return 0;
}
