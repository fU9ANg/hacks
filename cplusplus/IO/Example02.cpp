
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    // out file stream
    ofstream myfile ("example.txt");
    if (myfile.is_open ())
    {
        myfile << "This is a line." << endl;
        myfile << "This is another line.";
        myfile.close ();
    }
    else
    {
        cout << "unable to open file" << endl;
    }
    return (0);
}
