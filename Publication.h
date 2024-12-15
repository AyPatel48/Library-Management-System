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
//Publication.h

#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {

	class Publication : public Streamable {
		private:
			char* m_title;
			char m_shelfId[SDDS_SHELF_ID_LEN + 1];
			int m_membership;
			int m_libRef;
			Date m_date;

		public:

		// Constructors and Destructor
			Publication();
			~Publication();

		//Rule of Three
			Publication(const Publication& publication);
			Publication& operator=(const Publication& publication);

		// Modifiers
			
			// Sets the object to a safe empty state
			void setToDefault();

			// Sets the membership attribute to either zero or a five-digit integer.
			virtual void set(int member_id);
			
			// Sets the **libRef** attribute value
			void setRef(int value);

			// Sets the date to the current date of the system.
			void resetDate();

		// Queries
		
			//Returns the character 'P' to identify this object as a "Publication object"
			virtual char type()const;

			//Returns true is the publication is checkout (membership is non-zero)
			bool onLoan()const;

			//Returns the date attribute
			Date checkoutDate()const;
			
			//Returns true if the argument title appears anywhere in the title of the 
			//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
			bool operator==(const char* title)const;
			
			//Returns the title attribute
			operator const char* ()const;

			//Returns the libRef attirbute. 
			int getRef()const;

			// Returns true if the address of the io object is the same as the 
			// address of either the cin object or the cout object.
			bool conIO(std::ios& io) const;

			// Writes the title, year, shelfId and membership to the console
			std::ostream& write(std::ostream& os) const;

			//Reads the title, year, shelfId and membership from the console
			std::istream& read(std::istream& istr);

			//Returns true if the publication is in a safe empty state
			operator bool() const;
	};

}


#endif