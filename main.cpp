#include "CoursePlanner.hpp"
#include <cctype>        // Included for std::toupper
#include <iostream>      // Included for std::cout and std::cin
#include <limits>        // Included for std::numeric_limits
#include <string>        // Included for std::string

int main() {
    CoursePlanner planner;   // Create a CoursePlanner object to manage courses

    bool exit = false;       // Flag to control the loop and exit the program

    while (!exit) {          // Continue until the exit flag is set to true

        // Display the menu to the user
        std::cout << "Welcome to the course planner.\n";
        std::cout << "1. Load Data Structure.\n";
        std::cout << "2. Print Course List.\n";
        std::cout << "3. Print Course.\n";
        std::cout << "9. Exit\n";
        std::cout << "What would you like to do? ";

        int choice;           // Variable to store user's menu choice
        std::cin >> choice;
        
        // Clear the input buffer to prevent unwanted behavior
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                // Prompt the user to enter the filename to load
                std::cout << "Enter the filename: ";
                std::string filename;  // Store the filename
                std::cin >> filename;
                planner.loadData(filename);  // Load course data from the provided filename
                break;
            }
            case 2: {
                std::cout << "Here is a sample schedule:\n";
                planner.printCourseList();   // Print the list of all courses
                break;
            }
            case 3: {
                std::cout << "What course do you want to know about? ";
                std::string courseNumber;   // Variable to store the course number provided by user
                std::cin >> courseNumber;
                
                // Convert the provided courseNumber to uppercase to maintain consistency
                for (char &ch : courseNumber) {
                    ch = std::toupper(ch);
                }
                planner.printCourse(courseNumber);  // Print details of the specific course
                break;
            }
            case 9: {
                exit = true;   // Set the exit flag to true to exit the program
                std::cout << "Thank you for using the course planner!\n";
                break;
            }
            default: { 
                // Inform the user that they provided an invalid choice
                std::cout << choice << " is not a valid option.\n";
                break;
            }
        }
    }

    return 0;  // Indicate successful completion of the program
}
