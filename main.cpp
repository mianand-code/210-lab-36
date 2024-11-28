// COMSC-210 | Lab 36 | Mira Anand
// Module 14, Lesson: Binary Trees & Binary Search Trees, Assignment: Records BST
// IDE used: Visual Studio Code for Mac

// Implementation of menu-driven functionality + creation/population of the BST

#include <fstream> // needed for file operations
#include "IntBinaryTree.h" // including the specification file for the StringBinaryTree class
#include <iostream>
#include <string>
using namespace std;

// declaration and initialization of a global const string variable
string INPUT_FILE_NAME = "codes.txt"; // to hold the name of the input file, which contains the data that will populate the BST

int main() 
{
    StringBinaryTree recordsTree; // creation of the BST

    // declaration of variables section
    string record; // to hold a record from the input file - will be used to read records from the input file
    int userChoiceMenuNum; // to hold the user's choice of the menu option # they would like to select
    string userChoiceRecord; // to hold the user's input for a record they want to perform actions with - will be used with all menu functionalities
    string oldRecord; // to hold the user's input for the pre-existing record they want to modify - will be used with the modify() function

    ifstream fin(INPUT_FILE_NAME); // creation of an ifstream (input file) object
    
    // population of the BST - to hold records from the "codes.txt" (INPUT_FILE_NAME) file
    if (!fin) // check if there was an error when opening the input file
    {
        cout << "ERROR: Could not open input file. Please make sure the file exists in the correct location & try running the program again." << endl;
        return 1; // exit with an error state
    }

    while (getline(fin, record)) // read all of the records from the input file, until the end of the input file is reached
    {
        recordsTree.insertNode(record); // call the insertNode() function, to insert the records from the input file into the BST
    }

    fin.close(); // close the input file

    // creation of a numbered menu that users can choose from to perform actions with the created BST
    do  // creation of a do-while loop so that the user can continue to select options until they wish to quit
    {
        // output the menu of choices that the user can select from
        cout << "Records BST Menu:" << endl;
        cout << "[1] " << endl;
        cout << "[2] " << endl;
        cout << "[3] " << endl;
        cout << "[4] " << endl;
        cout << "[5] Exit" << endl;
        cout << endl;

        // user input for menu option number they would like to choose
        cout << "Enter your choice: "; 
        cin >> userChoiceMenuNum;

        // creation of a switch statement that handles cases of each numbered option based on userChoiceMenuNum
        switch (userChoiceMenuNum)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;
            
            // menu option #5 means the user wants to exit the program
            case 5:
                cout << "Thank you for using this program. Now exiting..." << endl;
                break;
            
            // user input validation for menu option number (has to be 1-5)
            default:
                cout << "ERROR: Invalid entry. Please enter a valid menu option number (1-5) and try again." << endl << endl;
        }

    } while (userChoiceMenuNum != 5); // userChoice = 5 means user wants to quit program

    return 0;
}