#include <limits.h>
#include "PoolT.h"
#include "gtest/gtest.h"


TEST(poolT, Basic) {
    PoolT<int> x;
    int* p = x.malloc();
    EXPECT_TRUE(p != NULL);
    EXPECT_EQ(x.size(), 1000);
    EXPECT_EQ(x.used(), 1);
}

TEST(poolT, Constructor) {
    PoolT<int> x(10);
    EXPECT_EQ(x.size(), 10);
}

TEST(poolT, maxmalloc) {
    PoolT<int> x(1);
    EXPECT_EQ(x.size(), 1);
    int* p = x.malloc();

    EXPECT_FALSE(p == NULL);
    EXPECT_EQ(x.size(), x.used());
    int* y = x.malloc();
    EXPECT_EQ(x.size(), x.used());
    EXPECT_TRUE(y == NULL);
}
