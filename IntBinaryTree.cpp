// Implementation file for the StringBinaryTree class
#include "IntBinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.
void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

// insertNode creates a new node to hold "record" as its value,
// and passes it to the insert function.                  
void StringBinaryTree::insertNode(string record) {
   TreeNode *newNode;      // Pointer to a new node.

   // Create a new node and store record in it.
   newNode = new TreeNode;
   newNode->value = record;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
// searchNode determines if a value is present in  
// the tree. If so, the function returns true.     
// Otherwise, it returns false.                    
bool StringBinaryTree::searchNode(string record) {
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == record)
         return true;
      else if (record < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

// remove calls deleteNode to delete the      
// node whose value member is the same as record.
void StringBinaryTree::remove(string record) {
   deleteNode(record, root);
}

// deleteNode deletes the node whose value 
// member is the same as record.              
void StringBinaryTree::deleteNode(string record, TreeNode *&nodePtr) {
   if (record < nodePtr->value)
      deleteNode(record, nodePtr->left);
   else if (record > nodePtr->value)
      deleteNode(record, nodePtr->right);
   else
      makeDeletion(nodePtr);
}

// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

// The displayPreOrder member function displays the values      
// in the subtree pointed to by nodePtr, via preorder traversal.
void StringBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

// The displayPostOrder member function displays the values     
// in the subtree pointed to by nodePtr, via postorder traversal.
void StringBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

// *** adding a new function to modify records ***
// bool StringBinaryTree::modify(string record, string modifiedRecord) function header
// DESCRIPTION: this function will allow the user to modify a record within the BST
// - I am using the pre-existing "remove" and "insertNode" functions to implement this new function, so that the BST retains its ordered structure
// - in order for the BST to retain its ordered structure, the pre-existing record has to first be removed and then the modified/new record has to be inserted after removal
// - BST's do not retain their order automatically; it is up to us to write code that will ensure that the BST will remain ordered, no matter what operations are performed
// - note - this function's modification process allows a record that already exists in the BST (a duplicate) to be inserted again, if the user wishes
// ARGUMENTS: string record, which is the record we want to modify/remove
// - string modifiedRecord, which is the record we want to insert/add after removing the pre-existing record
// RETURNS: true or false, since this is a bool function
// - true means that the record was found in the BST and modification was performed
// - false means that the record was not found in the BST, so modification could not be performed
bool StringBinaryTree::modify(string record, string modifiedRecord)
{
   // call the searchNode() function to check if the record we want to modify exists within the BST before proceeding
   if (!searchNode(record)) // if the record was not found within the BST
   {
      cout << record << " was not found in the BST. Modification cannot be performed." << endl;
      return false; // modification not performed
   }

   remove(record); // remove() function call, to remove the pre-existing record
   insertNode(modifiedRecord); // insertNode() function call, to insert/add the modified record into the correct position in the BST
   return true; // modification performed
}