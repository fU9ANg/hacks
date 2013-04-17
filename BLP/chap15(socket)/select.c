
// @2012, 2013
// by fU9ANg

#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main (int argc, char** argv)
{
    char buffer[128];

    int result, nread;
    fd_set inputs, testfds;
    struct timeval timeout;

    // initialize inputs fd
    FD_ZERO (&inputs);
    FD_SET (0, &inputs);

    while (1) {

        testfds = inputs;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000;

        result = select (FD_SETSIZE, &testfds, (fd_set*)NULL, (fd_set*)NULL, &timeout);

        switch (result) {
        case 0:
            printf ("timeout\n");
            break;
        case -1:
            perror ("select");
            return (1);
        default:
            if (FD_ISSET (0, &testfds)) {
                ioctl (0, FIONREAD, &nread);
                // if input control character is CTRL+D
                if (nread == 0) {
                    printf ("keyboard done\n");
                    return (0);
                }

                nread = read (0, buffer, nread);
                buffer[nread] = 0x00;
                printf ("read %d from keyboard: %s", nread, buffer);
            }
            break;
        }
    }

    return (0);
}
