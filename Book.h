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
//Book.h

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

// Including necessary header files.
#include <iostream>
#include "Publication.h"

// Creating a namespace named "sdds" to avoid naming conflicts.
namespace sdds
{
	// Declaration of the Book class, which is a derived class of the Publication class.
	class Book : public Publication
	{
		// Private member variable to store the author's name as a dynamically allocated C-string.
		char* m_authorName;

	public:
		// Default constructor for the Book class.
		Book();

		// Copy constructor for the Book class.
		Book(const Book& src);

		// Assignment operator for the Book class.
		Book& operator=(const Book&);

		// Destructor for the Book class.
		~Book();

		// Function to return the type of the object, in this case, 'B' representing a Book.
		char type() const;

		// Function to write the Book object's information to an output stream.
		std::ostream& write(std::ostream& os) const;

		// Function to read the Book object's information from an input stream.
		std::istream& read(std::istream& istr);

		// Function to set the member_id and reset the date attributes of the Book object.
		void set(int member_id);

		// Conversion operator to check if a Book object is valid (has a valid author name and valid publication data).
		operator bool() const;
	};
}

// End of header guard.
#endif
