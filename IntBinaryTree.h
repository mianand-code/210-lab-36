// Specification file for the StringBinaryTree class
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include <string> 
using namespace std;

// The StringBinaryTree class manages a binary tree of strings.
class StringBinaryTree {
private:
   // TreeNode is a private structure for StringBinaryTree nodes.
   struct TreeNode {
      string value;      // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   // root points to the topmost node of the tree.
   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(string, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   // Constructor initializes the root to nullptr, indicating an empty tree.
   StringBinaryTree()     { root = nullptr; }

   // Destructor deallocates all nodes in the tree.
   ~StringBinaryTree()    { destroySubTree(root); }

   // Public interface for inserting, searching, removing, and modifying nodes.
   void insertNode(string);
   bool searchNode(string);
   void remove(string);
   bool modify(string, string);

   // Public wrappers for tree traversal functions.
   void displayInOrder() const     {  displayInOrder(root); }
   void displayPreOrder() const    {  displayPreOrder(root); }
   void displayPostOrder() const   {  displayPostOrder(root); }
};

#endif // INTBINARYTREE_H
