
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
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "utils.h"

SSL_CTX* init_ssl_library (char* c_file, char* p_file, int flag)
{
    SSL_CTX* context = NULL;

    if ((c_file == NULL || p_file == NULL) && (flag == 1)) {
        exit (1);
    }

    SSL_library_init ();
    OpenSSL_add_all_algorithms ();
    SSL_load_error_strings ();

    if (flag == 1)
        context = SSL_CTX_new(SSLv23_server_method ());
    else
        context = SSL_CTX_new(SSLv23_client_method ());

    if (context == NULL) {
        ERR_print_errors_fp (stdout);
        exit (EXIT_FAILURE);
    }

    if (flag == 0)
        goto out;
        
    if (SSL_CTX_use_certificate_file (context, c_file, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp (stdout);
        exit (EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file (context, p_file, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp (stdout);
        exit (EXIT_FAILURE);
    }

    if (!SSL_CTX_check_private_key (context)) {
        ERR_print_errors_fp (stdout);
        exit (EXIT_FAILURE);
    }

out:
    return (context);
}

void dump_centificate (SSL* ssl)
{
    X509 *cert = NULL;
    char *line = NULL;

    cert = SSL_get_peer_certificate (ssl);
    if (cert != NULL) {
        printf ("\n[-- DIGITAL CERTIFICATE INFORMATION --]\n");
        line = X509_NAME_oneline (X509_get_subject_name (cert), 0, 0);
        printf ("certificate: %s\n", line);
        free(line);
        line = X509_NAME_oneline(X509_get_issuer_name (cert), 0, 0);
        printf ("Issuer: %s\n", line);
        free (line);
        X509_free (cert);
    } else {
        printf ("no certificate information\n");
    }
}
