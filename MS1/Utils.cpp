/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date : 2023/07/09
// Author : Ayushkumar Patel
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {

    // This function gets an integer input from the user within the specified range.
    int getInteger(int minRange, int maxRange) {
        int input;
        bool validInt = false;
        while (validInt == false)
        {
            cin >> input; // Read user input

            // Check if the input is not a valid integer or outside the specified range
            if (!cin || input < minRange || input > maxRange)
            {
                std::cout << "Invalid Selection, try again: ";
                cin.clear(); // Clear any error flags
                cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer
                validInt = false; // The input is invalid, continue the loop
            }
            else
            {
                validInt = true; // The input is valid, exit the loop
            }

        }
        return input; // Return the valid input
    }

}
