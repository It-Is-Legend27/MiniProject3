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
    for(int i = 0; i < 10; ++i)
    {
        // Read in values as hex
        infile >> hex >> code >> address;

        // Get unique page number
        unsigned int pageNum = (un_page_mask & (address >> 11));

        // Get segment number
        unsigned int segmentNum = (segment_mask & (address >> 22));

        // Insert into sets
        // https://cplusplus.com/reference/unordered_set/unordered_set/insert/ 
        segments.insert(segmentNum);
        pages.insert(pageNum);


        // See results of bit manipulations
        cout << hex << address << ' ' << segmentNum << ' '<< pageNum << newl;
    }

    cout << "Number of segments: " << segments.size() << newl;
    cout << "Number of pages: " << pages.size() << newl;

    // Close file stream
    infile.close();
}