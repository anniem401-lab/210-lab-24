// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

// Task One
// Write three more constuctors for the Goat Class:
// One that has just the name as an argument;
// One with name and age; and the last for all parameters.

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()  { name = ""; age = 0; color = ""; } // Default parameter
    // write three more constructors
    Goat(string n)  {name = n;} // Partial parameter
    Goat(string n, int a)   {name = n; age = a;} // Partial parameter
    Goat(string n, int a, string c) {name = n; age = a; color = c;} // Full parameter

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::set
    // bool operator allows sorting to occur, which uses name from the private member variable.
    // arguments: Goat
    // returns: name after it has been compared with another name.
    bool operator< (const Goat &other) const {
        return name < other.name;
    }
};

#endif