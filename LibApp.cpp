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
#include "Book.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include <iomanip>
#include <fstream>

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

        std::ifstream file(m_filename);

        char type{};
        int i;

        // Iterating over the file
        for (i = 0; file && i < SDDS_LIBRARY_CAPACITY; i++) {
            // Reading the first character to determine the type of publication
            file >> type;

            // Ignoring the white space character
            file.ignore();

            // Dynamically allocating space for the m_PPA array based on the type of publication
            if (file) {
                if (type == 'P')
                    PPA[i] = new Publication;

                else if (type == 'B')
                    PPA[i] = new Book;

                if (PPA[i]) {
                    // Extracting the object from the file stream
                    file >> *PPA[i];
                    NOLP++;
                    // Setting the LLRN to the reference number of the last publication read
                    LLRN = PPA[i]->getRef();
                }
            }
        }

    }

    // Save function to save data
    void LibApp::save() {
        cout << "Saving Data" << endl;

        ofstream file(m_filename);
        // Iterating over the m_PPA array
        for (int i = 0; i < NOLP; i++) {
            // Inserting the object into the file stream
            if(PPA[i]->getRef() != 0){
                file << *PPA[i] << endl;
            }
        }
        file.close();
    }

    // Search function to search for a publication
    int LibApp::search(int searchType) {
        // cout << "Searching for publication" << endl;
        
        // Add arguments so the search function can be called in three different ways
        // 1. Search All
        // 2. Search Checkout Items
        // 3. Search Available Items

        char pub_title[256]{};
        int type{};
        int i = 0, libRef = 0;

        char type_char{};
        PublicationSelector pubSel("Select one of the following found matches:");
        
        // Asking the user for the type of publication
        type = typeMenu.run();

        if(type == 1){
            type_char = 'B';
        }
        else if(type == 2){
            type_char = 'P';
        }
        
        std::cin.ignore(1000, '\n');
        std::cout << "Publication Title: ";
        std::cin.getline(pub_title, 256);

        if(searchType == 1){
            // Iterating over the m_PPA array
            for(i = 0; i < NOLP; i++){
                // Checking if the publication is available
                if(PPA[i]->operator==(pub_title) && type_char == PPA[i]->type() && PPA[i]->getRef() != 0){
                    // Inserting the object into the publication selector
                    pubSel << PPA[i];
                }
            }
        }
        else if (searchType == 2) {
            for (i = 0; i < NOLP; i++) {
                if (PPA[i]->operator==(pub_title) && PPA[i]->onLoan() && type_char == PPA[i]->type() && PPA[i]->getRef() != 0) {
                    pubSel << PPA[i];
                }
            }
        }
        else if (searchType == 3) {
            for (i = 0; i < NOLP; i++) {
                if (PPA[i]->operator==(pub_title) && !PPA[i]->onLoan() && type_char == PPA[i]->type() && PPA[i]->getRef() != 0) {
                    // Insert object into pubSel object so that we can generate a selector to choose an element from
                    pubSel << PPA[i];
                }
            }
        }

        if (pubSel) {
            pubSel.sort();
            libRef = pubSel.run();

            if (libRef > 0)
            {
                std::cout << *getPub(libRef) << std::endl;
            }
            else {
                std::cout << "Aborted!" << std::endl;
            }
        }
        else {
            std::cout << "No matches found!" << std::endl;
        }

        return libRef;

    }

    // Function to return a publication
    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;
        int libRef = search(2);
        if(libRef > 0){
            if(confirm("Return Publication?")){
                // If the publication is more than 15 days on loan, 
                // a 50 cents per day penalty will be calculated 
                //for the number of days exceeding the 15 days
                int daysOnLoan = Date() - getPub(libRef)->checkoutDate();
                if (daysOnLoan > SDDS_MAX_LOAN_DAYS) {
                    double penalty = (daysOnLoan - SDDS_MAX_LOAN_DAYS) * 0.5;
                    cout << fixed << setprecision(2);
                    std::cout << "Please pay $" << penalty << " penalty for being " 
                        << (daysOnLoan - SDDS_MAX_LOAN_DAYS) << " days late!" << std::endl;
                }

                getPub(libRef)->set(0);
                m_changed = true;
            }
            cout << "Publication returned" << endl;
        }
        cout << endl;
    }

    // Function to add a new publication
    void LibApp::newPublication() {
        bool end = false;
        
        if(NOLP == SDDS_LIBRARY_CAPACITY){
            cout << "Library is at its maximum capacity!" << endl;
            end = true;
        }
        if(!end){
            Publication* pubPointer = nullptr;
            cout << "Adding new publication to the library" << endl;
            int type = typeMenu.run();
            cin.ignore(1000, '\n');

            if(type == 1){
                pubPointer = new Book;
                cin >> *pubPointer;

            }
            else if(type == 2){
                pubPointer = new Publication;
                cin >> *pubPointer;
            }
            else if(type == 0){
                cout << "Aborted!" << endl;
                end = true;
            }

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Aborted!" << endl;
                exit(0);
            }
            else{
                if(!end && confirm("Add this publication to the library?")){
                    if(!*pubPointer){
                        cout << "Failed to add publication!" << endl;
                        delete pubPointer;
                    }
                    else{
                        LLRN++;
                        pubPointer->setRef(LLRN);

                        PPA[NOLP] = pubPointer;
                        NOLP++;
                        m_changed = true;

                        cout << "Publication added" << endl;
                    }
                }
            }
        }
        cout << endl;
    }

    // Function to remove a publication
    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int libRef = search(1); // Search for all publications
        if(libRef){
            if(confirm("Remove this publication from the library?")){
                getPub(libRef)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
        cout << endl;
    }

    // Function to check out a publication
    void LibApp::checkOutPub() {
        
        cout << "Checkout publication from the library" << endl;
        int libRef = search(3); // Search for available publications
        if(libRef > 0){
            if(confirm("Check out publication?")){
                cout << "Enter Membership number: ";
                int memNum = ut.getInteger(10000, 99999, "Invalid membership number, try again: ");
                getPub(libRef)->set(memNum);
                m_changed = true;
                cout << "Publication checked out" << endl;
            }
        }
        cout << endl;
    }

    // Constructor for LibApp class
    LibApp::LibApp(const char* filename) : m_mainMenu("Seneca Library Application"), 
        m_exitMenu("Changes have been made to the data, what would you like to do?"), 
        typeMenu("Choose the type of publication:") {

        if (filename){
            ut.strcpy(m_filename, filename);
        }
        NOLP = 0;
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        typeMenu << "Book" << "Publication";
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

    Publication* LibApp::getPub(int RefNumber) {
        Publication* publication = nullptr;
        for (int i = 0; i < NOLP; i++)
        {
            if (PPA[i]->getRef() == RefNumber) {
                publication = PPA[i];
            }
        }

        return publication;
    }

    LibApp::~LibApp() {
        for (int i = 0; i < NOLP; i++) {
            delete PPA[i];
        }
    }

}
