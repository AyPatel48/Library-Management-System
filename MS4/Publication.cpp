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
//Publication.cpp

// Disable some secure CRT warnings
#define _CRT_SECURE_NO_WARNINGS

// Include necessary headers
#include "Publication.h"
#include <iostream>
#include <iomanip>
#include <cstring>

// Use the namespace sdds
namespace sdds {

	// Default constructor
	Publication::Publication() {
		setToDefault(); // Initialize member variables to default values
	}

	// Destructor
	Publication::~Publication() {
		delete[] m_title; // Deallocate memory for the title string
		/*m_title = nullptr;*/ // Unnecessary - commented out to avoid confusion
	}

	// Copy constructor
	Publication::Publication(const Publication& publication) {
		*this = publication; // Call the assignment operator to perform a deep copy
	}

	// Assignment operator
	Publication& Publication::operator=(const Publication& publication) {
		// Copy member variables from the source publication
		set(publication.m_membership);
		setRef(publication.m_libRef);
		m_date = publication.m_date;
		strcpy(m_shelfId, publication.m_shelfId);

		// Release memory for the existing title
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}

		// Allocate memory for the new title and copy it
		if (publication.m_title) {
			m_title = new char[strlen(publication.m_title) + 1];
			strcpy(m_title, publication.m_title);
		}
		else {
			m_title = nullptr;
		}

		return *this; // Return the current object after the assignment
	}

	// Initialize member variables to default values
	void Publication::setToDefault() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate(); // Reset the date to a default value (presumably the current date)
	}

	// Set the membership ID
	void Publication::set(int member_id) {
		m_membership = member_id;
	}

	// Set the library reference value
	void Publication::setRef(int value) {
		m_libRef = value;
	}

	// Reset the publication date to a default value
	void Publication::resetDate() {
		m_date = Date();
	}

	// Get the type of publication (in this case, 'P' for Publication)
	char Publication::type() const {
		return 'P';
	}

	// Check if the publication is currently on loan (has a membership associated with it)
	bool Publication::onLoan() const {
		return (m_membership != 0);
	}

	// Get the checkout date of the publication
	Date Publication::checkoutDate() const {
		return m_date;
	}

	// Check if the publication's title matches the given title
	bool Publication::operator==(const char* title) const {
		return strstr(m_title, title) != nullptr;
	}

	// Conversion operator to const char*
	Publication::operator const char* () const {
		return m_title;
	}

	// Get the library reference value of the publication
	int Publication::getRef() const {
		return m_libRef;
	}

	// Check if the given ios object is cin or cout (console I/O)
	bool Publication::conIO(std::ios& io) const {
		if (&io == &std::cout || &io == &std::cin) {
			return true;
		}
		return false;
	}

	// Write the publication information to the ostream
	std::ostream& Publication::write(std::ostream& os) const {
		// Check if the output stream is connected to the console (cin or cout)
		if (conIO(os)) {
			// Output the publication information in a specific format for console display
			char temp_title[SDDS_TITLE_WIDTH + 1] = {0}; // Temporary title string to hold the truncated title
			strncpy(temp_title, m_title, SDDS_TITLE_WIDTH); // Copy the title to the temporary string

			os << "| " << m_shelfId << " | " << std::setw(30) << std::left << std::setfill('.') << temp_title << " | ";
			if (m_membership == 0) {
				os << " N/A ";
			}
			else {
				os << m_membership;
			}

			os << " | " << m_date << " |";
		}
		else {
			// Output the publication information in a specific format for file output
			os << type() << "\t" << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			if (m_membership == 0) {
				os << " N/A ";
			}
			else {
				os << m_membership;
			}
			os << "\t" << m_date;
		}

		return os;
	}

	// Read the publication information from the istream
	std::istream& Publication::read(std::istream& istr) {
		char temp_title[256]{};
		char temp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int temp_libRef = -1;
		int temp_membership = 0;
		Date temp_date;

		// Release memory for the existing title before reading new data
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}

		// Reset the object to default values before reading new data
		setToDefault();

		// Check if the input stream is connected to the console (cin) or a file
		if (conIO(istr)) {
			std::cout << "Shelf No: ";
			istr.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1);

			// Validate the shelf ID length
			if (strlen(temp_shelfId) != SDDS_SHELF_ID_LEN)
				istr.setstate(std::ios::failbit);

			std::cout << "Title: ";
			istr.getline(temp_title, 256);

			std::cout << "Date: ";
			istr >> temp_date;
		}
		else {
			// Read publication information from a file
			istr >> temp_libRef;
			istr.ignore();
			istr.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(temp_title, 256, '\t');
			istr >> temp_membership;
			istr.ignore();
			istr >> temp_date;
		}

		// Validate the read date
		if (!temp_date) {
			istr.setstate(std::ios::failbit);
		}

		// If the read was successful, update the object's data
		if (!istr.fail()) {
			m_title = new char[strlen(temp_title) + 1];
			strcpy(m_title, temp_title);
			strcpy(m_shelfId, temp_shelfId);
			m_date = temp_date;
			m_libRef = temp_libRef;
			m_membership = temp_membership;
		}

		return istr;
	}

	// Conversion operator to bool to check if the object is valid
	Publication::operator bool() const {
		if (m_title != nullptr && m_shelfId[0] != '\0') {
			return true; // The object is valid if title is not null and shelfId is not empty
		}
		return false; // Otherwise, the object is invalid
	}
}
