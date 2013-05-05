
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: #error directive.
 */

#include <iostream>

using namespace std;

#ifdef  __cplusplus
#undef  __cplusplus
#endif

#if 0
#ifndef __cplusplus
#error "Need a cplusplus compiler."
#endif
#endif

int main (void)
{
    return (0);
}
