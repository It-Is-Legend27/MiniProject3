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
#define newl '\n'
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
        unsigned int mask = 0x7FF;
        unsigned int poffset = (mask & address);
        unsigned int pageNum = (mask & (address >> 11));
        mask = 0x3FF;
        unsigned int segmentNum = (mask & (address >> 22));
        // 010000001011110001110100
        // See results
        cout << hex << address << newl<< segmentNum << newl << pageNum << newl << poffset << newl;
    }

    // Close file stream
    infile.close();
}