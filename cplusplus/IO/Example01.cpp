
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    // out file stream
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file." << endl;
    myfile.close ();

    return (0);
}
