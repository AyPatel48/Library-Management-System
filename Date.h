// Final Project Milestone 4
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo, Ayushkumar Patel
/******************************************************************************
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : NAA
Date	   : 26/07/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
******************************************************************************/


#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds {
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int  MIN_YEAR = 1500;
    class Date {
    private:
        // private member variables
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;

        // returns number of days passed since the date 0001/1/1
        int daysSince0001_1_1()const;

        // validates the date setting the error code and then returning the result true, if valid, and false if invalid.
        bool validate();

        // sets the error code
        void errCode(int);

        // returns the current system year
        int systemYear()const;

        // return true if m_ErrorCode is not zero
        bool bad()const;

        // returns the number of days in current month
        int mdays()const;

        // sets the date to the current date (system date)
        void setToToday();

    public:

        // creates a date with current date
        Date();

        /* create a date with assigned values then validates the date and sets the error code accordingly */
        Date(int year, int mon, int day);

        // returns the error code or zero if date is valid
        int errCode()const;

        // returns a string corresponding the current status of the date
        const char* dateStatus()const;

        // returns the m_CUR_YEAR value;
        int currentYear()const;

        // calls the daysSince0001_1_1() function and returns the number of days passed since the date 0001/1/1
        int getNoOfDays() const;

        // returns true if the date is valid
        operator bool()const;

        // IO member functions
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout)const;

    };
    // Insertion and extraction operator overloads prototypes for cout and cin
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);

    // Comparison operator overloads prototypes for ==, !=, >, <, >=, <=
    bool operator==(const Date& Date1, const Date& Date2);
    bool operator!=(const Date& Date1, const Date& Date2);
    bool operator> (const Date& Date1, const Date& Date2);
    bool operator< (const Date& Date1, const Date& Date2);
    bool operator>=(const Date& Date1, const Date& Date2);
    bool operator<=(const Date& Date1, const Date& Date2);

    // Binary operator overloads prototypes for -
    int operator-(const Date& Date1, const Date& Date2);

    // Helper functions prototypes
    int noOfDaysInMonth(int month, int year);

    // Global variables made truly global for testing purposes
    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;

}


#endif