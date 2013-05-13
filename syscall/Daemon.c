
int main (int argc, char** argv)
{
    Daemon ();
}

int Daemon (void)
{
    int     i;
    pid_t   pid;

    if ((pid = fork ()) < 0) {
        printf ("ERROR: fork()\n");
        return (1);
    }
    else if (pid) {
        exit (0);
    }

    /* child 1 */
    if (setsid () < 0) {
        printf ("ERROR: setsid()\n");
        return (1);
    }

    (void) signal (SIGHUP, SIG_IGN);

    if ((pid = fork ()) < 0) {
        printf ("ERROR: fork()\n");
        return (1);
    }
    else if (pid) {
        exit (0);
    }

    /* child 2 */

    chdir ("/");

    /* close off file descriptors */
    for (i = 0; i < MAXFD; i++) {
        close (i);
    }

    open ("/dev/null", O_RDONLY);
    open ("/dev/null", O_WRONLY);
    open ("/dev/null", O_RDWR);

    return (0);
}
