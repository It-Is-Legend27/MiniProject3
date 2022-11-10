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
    for(int i = 0; i < 5; ++i)
    {
        // Read in values as hex
        infile >> hex >> code >> address;

        // Print as hex
        cout << "Hexadec: ";
        cout << hex << showbase << code << ' ' << address << '\n';
        // Print as dec
        cout << "Decimal: ";
        cout << dec << showbase << code << ' ' << address << "\n\n";
    }

    // Close file stream
    infile.close();
}