/******************************************************************************
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : NAA
Date	   : 21/07/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
******************************************************************************/
//Streamable.cpp

#include <iostream>
#include "Streamable.h"

namespace sdds {

	// virtual destructor
	Streamable::~Streamable() {};

	// helper operator << and >> prototypes for ostream and istream 
	std::ostream& operator<<(std::ostream& os, const Streamable& src) {
		if (src) {
			src.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& src) {
		return (src.read(is));
	}

} // end of namespace sdds