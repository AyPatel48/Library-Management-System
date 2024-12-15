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

namespace sdds {
   class LibApp {

       bool m_changed; //flag to keep track of the changes made to the app data and save it before exiting
       Menu m_mainMenu; //main menu of the app
       Menu m_exitMenu; //exit menu of the app

       bool confirm(const char* message); //confirm the user's choice
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication(); //prints "Adding a new publication"<NEWLINE> and confirms the user's choice
       void removePublication(); //prints "Removing a publication"<NEWLINE> and confirms the user's choice
       void checkOutPub(); //prints "Checking out a publication"<NEWLINE> and confirms the user's choice
       
     public:

       LibApp(); //default constructor
       void run(); //runs the app

   };
}
#endif // !SDDS_LIBAPP_H



