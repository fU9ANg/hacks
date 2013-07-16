
//
// SSL server 
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#ifdef _ENABLED_SSL
    #include <openssl/ssl.h>
    #include <openssl/err.h>
#endif
#include "utils.h"

int main(int argc, char **argv)
{
    int listenfd, clientfd;
    socklen_t len;
    struct sockaddr_in sock_addr, client_addr;
    char buffer[BUFF_SIZE + 1];
#ifdef _ENABLED_SSL
    SSL_CTX *context;
    char* centificate = NULL;
    char* private_key = NULL; 
#endif

    char* s_host = NULL; 
    char* s_port = NULL; 

#ifdef _ENABLED_SSL
    if (argc != 5) {
        printf ("usage: %s <host> <port> <certificate file> <private_key file>\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    centificate = argv[3];
    private_key = argv[4];
#else
    if (argc != 3) {
        printf ("usage: %s <host> <port>\n", argv[0]);
        exit (EXIT_FAILURE);
    }
#endif

    s_host = argv[1];
    s_port = argv[2];

#ifdef _ENABLED_SSL
    if ((context = init_ssl_library (centificate, private_key, 1)) == NULL)
        exit (1);
#endif
    
    if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) == -1) {
        perror ("socket");
        exit (EXIT_FAILURE);
    } else
        printf ("[INFO]: create socket success\n");

    (void) memset (&sock_addr, 0x00, sizeof (sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons (atoi (s_port));
    if (s_host)
        sock_addr.sin_addr.s_addr = inet_addr (s_host);
    else
        sock_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind (listenfd, (struct sockaddr *) &sock_addr, sizeof (struct sockaddr)) < 0) {
        perror ("bind");
        if (listenfd)
            close (listenfd);
        exit (EXIT_FAILURE);
    }
    printf ("[INFO]: bind inet address to socket fd\n");

    if (listen (listenfd, 5) == -1) {
        perror ("listen");
        exit (EXIT_FAILURE);
    }
    printf ("[INFO]: listen...\n");

    for (;;) {
        SSL *ssl = NULL;
        len = sizeof (struct sockaddr);

        // accept client request of socket
        if ((clientfd = accept (listenfd, (struct sockaddr *) &client_addr, &len)) < 0) {
            perror ("accept");
            exit (errno);
        }
        else {
            printf ("---------------------\n");
            printf ("[INFO]: new connection from %s, port %d, socket %d\n", inet_ntoa (client_addr.sin_addr),
                   ntohs (client_addr.sin_port), clientfd);
        }

#ifdef _ENABLED_SSL
        ssl = SSL_new (context);
        SSL_set_fd (ssl, clientfd);
        if (SSL_accept (ssl) == -1) {
            perror ("accept");
            close (clientfd);
            break;
        }
#endif

        (void) memset (buffer, 0x00, sizeof (buffer));
        (void) strcpy (buffer, "from SERVER to CLIENT");

        // send
#ifdef _ENABLED_SSL
        len = SSL_write (ssl, buffer, strlen (buffer));
#else
        len = write (clientfd, buffer, strlen (buffer));
#endif

        if (len <= 0) {
            printf ("[FAIL]: message='%s', errno=%d, '%s'\n", buffer, errno, strerror (errno));
            goto out;
        }
        else {
            printf ("[SUCC]: message='%s', %d bytes by sended\n", buffer, len);
        }

        (void) memset (buffer, 0x00, sizeof (buffer));
        
        // recv
#ifdef _ENABLED_SSL
        len = SSL_read (ssl, buffer, BUFF_SIZE);
#else
        len = read (clientfd, buffer, BUFF_SIZE);
#endif
        if (len > 0)
            printf ("[SUCC]: message='%s', %d bytes by recved\n", buffer, len);
        else
            printf ("[FAIL]: errno=%d, '%s'\n", errno, strerror(errno));
            
out:
#ifdef _ENABLED_SSL
        SSL_shutdown (ssl);
        SSL_free (ssl);
#endif
        close (clientfd);
    }

    close (listenfd);
#ifdef _ENABLED_SSL
    SSL_CTX_free (context);
#endif

    return (EXIT_SUCCESS);
}
