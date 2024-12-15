/***********************************************************************
// Intro. to Object Oriented Programming
// Milestone 5 stage 6
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "LibApp.h"
#include "Date.h"

void runLibApp(const char* filename) {
   char ch{};
   sdds::LibApp theApp(filename);
   theApp.run();
   std::ifstream file(filename);
   while (file) {
      if (file.get(ch)) std::cout << ch;
   }
}
int main() {
   sdds::sdds_day = 10;
   sdds::sdds_mon = 8;
   sdds::sdds_year = 2023;
   sdds::sdds_test = true;
   runLibApp("LibRecs.txt");
   return 0;
}