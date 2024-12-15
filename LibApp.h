/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
Version 1.0

Author        : Ayushkumar Patel
Student Number: 114473226
Email         : apatel574@myseneca.ca
Section:        NAA
Date          : 15/07/2023

Revision History
-----------------------------------------------------------
Date        Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
#include "Publication.h"

namespace sdds {
   class LibApp {

      char m_filename[256]; // Stores the name of the file to be read from.
      Publication *PPA[SDDS_LIBRARY_CAPACITY]; // Array of pointers to Publication objects.
      int NOLP; // Number of publications in the array.
      int LLRN; // The last library reference number used.
      bool m_changed; // A flag to keep track of changes made to the app data and save it before exiting.
      Menu m_mainMenu; // The main menu of the app.
      Menu m_exitMenu; // The exit menu of the app.
      Menu typeMenu; // The type menu of the app.

      bool confirm(const char* message); // Function to confirm the user's choice with the provided message.
      void load(); // Prints "Loading Data" followed by a newline character.
      void save(); // Prints "Saving Data" followed by a newline character.
      int search(int searchType); // Performs a search for a publication based on the given searchType and returns the result.

      void returnPub(); // Calls the search() method, prints "Returning publication" and "Publication returned", and sets m_changed to true.

      void newPublication(); // Prints "Adding a new publication" and confirms the user's choice.
      void removePublication(); // Prints "Removing a publication" and confirms the user's choice.
      void checkOutPub(); // Prints "Checking out a publication" and confirms the user's choice.

    public:

      LibApp(const char* filename); // Constructor that takes the filename as input.
      void run(); // Runs the app, allowing the user to interact with the library application.
      Publication* getPub(int RefNumber); // Returns a pointer to the publication with the given reference number.
      ~LibApp(); // Destructor for the LibApp class.
   };
}

#endif // !SDDS_LIBAPP_H



