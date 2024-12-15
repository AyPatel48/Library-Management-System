// Final Project Milestone 1 
// Date Module
// File	Utils.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>

// using namespace std; not allowed in a header file

namespace sdds {

    class Utils {
    public:
        // Convert a character to lowercase and return it.
        char tolower(char ch) const;

        // Concatenate the source string to the destination string and return the destination string.
        char* strcat(char* des, const char* src) const;

        // Compare two strings lexicographically and return the difference in their ASCII values.
        int strcmp(const char* s1, const char* s2) const;

        // Compare the first "len" characters of two strings and return the difference in their ASCII values.
        int strcmp(const char* s1, const char* s2, int len) const;

        // Copy the source string into the destination string and return the destination string.
        char* strcpy(char* des, const char* src) const;

        // Copy the first "len" characters of the source string into the destination string and return the destination string.
        char* strcpy(char* des, const char* src, int len) const;

        // Copy the first "len" characters of the source string into the destination string, up to "len" characters, and return the destination string.
        char* strncpy(char* des, const char* src, int len) const;

        // Calculate and return the length of the input string.
        int strlen(const char* str) const;

        // Find the first occurrence of "find" in "str" and return a pointer to that location. Return nullptr if not found.
        const char* strstr(const char* str, const char* find) const;

        // Check if a given character is alphabetic (a letter).
        int isalpha(char ch) const;

        // Check if a given character is whitespace (space, tab, newline, etc.).
        int isspace(char ch) const;

        // Trim leading and trailing non-alphabetic characters from the input word.
        void trim(char word[]) const;

        // Copy the source string to the destination string while converting all characters to lowercase, and return the destination string.
        char* lowerstrcpy(char des[], const char source[]) const;

        // Read characters from the standard input into "cString" until a delimiter character is encountered or "maxSize" characters are read.
        void read(char* cString, unsigned int maxSize, char delimiter = '\n') const;

        // Get an integer input from the user and return it.
        int getint(const char* prompt = nullptr, std::istream& istr = std::cin) const;

        // Get an integer input from the user within the specified range (min to max).
        int getMMInt(int min, int max);

        // Function to replicate the cin.get() function. Get an integer input from the user and return it.
        std::istream& getint(int& num, const char* prompt = nullptr, std::istream& istr = std::cin) const;

        // Reallocate memory for the destination string and copy the source string into it.
        void reAloCpy(char*& des, const char* src);

        // Allocate memory for the destination string and copy the source string into it.
        void aloCpy(char*& des, const char* src);

        // Get an integer input from the user within the specified range and display the error message if input is invalid.
        int getInteger(int minRange, int maxRange, const char* errorMessage = "Invalid Selection, try again: ");
    };

    // Declare the external instance of the Utils class.
    extern Utils ut;

}


#endif // !SDDS_UTILS_H