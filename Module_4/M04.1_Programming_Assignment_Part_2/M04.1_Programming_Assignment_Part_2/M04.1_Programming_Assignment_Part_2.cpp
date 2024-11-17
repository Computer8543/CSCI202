/* Program Name: M04.1_Programming_Assignment_Part_2.cpp
*  Author: Kyle Ingersoll 
*  Date last updated 11/17/2024
*  Purpose: To create a program to store pairs of each state and its capital in a map. The program prompts the user to enter a state and displays the capital for the state.
*/

#include <iostream>
#include <string>
#include <map>

// custom comparator to make map case insensitive copied from StackOverflow
// link: https://stackoverflow.com/questions/19102195/how-to-make-stlmap-key-case-insensitive
// note: since this is a struct, not a class, I technically don't have to make a UML Class Diagram and a Use Case Diagram for this
struct comparator {
    bool operator() (const std::string& lhs, const std::string& rhs) const {
        return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

// all 50 states in the United States and their capitals in a case insensitive map for use in the main program
static const std::map<std::string, std::string, comparator> stateAndCapitalMap{
    {"Alabama", "Montgomery"}, {"Alaska", "Juneau"}, {"Arizona", "Phoenix"},
    {"Arkansas", "Little Rock"}, {"California", "Sacramento"}, {"Colorado", "Denver"},
    {"Connecticut", "Hartford"}, {"Delaware", "Dover"}, {"Florida", "Tallahassee"},
    {"Georgia", "Atlanta"}, {"Hawaii", "Honolulu"}, {"Idaho", "Boise"},
    {"Illinois", "Springfield"}, {"Indiana", "Indianapolis"}, {"Iowa", "Des Moines"}, 
    {"Kansas", "Topeka"}, {"Kentucky", "Frankfort"}, {"Louisiana", "Baton Rouge"}, 
    {"Maine", "Augusta"}, {"Maryland", "Annapolis"}, {"Massachusetts", "Boston"},
    {"Michigan", "Lansing"}, {"Minnesota", "Saint Paul"}, {"Mississippi", "Jackson"},
    {"Missouri", "Jefferson City"}, {"Montana", "Helena"}, {"Nebraska", "Lincoln"},
    {"Nevada", "Carson City"}, {"New Hampshire", "Concord"}, {"New Jersey", "Trenton"},
    {"New Mexico", "Santa Fe"}, {"New York", "Albany"}, {"North Carolina", "Raleigh"},
    {"North Dakota", "Bismarck"}, {"Ohio", "Columbus"}, {"Oklahoma", "Oklahoma City"},
    {"Oregon", "Salem"}, {"Pennsylvania", "Harrisburg"}, {"Rhode Island", "Providence"},
    {"South Carolina", "Columbia"}, {"South Dakota", "Pierre"}, {"Tennessee", "Nashville"},
    {"Texas", "Austin"}, {"Utah", "Salt Lake City"}, {"Vermont", "Montpelier"},
    {"Virginia", "Richmond"}, {"Washington", "Olympia"}, {"West Virginia", "Charleston"},
    {"Wisconsin", "Madison"}, {"Wyoming", "Cheyenne"}
};

int main()
{
    // initialize variable
    std::string userInputState;

    // tell user purpose of program 
    std::cout << "This program allows you to enter in the full name of a state in the United States and get the state capital in response as many times as desired." << std::endl;

    // prompt user to enter in the state
    std::cout << "Enter in the full name (not the abbreviation) of the state (enter -1 to exit out of the program): ";
    std::cin >> userInputState;
    std::cout << std::endl;

    // create while loop to allow user to input states and get their capitols multiple times
    while (userInputState != "-1") {
        // if the user input corresponds to a full name of a state in the United States, give the user the state capitol 
        // and then reprompt them to either enter in the full name of another state or exit out of the program
        if ((stateAndCapitalMap.find(userInputState) != stateAndCapitalMap.end())) {
            std::cout << "The state capitol is: " << stateAndCapitalMap.at(userInputState) << std::endl;

            // prompt user to enter in the state
            std::cout << "Enter in the full name (not the abbreviation) of the state (enter -1 to exit out of the program): ";
            std::cin >> userInputState;
            std::cout << std::endl;
            continue;
        }
        else {
            // output error message, and then reprompt user to enter in the full name of a state in the United States or exit out of the program
            std::cerr << "What you entered was not a valid full name of a state in the United States. Please try again." << std::endl;

            // prompt user to enter in the state
            std::cout << "Enter in the full name (not the abbreviation) of the state (enter -1 to exit out of the program): ";
            std::cin >> userInputState;
            std::cout << std::endl;
            continue;
        }
    }
    

    // end program normally
    return 0;
}

