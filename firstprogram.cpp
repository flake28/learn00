#include <stdio.h>
#include <iostream>
#include <cmath> // Include cmath for mathematical functions
//Header files provide declarations for functions and macros
//macros are fragments of code which have been given a name


using namespace std; // Use the standard namespace
//namespace std allows us to use standard library features without prefixing them with std::
//namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it.
//without using namespace std, we would have to write std::cout, std::cin, std::string, etc.
//so namespace basically helps to avoid name conflicts in larger projects
//example two libraries having a function with the same name
//using namespace std is generally fine for small programs, but in larger projects, it's better to avoid it to prevent potential name conflicts.
//so in larger projects, it's better to use std:: prefix explicitly

void greet(string name, int age) // Function to print a greeting
{
    cout << "Hello " << name << "." << "You're " << age << "y/o.\n"; // Output a greeting to the console
}
// variables inside the funtion defined above are called parameters
// when you call the function, you provide arguments
// the value user gives is called an argument
// the argument is passed to the parameter when the function is called
// the argument is stored in the parameter variable as long as the function is running

double cube(double num); // Function prototype (declaration)
// The text inside brackets is called the parameter list and it specifies the types and names of parameters the function takes.

int main() // Main function - execution starts here
{
    // string name;
    // int age;                      // Declare the variable 'name' of type string
    // cout << "Whats ur name?: ";   // Output a prompt to the console
    // getline(cin, name);           // Read a line of text from the user, including spaces
    // cout << "How old are you?: "; // Output a prompt to the console
    // cin >> age;                   // Read the input from the user
    // greet(name, age);             // Call the greet function to print the greeting

    // double num;                         // Declare a variable to hold the number
    // cout << "Enter a number to cube: "; // Prompt the user for a number
    // cin >> num;                         // Read the number from the user
    // cout << "The cube of " << num << " is " << cube(num) << "\n";
    // // Call the cube function and output the result

    // cout << x << endl;     // Output the string to the console
    // cout << 5 * 5 << endl; // Output the result of 5 squared
    // // In C++, ** is not an exponentiation operator.
    // // To calculate powers, use the pow() function from <cmath>.
    // cout << pow(5, 2) << endl; // Outputs 25 (5 squared)
    // int y = 10;
    // int z = 20;
    // cout << y * z << endl;          // Output the sum of y and z
    // cout << ceil(2.4) << endl;      // Output the ceiling of 2.4
    // cout << floor(2.4) << endl;     // Output the floor of 2.4
    // cout << round(2.4) << endl;     // Output the rounded value of 2.4
    // cout << round(2.5) << endl;     // Output the rounded value of 2.5
    // cout << fmax(2.4, 3.5) << endl; // Output the maximum of 2.4 and 3.5
    // To output max of multiple numbers, use nested fmax calls
    // cout << fmax(2.4, fmax(3.5, 1.2)) << endl; // Output the maximum of 2.4, 3.5, and 1.2
    // cout << fmin(2.4, 3.5) << endl; // Output the minimum of 2.4 and 3.
    // select text use 'cmd + /' to comment/uncomment lines in VS Code

    // int age;
    // string name;
    // cout << "Enter your name: ";
    // getline(cin, name); // Read a line of text from the user, including spaces
    // // getline is used to read a full line of input, allowing for spaces in the name
    // cout << "Enter your age: ";
    // cin >> age; // Read the input from the user
    // cout << "You are " << name << " and you are " << age << " years old." << endl;

    // arrays start
    // int nums[8] = {1, 2, 3, 4, 5}; // Declare and initialize an array with 8 elements
    // // if I keep just nums[] it will give an error, I need to specify the size of the array
    // nums[7] = 12;            // there are 8 elements, but indexing starts from 0, so nums[7] is the 8th element
    // cout << nums[7] << endl; // Output the 8th element of the array
    // // all unassigned elements in the array will be initialized to 0
    // return 0; // Return 0 to indicate successful execution

    // boolean
    // elif is not used in C++, use 'else if' instead
    //  the or operator is '||' in C++
    //  the and operator is '&&' in C++
    //  the not operator is '!' in C++
    bool isMale = true; // Declare a boolean variable and initialize it to true
    // use lowercase 'true' and 'false' in C++
    bool isTall = false; // Declare a boolean variable and initialize it to false
    if (isMale && isTall)
    {                                    // Check if the person is male and tall
        cout << "You are a tall man.\n"; // Output if both conditions are true
    }
    else if (isMale && !isTall)
    {                                     // Check if the person is male and short
        cout << "You are a short man.\n"; // Output if the person is a short man
    }
    else if (!isMale && isTall)
    { // Check if the person is a female and tall..
        cout << "You are a tall woman.\n";
    }
    else
    { // If none of the above conditions are true
        cout << "You are a short woman.\n";
    }

    return 0;
}
//return 0 indicates that the program ended successfully, in literal terms it means "no error"

