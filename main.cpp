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
    string record; // to hold a record from the input file
    int userChoiceMenuNum; // to hold the user's choice of the menu option # they would like to select
    string oldRecord; // to hold the user's input for the pre-existing record they want to modify
    string userChoiceRecord; // to hold the user's input of a record

    return 0;
}