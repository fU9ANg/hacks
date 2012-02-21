
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

#ifndef __cplusplus
#error "Need a cplusplus compiler."
#endif

int main (void)
{
    return (0);
}
