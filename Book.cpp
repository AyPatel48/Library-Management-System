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
//Book.cpp

// Including necessary header files.
#include "Book.h"
#include <iostream>
#include <iomanip>
#include "Utils.h"
// Using a namespace named "sdds" to avoid naming conflicts.
namespace sdds {

	// Return the type of the object, in this case, 'B' representing a Book.
	char Book::type() const
	{
		return 'B';
	}

	// Implementation of the write() function for the Book class.
	std::ostream& Book::write(std::ostream& os) const {

		// Call the write() function from the base class (Publication) to write common attributes.
		Publication::write(os);

		// Check if the output stream supports console I/O (e.g., cin/cout) and format the author's name accordingly.
		if (conIO(os)) {
			os << " ";
			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			ut.strcpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
			os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << author << " |";
		}
		else {
			os << "\t" << m_authorName;
		}

		return os;
	}

	// Implementation of the read() function for the Book class.
	std::istream& Book::read(std::istream& istr) {

		char author[256] = { 0 };

		// Call the read() function from the base class (Publication) to read common attributes.
		Publication::read(istr);

		// Release any previously allocated memory for the author's name.
		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}

		// Check if the input stream supports console I/O (e.g., cin/cout) and read the author's name accordingly.
		if (conIO(istr)) {
			istr.ignore();
			std::cout << "Author: ";
		}
		else {
			istr.ignore(1000, '\t');
		}

		istr.get(author, 256);

		// If read was successful, allocate memory for the author's name and copy the content into it.
		if (istr) {
			m_authorName = new char[ut.strlen(author) + 1];
			ut.strcpy(m_authorName, author);
		}

		return istr;
	}

	// Set function for the Book class, sets member_id and resets date attributes.
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	// Conversion operator to check if a Book object is valid (has a valid author name and valid publication data).
	Book::operator bool() const
	{
		return (m_authorName != nullptr) && Publication::operator bool();
	}

	// Default constructor for the Book class, initializes the author's name to nullptr.
	Book::Book() : Publication() {
		m_authorName = nullptr;
	}

	// Copy constructor for the Book class, performs a deep copy of the author's name.
	Book::Book(const Book& src) : Publication(src) {
		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}
		m_authorName = new char[ut.strlen(src.m_authorName) + 1];
		ut.strcpy(m_authorName, src.m_authorName);
	}

	// Assignment operator for the Book class, performs a deep copy of the author's name.
	Book& Book::operator=(const Book& src) {
		if (this != &src) {
			Publication::operator=(src);
			if (m_authorName) {
				delete[] m_authorName;
				m_authorName = nullptr;
			}
			if (src.m_authorName) {
				m_authorName = new char[ut.strlen(src.m_authorName) + 1];
				ut.strcpy(m_authorName, src.m_authorName);
			}
		}
		return *this;
	}

	// Destructor for the Book class, frees the memory allocated for the author's name.
	Book::~Book() {
		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}
	}
} // End of namespace 'sdds'
