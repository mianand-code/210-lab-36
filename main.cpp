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
        recordsTree.insertNode(record);
    }

    return 0;
}