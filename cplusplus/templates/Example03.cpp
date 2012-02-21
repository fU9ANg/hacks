
/*
 * Written 2011, 2012 by fU9ANg
 *
 * Example: A simple vector with template.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include <iostream>
#include <string>
using namespace std;

template <class type>
class d2Vector
{
protected:
    int             size;
    int             capacity;
    type*           data;

public:
                    d2Vector (int nCap);
    type*           At (int index);
    type&           Front (void);
    type&           Back (void);
    type*           Begin (void);
    type*           End (void);
    int             Capacity (void);
    int             Size (void);
    void            Clear (void);
    bool            Empty (void);
    void            Erase (int index);
    void            Push (type& item);
    void            Pop (void);
    void            Resize (int nSize);
    type*           Data (void);
};

int main ()
{
#define _DEBUG_CHAR 1

#ifdef  _DEBUG_INT
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int *p = NULL;
    d2Vector<int> v (10);
#elif   _DEBUG_CHAR
    char a = 'A';
    char b = 'B';
    char c = 'C';
    char d = 'D';
    char *p = NULL;
    d2Vector<char> v (10);
#elif   _DEBUG_FLOAT
    float a = 10.1f;
    float b = 20.2f;
    float c = 30.3f;
    float d = 40.4f;
    float *p = NULL;
    d2Vector<float> v (10);
#endif

    v.Push (a);
    v.Push (b);
    v.Push (c);
    p = v.Data();
    //p++;
    if (p)
    {
        cout << "size=" << v.Size() << endl;
        cout << "capacity=" << v.Capacity() << endl;
        cout << *p << endl;
    }
    cout << "front=" << v.Front () << endl;
    cout << "back=" << v.Back () << endl;
    v.Pop ();
    cout << "front=" << v.Front () << endl;
    cout << "back=" << v.Back () << endl;
    v.Push (d);
    cout << "front=" << v.Front () << endl;
    cout << "back=" << v.Back () << endl;
    v.Resize (20);
    cout << "--- After of Resize ---" << endl;
    p = v.Data ();
    if (p)
    {
        cout << "size=" << v.Size() << endl;
        cout << "capacity=" << v.Capacity() << endl;
    }
    cout << *(p+2) << endl;
}

template <class type>
inline type* d2Vector<type> :: Data (void)
{
    if (data)
        return (data);
    else
        return (NULL);
}

template <class type>
inline d2Vector<type> :: d2Vector (int nCap)
{
    if (nCap != 0)
    {
        capacity = nCap;
        size = 0;
        data = (type *) malloc (sizeof (type) * capacity);
    }
}

template <class type>
inline void d2Vector<type> :: Pop (void)
{
    if (data == NULL)
        return;
    if (size == capacity)
        return;

    size--;
}

template <class type>
inline void d2Vector<type> :: Push (type& item)
{
    if (data == NULL)
        return;
    if (size == capacity)
        return;

    //memcpy (data[size+1], item, sizeof (type));
    data[size] = item;
    size++;
}

template <class type>
inline void d2Vector<type> :: Erase (int index)
{
    if (data == NULL)
        return;
    if (index < size)
        return;

    for (int i = 0; i < size; ++i)
    {
        if (&data[i] == &data[index])   // found it.
        {
            for (int j = i; j < size - 1; j++)
            {
                memcpy (data[j], data[j+1], sizeof (type));
            }
            size--;
        }
    }
}

template <class type>
inline bool d2Vector<type> :: Empty (void)
{
    if (size == 0)
        return (true);
    else
        return (false);
}

template <class type>
inline void d2Vector<type> :: Clear (void)
{
    if (data)
        delete [] data;

    data     = NULL;
    size     = 0;
    capacity = 0;
}

template <class type>
inline type* d2Vector<type> :: At (int index)
{
    if (index < size)
    {
        return (&data[index]);
    }
    return (NULL);
}

template <class type>
inline type* d2Vector<type> :: Begin (void)
{
    if (data)
    {
        return (&data [0]);
    }
    return (NULL);
}

template <class type>
inline type* d2Vector<type> :: End (void)
{
    if (data)
    {
        return (&data [size]);
    }
    return (NULL);
}

template <class type>
inline type& d2Vector<type> :: Front (void)
{
    if (data)
    {
        return (data [0]);
    }
}

template <class type>
inline type& d2Vector<type> :: Back (void)
{
    if (data)
    {
        return (data [size-1]);
    }
}

template <class type>
inline void d2Vector<type> :: Resize (int nSize)
{
    type* tmp = NULL;

    if (capacity != nSize)
    {
        type *alloc = (type *) malloc (sizeof (type) * nSize);
        if (alloc)
        {
            tmp = data;
            data = alloc;
            if (capacity > nSize)
                memcpy (data, tmp, sizeof (type) * nSize);
            else
                memcpy (data, tmp, sizeof (type) * capacity);
        }
        capacity = nSize;
    }
}

template <class type>
inline int d2Vector<type> :: Size (void)
{
    return (size);
}

template <class type>
inline int d2Vector<type> :: Capacity (void)
{
    return (capacity);
}
