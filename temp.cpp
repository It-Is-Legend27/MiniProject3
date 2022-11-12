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
#include <array>
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
    array<int, 1024> l;
    
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
        bitset<32> temp = address;
        unsigned int segNum;
        string num = temp.to_string();
        for(int i = 0; i < 22; i++){
            num.pop_back();
        }
        cout << num << endl;
        bitset<10> seg(num);
        cout << hex << seg.to_ulong() << newl;
        unsigned int pageNum;
        unsigned int poffset;
        
    }
    /*
    40bc74
1
17
474
7ffebac8
1ff
7d7
2c8
    */
    
    

    // Close file stream
    infile.close();
}