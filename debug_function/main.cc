#include <iostream>
#include <string>

#include "CCDebug.h"

using namespace std;

class CCTest1
{
    public:
        void init (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }

        void update (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }

        void finish (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }
};

struct CCStruct1
{
    public:
        void init (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }

        void update (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }

        void finish (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }
};

class CCTestTestTest2
{
    public:
        void init (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }

        void update (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }

        void finish (void)
        {
            DEBUG_FUNCION;

            // TODO:
        }
};

int main ()
{
    CCTest1 c1;
    CCStruct1 s1;
    CCTestTestTest2 c2;


    c1.init ();
    c1.update ();
    c1.finish ();

    s1.init ();
    s1.update ();
    s1.finish ();

    c2.init ();
    c2.update ();
    c2.finish ();
}
