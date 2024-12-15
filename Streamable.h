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
//Streamable.h

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

#include <iostream>

namespace sdds {

	class Streamable {
	public:
		// pure virtual functions

		//Function that overrides this function will write into an ostream object
		virtual std::ostream& write(std::ostream& os = std::cout)const = 0;

		//Function that overrides this function will read from an istream object
		virtual std::istream& read(std::istream& is = std::cin) = 0;

		// bool operator overload: checks and returns true if the object is in a valid state
		virtual operator bool() const = 0;

		// virtual destructor
		virtual ~Streamable();

		// determines if the incoming IO object is a console IO object 
		virtual bool conIO(std::ios& io) const = 0;

	};

	// helper operator << and >> prototypes for ostream and istream 
	std::ostream& operator<<(std::ostream& os, const Streamable& src);
	std::istream& operator>>(std::istream& is, Streamable& src);

} // end of namespace sdds

#endif