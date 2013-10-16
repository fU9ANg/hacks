

// 2012, 2013 by fU9ANg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> // for inet
#include <arpa/inet.h>  // for inet
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#include <curl/curl.h>

#include "utils.h"
#include "updater.pb.h"

#define     MAXBUFF 8192

int main (int argc, char** argv)
{
    int sock_fd;
    int len, n;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    char recvbuf[MAXBUFF];

    if ((sock_fd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("oops: socket ");
        return (1);
    }

    (void) memset (&address, 0x00, sizeof (struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr ("192.168.0.254");
    address.sin_port = htons (15432);
    len = sizeof (address);


    if ((result = connect (sock_fd, (struct sockaddr*) &address, len)) < 0) {
        perror ("oops: connect ");
        return (1);
    }

    write (sock_fd, &ch, 1);

    while ((n = read (sock_fd, recvbuf, sizeof (recvbuf))) > 0) {
        recvbuf[n] = 0x00;

        string s_update;
        updater update;
        s_update = recvbuf;
        cout << "ParseFromString..."
            << endl;
        //s_update = recvbuf;
        update.ParseFromString (s_update);
        WriteToFile (update.content (), "OUTOUTOUT.xml");
        cout << "content: " << update.content ();
        getchar ();
#if 0
        cout << "major=" << update.major() << endl;
        cout << "minor=" << update.minor() << endl;
        cout << "size =" << update.size () << endl;
        cout << "date =" << update.date () << endl;
        cout << "addr =" << update.addr () << endl;
#endif
    char s1[] = "server-7.13.tar.gz";
    (void) s1;
    cout << "[INFO]: down-loading files!" << endl;
    //get_data (s1, update.addr().c_str());    // 'filename', 'server address'
    cout << "---------DOWNLOADED-------------" << endl;
    }

    cout << "herere" << endl;
    char s1[] = "server-7.13.tar.gz";
    char s2[] = "http://222.186.50.76:9090/static/server-7.13.tar.gz";
    cout << "[info]: down-loading files!" << endl;
    get_data (s1, s2);    // 'filename', 'server address'

    printf ("character='%c', from server\n", ch);

    if (sock_fd)
        close (sock_fd);

    return (0);
}
