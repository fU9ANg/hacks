
#include <iostream>
#include "CMemcached.hpp"

using namespace std;

int main ()
{
    CMemcached mc;

    mc.insert ("account", "fU9ANg", 5);
    mc.insert ("password", "******", 10);
    mc.insert ("e-mail", "bb.newlife@gmail.com", 15);
    cout << "Account:\t" << mc.select ("account") << endl;
    cout << "Password:\t" << mc.select ("password") << endl;
    cout << "E-Mail:\t" << mc.select ("e-mail") << endl;
    
    return 1;
}
