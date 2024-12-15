// Final Project Milestone 1 
// Date Module
// File	Utils.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Utils.h"

namespace sdds {

    Utils ut; // Create an instance of the Utils class called "ut"

    // Concatenate the source string to the destination string and return the destination string.
    char* Utils::strcat(char* des, const char* src)const {
        int len = strlen(des);
        int i = 0;
        while (src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = char(0); // Null-terminate the destination string
        return des;
    }

    // Get an integer input from the user and return it.
    int Utils::getint(const char* prompt, istream& istr)const {
        int num;
        if (prompt) cout << prompt; // If prompt is provided, display it
        istr >> num; // Read integer input from the istream
        istr.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer
        return num;
    }

    // Function to replicate the cin.get() function. Get an integer input from the user and return it.
    istream& Utils::getint(int& num, const char* prompt, istream& istr)const {
        num = getint(prompt, istr); // Call the getint function and store the result in "num"
        return istr; // Return the istream object for chaining input operations
    }

    // Get an integer input from the user within the specified range (min to max).
    int Utils::getMMInt(int min, int max) {
        int value;
        bool done = false;
        while (done == false)
        {
            cin >> value; // Read user input

            // Check if the input is not a valid integer or outside the specified range
            if (!cin || value < min || value > max)
            {
                cout << "Invalid Selection, try again: ";
                cin.clear(); // Clear any error flags
                cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer
                done = false; // The input is invalid, continue the loop
            }
            else
            {
                done = true; // The input is valid, exit the loop
            }
        }
        return value; // Return the valid input
    }

    // Reallocate memory for the destination string and copy the source string into it.
    void Utils::reAloCpy(char*& des, const char* src) {
        delete[] des; // Deallocate the existing memory for "des"
        aloCpy(des, src); // Call "aloCpy" to allocate new memory and copy "src" into "des"
    }

    // Allocate memory for the destination string and copy the source string into it.
    void Utils::aloCpy(char*& des, const char* src) {
        des = nullptr; // Set "des" to nullptr to avoid potential memory issues
        if (src) {
            des = new char[ut.strlen(src) + 1]; // Allocate memory for "des" with the appropriate size
            ut.strcpy(des, src); // Copy the content of "src" into "des"
        }
    }

    // Convert a character to lowercase if it is uppercase, and return the character.
    char Utils::tolower(char ch)const {
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
        return ch;
    }

    // Compare two strings lexicographically and return the difference in their ASCII values.
    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    // Compare the first "len" characters of two strings and return the difference in their ASCII values.
    int Utils::strcmp(const char* s1, const char* s2, int len)const {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }

    // Copy the source string into the destination string and return the destination string.
    char* Utils::strcpy(char* des, const char* src)const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0); // Null-terminate the destination string
        return des;
    }

    // Copy the first "len" characters of the source string into the destination string and return the destination string.
    char* Utils::strcpy(char* des, const char* src, int len)const {
        int i;
        for (i = 0; i < len && src[i]; i++) des[i] = src[i];
        des[i] = 0; // Unlike strncpy, this function null terminates the destination string
        return des;
    }

    // Copy the first "len" characters of the source string into the destination string, up to "len" characters, and return the destination string.
    char* Utils::strncpy(char* des, const char* src, int len)const {
        int i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i]; // Null-terminate the destination string
        return des;
    }

    // Calculate and return the length of the input string.
    int Utils::strlen(const char* str)const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    // Find the first occurrence of "find" in "str" and return a pointer to that location. Return nullptr if not found.
    const char* Utils::strstr(const char* str, const char* find)const {
        const char* faddress = nullptr;
        int i, flen = strlen(find), slen = strlen(str);
        for (i = 0; i <= slen - flen && strcmp(&str[i], find, flen); i++);
        if (i <= slen - flen) faddress = &str[i];
        return faddress;
    }

    // Check if a given character is alphabetic (a letter).
    int Utils::isalpha(char ch)const {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    // Check if a given character is whitespace (space, tab, newline, etc.).
    int Utils::isspace(char ch)const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    // Trim leading and trailing non-alphabetic characters from the input word.
    void Utils::trim(char word[])const {
        int i;
        while (word[0] && !isalpha(word[0])) {
            strcpy(word, word + 1);
        }
        i = strlen(word);
        while (i && !isalpha(word[i - 1])) {
            word[i-- - 1] = char(0);
        }
    }

    // Copy the source string to the destination string while converting all characters to lowercase, and return the destination string.
    char* Utils::lowerstrcpy(char des[], const char source[])const {
        int i = 0, j = 0;
        for (; source[i] != 0; i++) {
            des[j++] = tolower(source[i]);
        }
        des[j] = char(0); // Null-terminate the destination string
        return des;
    }

    // Read characters from the standard input into "cString" until a delimiter character is encountered or "maxSize" characters are read.
    void Utils::read(char* cString, unsigned int maxSize, char delimiter)const {
        char ch = 0;
        unsigned int i = 0;
        do {    // skipping leading white space chars
            std::cin.get(ch);
        } while (isspace(ch));
        // read char by char until hitting delimiter or maxSize
        for (i = 0; i < maxSize && ch != delimiter; i++) {
            cString[i] = ch;
            if (i < maxSize - 1) std::cin.get(ch);
        }
        cString[i] = char(0); // Null-terminate the string
    }

    // This function gets an integer input from the user within the specified range.
    int Utils::getInteger(int minRange, int maxRange, const char* errorMessage) {
        int input;
        bool validInt = false;
        while (validInt == false)
        {
            cin >> input; // Read user input

            // Check if the input is not a valid integer or outside the specified range
            if (!cin || input < minRange || input > maxRange)
            {
                std::cout << errorMessage; // Display error message
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

    extern Utils ut; // Declare the external instance of the Utils class

}
