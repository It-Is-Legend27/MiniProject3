/**
 * @file main.cpp
 * @author Angel Badillo, Blake Gauna
 * @brief A simple program for reading several records consisting of a code,
 * and an address.
 * @date 2022-11-17
 * 
 */
#include <iostream>
#include <fstream>
#include <bitset>
// #include <format> C++20, must use /std:c++20 compiler flag :(
using namespace std;

int main()
{
    // Open file stream
    ifstream infile("spice.txt");

    // Stuff to read values
    unsigned int code;
    unsigned int address;
    
    // Loop until end of file
    // while(infile >> hex >> code >> address)
    // {
    //   // Do stuff here
    // }

    // Testing hex and dec output
    for(int i = 0; i < 2; ++i)
    {
        // Read in values as hex
        infile >> hex >> code >> address;
        unsigned int mask = 0xFFC00000;

        // Gives us segment number
        unsigned int segmentNum = (mask & address) >> 18;

        // See results
        cout << hex << address << '\n' << segmentNum << '\n';
        
        mask = 0x003FFE00;
        
    }

    // Close file stream
    infile.close();
}