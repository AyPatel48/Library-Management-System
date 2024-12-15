/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
    const unsigned int MAX_MENU_ITEMS = 20; // Maximum number of menu items

    class MenuItem {
    private:
        char* content{}; // Pointer to store the content of the menu item

        MenuItem(); // Private default constructor
        MenuItem(const char* itemContent); // Constructor with content parameter
        ~MenuItem(); // Destructor

        MenuItem(const MenuItem& item) = delete; // Deleted copy constructor
        void operator=(const MenuItem& MI) = delete; // Deleted assignment operator

        void setEmpty(); // Helper function to set the content pointer to nullptr

        operator bool() const; // Conversion operator to check if the content is not empty

        operator const char* () const; // Conversion operator to retrieve the content as a C-style string

        std::ostream& display(std::ostream& os = std::cout); // Display the menu item content

        friend class Menu; // Declare the Menu class as a friend

    };

    class Menu {
    private:
        MenuItem title{}; // Menu title
        MenuItem* items[MAX_MENU_ITEMS]{}; // Array of pointers to MenuItem objects
        unsigned int itemCount = 0; // Current number of menu items

    public:
        Menu(); // Default constructor
        Menu(const char* menuTitle); // Constructor with title parameter
        ~Menu(); // Destructor

        Menu(const Menu& M) = delete; // Deleted copy constructor
        void operator=(const Menu& M) = delete; // Deleted assignment operator

        std::ostream& displayMenuTitle(std::ostream& os); // Display the menu title
        std::ostream& displayMenu(std::ostream& os = std::cout); // Display the menu and its items
        operator int(); // Conversion operator to convert itemCount to int
        operator unsigned int(); // Conversion operator to convert itemCount to unsigned int
        operator bool(); // Conversion operator to check if itemCount is greater than 0
        int run(); // Display the menu and get user input
        int operator~(); // Run the menu using the ~ operator
        Menu& operator<<(const char* itemContent); // Add a new menu item to the menu
        const char* operator[](unsigned int index) const; // Access the content of a menu item by index

    };

    std::ostream& operator<<(std::ostream& os, Menu& menu); // Output the menu title

}

#endif
