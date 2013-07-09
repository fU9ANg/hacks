
//
// SSL client
//

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#ifdef _ENABLED_SSL
    #include <openssl/ssl.h>
    #include <openssl/err.h>
#endif
#include "utils.h"

int main (int argc, char **argv)
{
    int     sockfd, len;
    struct  sockaddr_in serv_addr;
    char    buffer[BUFF_SIZE + 1];
#ifdef _ENABLED_SSL
    SSL_CTX*context = NULL;
    SSL*    ssl = NULL;
#endif

    if (argc != 3) {
        printf ("usage: %s <address> <port>\n", argv[0]);
        exit (EXIT_FAILURE);
    }

#ifdef _ENABLED_SSL
    if ((context = init_ssl_library (NULL, NULL, 0)) == NULL)
        exit (EXIT_FAILURE);
#endif

    // create a socket fd
    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("Socket");
        exit (EXIT_FAILURE);
    }
    printf("[SUCC]: create socket success\n");

    // bind address to socket
    (void) memset (&serv_addr, 0x00, sizeof (serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons (atoi (argv[2]));
#if 1
    serv_addr.sin_addr.s_addr = inet_addr (argv[1]);
#else
    if (inet_aton(argv[1], (struct in_addr *) &serv_addr.sin_addr.s_addr) == 0) {
        perror(argv[1]);
        exit(errno);
    }
#endif
    printf("[SUCC]: fill address struct\n");

    // connect to server
    if (connect (sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror ("Connect");
        if (sockfd)
            close (sockfd);
        exit (EXIT_FAILURE);
    }
    printf("[SUCC]: connected to server\n");

#ifdef _ENABLED_SSL
    ssl = SSL_new (context);
    SSL_set_fd (ssl, sockfd);
    if (SSL_connect (ssl) < -1) {
        ERR_print_errors_fp (stderr);
        exit (EXIT_FAILURE);
    }
    else {
        printf ("connected with %s encryption\n", SSL_get_cipher (ssl));
        dump_centificate (ssl);
    }
#endif

    printf ("\n");
    
    (void) memset (buffer, 0x00, sizeof (buffer));
    // recv message from server
#ifdef _ENABLED_SSL
    len = SSL_read (ssl, buffer, BUFF_SIZE);
#else
    len = read (sockfd, buffer, BUFF_SIZE);
#endif
    if (len > 0) {
        printf ("[SUCC]: message='%s', %d bytes by recved.\n", buffer, len);
    }
    else {
        printf ("[FAIL]: errno=%d, '%s'\n", errno, strerror (errno));
        goto out;
    }

    (void) memset (buffer, 0x00, sizeof (buffer));
    (void) strcpy (buffer, "from CLIENT to SERVER");

    // send message to server
#ifdef _ENABLED_SSL
    len = SSL_write (ssl, buffer, strlen (buffer));
#else
    len = write (sockfd, buffer, strlen (buffer));
#endif
    if (len < 0)
        printf ("[FAIL]: message='%s', errno=%d, '%s'\n", buffer, errno, strerror (errno));
    else
        printf ("[SUCC]: message='%s', %d bytes by sended.\n", buffer, len);
               
out:
    
#ifdef _ENABLED_SSL
    SSL_shutdown (ssl);
    SSL_free (ssl);
    SSL_CTX_free (context);
#endif
    close (sockfd);

    return (EXIT_SUCCESS);
}
