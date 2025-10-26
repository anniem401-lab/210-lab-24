// COMSC-210 | Lab 24 | Annie Morales
// IDE used: Visual Studio Code

// This is a copy from lab 23, which will be converted from
// std::list into std::set.

#include <iostream>
#include <fstream> // For file operations
#include <iomanip>
#include <set> // To use std::set
#include "Goat.h" // A complete class for Goat objects
#include <ctime>
#include <cstdlib>
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

// Function prototypes: coverted from std::list to std::set.
int select_goat(set<Goat> trip); // Allows the user to select a goat from list.
void delete_goat(set<Goat> &trip); // Deletes a goat on trip.
void add_goat(set<Goat> &trip, string [], string []); // Adds a goat on trip.
void display_trip(set<Goat> trip); // Displays the goats on trip.
int main_menu(); // Main menu function that loops in main.

int main() {
    srand(time(0)); // For random number generation
    bool again;

    // Reads & populates arrays for names and colors
    ifstream fin("names(1).txt"); // Opens names(1).txt
    if (!fin) throw "I/O Error"; // Error handling
    string names[SZ_NAMES]; // String array of 200 names
    int i = 0;
    while (fin >> names[i++]);
    fin.close(); // Closes out of names(1).txt

    ifstream fin1("colors.txt"); // Opens colors.txt
    if (!fin1) throw "I/O Error"; // Error handling
    string colors[SZ_COLORS]; // String array of 25 colors
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close(); // Closes out of colors.txt

    // Default construction
    set<Goat> trip; // Initialized std::set of goats on the trip

    // Task two
    // Write a GM3K1 engine that loops on this menu.
    // Write a main_menu() function that outputs this and then obtains,
    // validates, and returns the user's choice.
    while (true){ // Loop of the menu
        int choice = main_menu();

        switch(choice){
            case 1: cout << "You chose to add a goat." << endl; add_goat(trip, names, colors);
                    break;
            case 2: cout << "You chose to delete a goat." << endl; delete_goat(trip);
                    break;
            case 3: cout << "You chose to list goats." << endl; display_trip(trip);
                    break;
            case 4: cout << "You have chosen to exit the program, goodbye!" << endl << endl;
                    return 0;      
        }
        // return 1; // Ends program to break infinite loop: Temporary
    }

    return 0;
}

// main_menu outputs a menu allowing the user to choose from four options.
// arguments: none.
// returns: user choice from number input.
int main_menu(){
    cout << endl << "** GOAT MANAGER 3001 **" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;

    int choice;
    cout << "Choice --> ";
    cin >> choice; // Choice user makes.
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4){ // Validation loop
        cout << "Invalid choice. Please enter 1, 2, 3, or 4: ";
        cin >> choice;
    }
    return choice;
}

// select_goat allows the user to select a goat from the list.
// arguments: list of goats.
// returns: The option user inputs.
int select_goat(set<Goat> trip){ // Changed from list to set.
    int option;
    cout << "Select a goat (Input a number from the index):\n";
    display_trip(trip); // List of goats on the trip.
    cout << "Choice --> ";
    cin >> option; // Option user makes.
    while (option < 1 || option > trip.size()){ // Validation loop.
        cout << "Invalid choice. Please enter a number of a goat on the list: ";
        cin >> option;
    }
    return option;
}

// Task Three
// Write functions to add a goat to the trip, delete a a goat from the trip, and
// display the current trip.
// When adding a goat, randomly select a name and color from main()'s arrays and
// select a random age between 0 and MAX_AGE.
// When asking user to select a certain goat, display a formatted submenu, allowing
// the user to input an interger to reference the correct goat.

// add_goat adds a goat to the list.
// arguments: list of goats, string array of names, string array of colors.
// returns: void
void add_goat(set<Goat>& trip, string names[], string colors[]){ // Changed from list to set.
    // Select random name, color, and age
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = 1 + (rand() % MAX_AGE);

    trip.insert(Goat(name, age, color)); // Change from push_back to insert()

    cout << "Goat added: " << name << " (" << age << ", " << color << ")" << endl;
}

// delete_goat deletes a goat from the list.
// arguments: list of goats.
// returns: void
void delete_goat(set<Goat> &trip){ // Changed from list to set.
    if (trip.empty()){
        cout << "No goats to delete. \n";
        return;
    }
    int index = select_goat(trip);
    auto it = trip.begin();
    advance (it, index - 1);
    trip.erase(it);
}

// display_trip outputs a display of the goats on the trip.
// arguments: list of goats.
// returns: void
void display_trip(set<Goat> trip){ // Changed from list to set.
    if (trip.empty()){
        cout << "The list is empty, therefore no goats are on a trip. \n";
        return;
    }

    int i = 1;
    for ( Goat g: trip){ // Displays the list of goats with name, age, color, and an index number
        cout << "[" << i++ << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ") \n";
    }
}