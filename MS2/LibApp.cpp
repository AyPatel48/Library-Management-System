/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
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

#include "LibApp.h"
using namespace std;
namespace sdds {

    // Function to confirm user's choice
    bool LibApp::confirm(const char* message) {
        bool confirmed = false;
        Menu confirmMenu(message);
        confirmMenu << "Yes";

        int response = confirmMenu.run();
        if (response == 1) {
            confirmed = true;
        }

        return confirmed;
    }

    // Load function to load data
    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    // Save function to save data
    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    // Search function to search for a publication
    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    // Function to return a publication
    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        cout << endl;
        m_changed = true;
    }

    // Function to add a new publication
    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        bool confirmed = confirm("Add this publication to library?");
        if (confirmed == true) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        cout << endl;
    }

    // Function to remove a publication
    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        bool confirmed = confirm("Remove this publication from the library?");
        if (confirmed == true) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    // Function to check out a publication
    void LibApp::checkOutPub() {
        search();
        bool confirmed = confirm("Check out publication?");
        if (confirmed == true) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    // Constructor for LibApp class
    LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        load();
    }

    // Main run function to control the flow of the application
    void LibApp::run() {
        int userInputMenu, userInputExit;

        do {
            userInputMenu = m_mainMenu.run();

            // Handle user input based on the main menu selection
            switch (userInputMenu) {
            case 0:
                if (m_changed == true) {
                    userInputExit = m_exitMenu.run();

                    // Handle user input based on the exit menu selection
                    switch (userInputExit) {
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            m_changed = false;
                        }
                        break;
                    case 1:
                        save();
                        break;
                    case 2:
                        userInputMenu = 1;
                        break;
                    }
                }
                cout << endl;
                break;
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            }
        } while (userInputMenu != 0);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}
