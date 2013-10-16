#include <limits.h>
#include "Buf.h"
#include "gtest/gtest.h"


TEST(Buf, Basic) {
    Buf b;
    b.reset();
    memcpy(b.ptr(), "hellow", strlen("hellow"));
    Buf c; 
    c= b;
    printf("%p  %p\n",b.ptr(), c.ptr());
    printf("%s\n", (char*)c.ptr());
}

TEST(Buf, Operatorassign) {
    Buf b;
    b.reset();
    memcpy(b.ptr(), "hellow", strlen("hellow"));
    Buf c; 
    c= b;
    printf("%p  %p\n",b.ptr(), c.ptr());
    EXPECT_FALSE(b.ptr() == c.ptr());
    printf("%s\n", (char*)c.ptr());
}
