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
#include <unordered_set>
using namespace std;

// Mask for segment number
const unsigned int segment_mask = 0x3FF;

// Mask for unique page number
const unsigned int page_mask = 0x7FF;

int main()
{
    // Open file stream
    ifstream infile("spice.txt");

    // Store code and address
    unsigned int code;
    unsigned int address;

    // Unordered sets to store unique values
    unordered_set<unsigned int> segments;
    unordered_set<unsigned int> pages;

    // Loop until end of file, read code and address
    while (infile >> hex >> code >> address)
    {
        // Get unique page number
        unsigned int pageNum = page_mask & (address >> 11);

        // Get segment number
        unsigned int segmentNum = segment_mask & (address >> 22);
        
        // Store unique values into sets
        segments.insert(segmentNum);
        pages.insert(pageNum);
    }

    // Print the number of different segments and pages
    cout << dec << "Number of segments: " << segments.size() << '\n';
    cout << dec << "Number of pages: " << pages.size() << '\n';
    
    // Close file stream
    infile.close();
}