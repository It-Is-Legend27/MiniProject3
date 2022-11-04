#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    basic_fstream<unsigned int> infile("spice.txt");
    unsigned stuff;

    infile >> stuff;
    cout << hex << stuff;
}