double cube(double num)
{                           // Function definition - actual implementation of the function
    return num * num * num; 
} // No semicolon here because it's a function definition (not a declaration)

//Template is a feature in C++ that allows you to write generic and reusable code.
//Templates can be used with functions and classes to create code that works with any data type.
//Example of a function template
// template <typename T> // Declare a template with a placeholder type T
// T getMax(T a, T b) // Function that returns the maximum of two values
// {
//     return (a > b) ? a : b; // Return the greater of a
// }

//Functional Overloading
//Function overloading is a feature in C++ that allows you to have multiple functions with the
// same name but different parameter lists (different types or number of parameters).
//The compiler determines which function to call based on the arguments passed to the function.
//Example of function overloading           
// int add(int a, int b) // Function to add two integers
// {
//     return a + b;        
// }
// double add(double a, double b) // Function to add two doubles        
// {
//     return a + b;
// }

// We can use different custom header files in our projects to organize code better
// Example of including a custom header file
// #include "myheader.h" // Include a custom header file named myheader.h
// In myheader.h, we can declare functions, classes, or variables that we want to use in our main program
// This helps to keep the code modular and easier to maintain
// Also the definitions of the functions declared in the header file can be placed in a separate .cpp file
// Example: myheader.cpp, the definitions of functions declared in myheader.h can be placed here

//Default Arguments allow you to specify default values for function parameters
//Example of default arguments
// void greet(string name, string message = "Hello") // Function with a default argument
// {    
//     cout << message << ", " << name << "!\n"; // Output the greeting message
// }    
// If the caller does not provide a value for 'message', it will default to "Hello"
// If the user passes arguments, they must be in the same order as the parameters
// Variables with default arguments must be at the end of the parameter list
// Example: void func(int a, int b = 10, int c = 20) is valid
// Example: void func(int a = 10, int b, int c = 20) is invalid

//Vector are dynamic arrays that can grow and shrink in size
//Vectors are part of the C++ Standard Library and are defined in the <vector> header
//Example of using vectors
// #include <vector> // Include the vector header
// vector<int> numbers; // Declare a vector of integers
// numbers.push_back(10); // Add an element to the end of the vector
// numbers.push_back(20); // Add another element
// cout << numbers[0] << endl; // Output the first element of the vector
// cout << numbers.size() << endl; // Output the size of the vector
// Vectors provide many useful functions like push_back, pop_back, size, clear, etc
//Vectors can have different data types like vector<string>, vector<double>, etc 
// A single vector can also hold multiple data types using structures or classes
// Example of a vector of structures
// struct Person // Define a structure to hold person data
// {
//     string name; // Name of the person   
//     int age;     // Age of the person
// };
// vector<Person> people; // Declare a vector of Person structures
// Person p1; // Create a Person object
// p1.name = "Alice"; // Set the name
// p1.age = 30;       // Set the age
// people.push_back(p1); // Add the Person object to the vector






































// MISC NOTES 

//best way to revice C++ is to build small projects
//best way to not forget syntax is to use it regularly
//other way is to use flashcards for syntax

//to make c++ apps run as applications on macOS, use a macOS specific IDE like Xcode or CLion
//if using vscode on macOS, you can create a .command file to run your compiled C++ program and to make it executable using 'chmod +x filename.command' in terminal
//to make a GUI application in C++, you can use libraries like Qt or wxWidgets
// to make a terminal application in C++, you can use libraries like ncurses or just standard input/output streams
// to use APIs and play video in terminal applications, you can use libraries like libcurl for APIs and ASCII art libraries for video playback
//if you want mp4 playback and not aasci art, you will need to use a GUI library like Qt or wxWidgets whilst still having a terminal interface
//C++ alone does not have built-in support for GUI or multimedia, so you will need to rely on external libraries for these functionalities.

// header vs library files
// header files provide declarations for functions and macros
// library files provide the actual implementation of functions and classes

//switch statements 
//switch statements are used to perform different actions based on different conditions
//switch statements can be used instead of multiple if-else statements when you have a single variable
//switch statements can only be used with integral types (int, char, etc) and enum
//switch statements cannot be used with floating point types (float, double, etc) or strings
//syntax of switch statement
// basically difference between switch and if-else is that switch is used for single variable with multiple values, whereas if-else can be used for multiple variables and complex conditions
// so its better to just use if-else statements in most cases unless you have a single variable with multiple discrete values to check against






