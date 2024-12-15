// Final Project Milestone 4
// Date Module
// File	Date.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;

// Define a namespace named "sdds"
namespace sdds {

    // Define the global variable
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;

    // Function to validate the date
    bool Date::validate() {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }

    // Function to get the number of days in the month
    int Date::mdays() const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * int(((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0)));
    }

    // Function to get the current system year
    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }

    // Function to set the date to today's date
    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }

    // Function to calculate the number of days since 0001/01/01
    int Date::daysSince0001_1_1() const {
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3) {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }

    // Default constructor
    Date::Date() : m_CUR_YEAR(systemYear()) {
        setToToday();
    }

    // Constructor with parameters
    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    // Function to get the error message corresponding to the error code
    const char* Date::dateStatus() const {
        return DATE_ERROR[errCode()];
    }

    // Function to get the current year
    int Date::currentYear() const {
        return m_CUR_YEAR;
    }

    // Function to set the error code
    void Date::errCode(int readErrorCode) {
        m_ErrorCode = readErrorCode;
    }

    // Function to get the error code
    int Date::errCode() const {
        return m_ErrorCode;
    }

    // Function to check if the date is valid
    bool Date::bad() const {
        return m_ErrorCode != 0;
    }

    // Overloaded insertion operator to print the Date object
    ostream& operator<<(ostream& os, const Date& RO) {
        return RO.write(os);
    }

    // Overloaded extraction operator to read the Date object
    istream& operator>>(istream& is, Date& RO) {
        return RO.read(is);
    }

    // Function to write the Date object to the output stream
    ostream& Date::write(ostream& ostr) const {
        if (bad()) {
            ostr << dateStatus();
        }
        else {
            ostr << m_year << "/" << setfill('0') << setw(2) << right 
                << m_mon << "/" << setfill('0') << setw(2) << right << m_day;
        }
        return ostr;
    }

    // Function to read the Date object from the input stream
    istream& Date::read(std::istream& is) {
        errCode(NO_ERROR); // Set the error code to no error

        is >> m_year;  // Read the year value
        is.ignore();   // Ignore the slash character
        is >> m_mon;   // Read the month value
        is.ignore();   // Ignore the slash character
        is >> m_day;   // Read the day value

        if (!is) {					   // If the input stream has failed
            errCode(CIN_FAILED);           // Set the error code to indicate a failed input
        }
        else {
            validate();                    // Validate the entered values
        }

        return is;
    }

    // Function to get the number of days since 0001/01/01
    int Date::getNoOfDays() const {
        return daysSince0001_1_1();
    }

    // Conversion operator to check if the Date object is valid
    Date::operator bool() const {
        return !bad();
    }

    // Comparison operator (equal)
    bool operator==(const Date& Date1, const Date& Date2) {
        return (Date1.getNoOfDays() == Date2.getNoOfDays());
    }

    // Comparison operator (not equal)
    bool operator!=(const Date& Date1, const Date& Date2) {
        return (Date1.getNoOfDays() != Date2.getNoOfDays());
    }

    // Comparison operator (less than or equal to)
    bool operator<=(const Date& Date1, const Date& Date2) {
        return (Date1.getNoOfDays() <= Date2.getNoOfDays());
    }

    // Comparison operator (greater than or equal to)
    bool operator>=(const Date& Date1, const Date& Date2) {
        return (Date1.getNoOfDays() >= Date2.getNoOfDays());
    }

    // Comparison operator (greater than)
    bool operator> (const Date& Date1, const Date& Date2) {
        return (Date1.getNoOfDays() > Date2.getNoOfDays());
    }

    // Comparison operator (less than)
    bool operator< (const Date& Date1, const Date& Date2) {
        return (Date1.getNoOfDays() < Date2.getNoOfDays());
    }

    // Subtraction operator to get the difference in days between two Date objects
    int operator-(const Date& Date1, const Date& Date2) {
        int days = Date1.getNoOfDays() - Date2.getNoOfDays();
        return days;
    }

    // Function to get the number of days in a specific month of a year
    int noOfDaysInMonth(int month, int year) {

        int noOfDays = 0;
        int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Check for leap year
        if (month == 2 && ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))) {
            noOfDays = arr[month - 1] + 1;
        }
        else {
            noOfDays = arr[month - 1];
        }

        return noOfDays;
    }
}

