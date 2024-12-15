/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0

Author        : Ayushkumar Patel
Student Number: 114473226
Email         : apatel574@myseneca.ca
Section:        NAA

Revision History
-----------------------------------------------------------
Date        Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include "Utils.h"

using namespace std;

namespace sdds {

    MenuItem::MenuItem() {
        setEmpty();
    }

    MenuItem::MenuItem(const char* itemContent) {
        if (itemContent != nullptr && itemContent[0] != '\0') {
            content = new char[strlen(itemContent) + 1]; // Allocate memory for the content
            strcpy(content, itemContent); // Copy the content to the allocated memory
        }
        else {
            setEmpty();
        }
    }

    MenuItem::~MenuItem() {
        delete[] content; // Deallocate memory for the content
    }

    void MenuItem::setEmpty() {
        content = nullptr; // Set the content pointer to nullptr
    }

    MenuItem::operator bool() const {
        return (content && content[0]); // Check if the content is not null and the first character is not null
    };

    MenuItem::operator const char* () const {
        return content; // Return the content as a C-style string
    }

    std::ostream& MenuItem::display(std::ostream& os) {
        if (*this) { // Check if the content is not empty
            os << content; // Output the content
        }

        return os;
    }

    Menu::Menu() {
        itemCount = 0; // Initialize the item count to 0
    };

    Menu::Menu(const char* menuTitle) : title(menuTitle) {};

    Menu::~Menu() {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete items[i]; // Deallocate memory for each item
        }
    };

    std::ostream& Menu::displayMenuTitle(std::ostream& os) {
        if (title) {
            title.display(); // Output the title
        }

        return os;
    }

    std::ostream& Menu::displayMenu(std::ostream& os) {
        if (title)
        {
            title.display(); // Output the title
            os << std::endl;
        }

        unsigned int i;
        for (i = 0; i < itemCount; i++)
        {
            os.width(2);
            os.setf(std::ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(std::ios::right);
            items[i]->display(os); // Output each item
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";

        return os;
    }

    Menu::operator int() {
        return itemCount; // Convert the item count to an int
    }

    Menu::operator unsigned int() {
        return itemCount; // Convert the item count to an unsigned int
    }

    Menu::operator bool() {
        return (itemCount > 0); // Check if the item count is greater than 0
    }

    std::ostream& operator<<(std::ostream& os, Menu& menu) {
        return (menu.displayMenuTitle(os)); // Output the menu title
    }

    int Menu::run() {
        int userInput;
        displayMenu();
        userInput = getInteger(0, itemCount); // Get user input within the range of 0 to item count
        return userInput;
    }

    int Menu::operator~() {
        return run(); // Call the run function when the menu is used with the ~ operator
    }

    Menu& Menu::operator<<(const char* itemContent) {
        if (itemCount < MAX_MENU_ITEMS)
        {
            MenuItem* newMenuItem = new MenuItem(itemContent); // Create a new menu item
            items[itemCount] = newMenuItem; // Add the menu item to the items array
            itemCount++;
        }

        return *this;
    }

    const char* Menu::operator[](unsigned int index) const {
        if (index > itemCount)
        {
            return items[index %= itemCount]->content; // Return the content of the item at the adjusted index
        }
        else
        {
            return items[index]->content; // Return the content of the item at the given index
        }
    }

}
