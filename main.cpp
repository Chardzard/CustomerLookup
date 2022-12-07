/*
  Parke Lovett
  10/5/2022
  We will take a number from user as input and output the corresponding customers I.D.
*/

#include <fstream>            // std::ifstream
#include <iostream>          // std::cin, std::cout
#include <string>           // std::string

int main() {
  std::string idToFind;     // Using string for id in case has both numbers and
                           // letters, like M47
  std::string dbId;
  std::string dbFirstName;
  std::string dbLastName;
  std::ifstream customerDb;  // Input file stream
  bool found = false;       // Bool variable to choose if I.D. found or not 

  std::cin >> idToFind;    // Take user input to know which I.D. to find
  customerDb.open("resources/CustomerDb.txt");
  if (!customerDb) {      // Open file to read from, check file opened properly
    std::cout << "\nError opening file\n";
    return -2;           // Return error if trouble opening file
  }

  customerDb >> dbId;   // While loop to check each user in file for correct I.D. number
  while (!customerDb.eof()) {
    customerDb >> dbFirstName;
    customerDb >> dbLastName;

    if (idToFind == dbId) { 
      found = true;    // If statement to determine whether I.D. was in file or not
      break;           // Break loop if I.D. is found
    }
    customerDb >> dbId;
  }

  if (found) {        // Output first and last name if I.D. was found
    std::cout << dbFirstName << " " << dbLastName << "\n";
  } else {            // Output not found message if I.D. was not located
    std::cout << "Not found";
  }

  customerDb.close(); // Close file

  return 0;           // Return 0 = successful program run
}
