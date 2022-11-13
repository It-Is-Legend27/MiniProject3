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
#include <vector>
#include <unordered_set>
#define newl '\n'
using namespace std;

const unsigned int segment_mask = 0x3FF;
const unsigned int un_page_mask = 0x1FFFFF;

int main()
{
    // Open file stream
    ifstream infile("spice.txt");

    // Stuff to read values
    unsigned int code;
    unsigned int address;

    // Data structs to hold stuff
    unordered_set<unsigned int> segments;
    unordered_set<unsigned int> pages;
    
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

        /* We probably don't need this */
        // unsigned int mask = 0x7FF;
        // unsigned int poffset = (mask & address);
        // unsigned int pageNum = (mask & (address >> 11));

        unsigned int pageNum = (un_page_mask & (address >> 11));
        unsigned int segmentNum = (segment_mask & (address >> 22));
        
        // See results
        cout << hex << address << newl << segmentNum << newl << pageNum << newl;
    }

    // Close file stream
    infile.close();
}