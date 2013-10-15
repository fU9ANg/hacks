#include <limits.h>
#include "twomapT.h"
#include "gtest/gtest.h"


TEST(twomapT, Negative) {
  EXPECT_EQ(1, 1);
  EXPECT_FALSE(false);
  EXPECT_TRUE(true);
  twomapT<int, int> xxx;
  xxx.insert(1,2);
  xxx.insert(11,22);

  EXPECT_EQ(xxx.value(1), 2);
}
