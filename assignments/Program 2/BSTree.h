#include <iostream>
#include <fstream>
#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
//                 
// Title:            Program 2/assigment 4
// Files:            (list of source files)
// Semester:         3013 Advanced Alg Spring 2018
//
// Author:			 Brett Workman
// Email:            brettworkman2014@gmail.com
// Description:
//       Complete the program and make it so that it can preform a 
//		 proper delete function.
/////////////////////////////////////////////////////////////////////////////////

//http://www.webgraphviz.com/


using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};
class BSTree
{
private:
	node *root;
	// suposed to return how many nodes are in the BST
	int count(node *root);
	// ads a new node to the tree.
	void insert(node *&root, node *&temp);
	//this is actually supposed to print out the node and what the address each node is pointing to.
	void print_node(node *n, string label = "");

	/**
	* type = ['predecessor','successor']
	*/

	// searches for the closest successor to the node in the right subtree.
	node *minValueNode(node *root);

	// this is meant to delete a selected node.

	node *deleteNode(node *&root, int key);
	// returns the height of the bst
	int height(node *root);

	/* Print nodes at a given level */
	void printGivenLevel(node *root, int level);
	//************************************************************************
	// Method to help create GraphViz code so the expression tree can
	// be visualized. This method prints out all the unique node id's
	// by traversing the tree.
	// Recivies a node pointer to root and performs a simple recursive
	// tree traversal.
	//************************************************************************
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);

	//************************************************************************
	// This method is partnered with the above method, but on this pass it
	// writes out the actual data from each node.
	// Don't worry about what this method and the above method do, just
	// use the output as your told:)
	//************************************************************************
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);

public:
	BSTree();
	~BSTree();
	int count();
	void insert(int x);
	void deleteNode(int key);
	void minValue();
	int height(int key = -1);
	int top();
	/* Function to line by line print level order traversal a tree*/
	void printLevelOrder();
	//************************************************************************
	// Recieves a filename to place the GraphViz data into.
	// It then calls the above two graphviz methods to create a data file
	// that can be used to visualize your expression tree.
	//************************************************************************
	void GraphVizOut(string filename);
};

