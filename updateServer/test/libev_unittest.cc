#include <limits.h>
#include "twomapT.h"
#include "gtest/gtest.h"
#include "ev.h"


TEST(libev, ev_time) {
    ev_tstamp t1 = ev_time();
//    ev_sleep(2);
    ev_tstamp t2 = ev_time();
    printf("%5.5f - %5.5f = %5.5f\n", t2, t1, t2 - t1);
}

TEST(libev, time_now) {
    struct ev_loop* loop = ev_loop_new();
    ev_tstamp t1 = ev_now(loop);
 //   ev_sleep(2);
    ev_tstamp t2 = ev_now(loop);
    printf("%5.5f - %5.5f = %5.5f\n", t2, t1, t2 - t1);
}
