#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.h"

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



int main()
{

	BSTree B;

	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");

	B.GraphVizOut("after.txt");
	// Continously delete root node, until tree is empty.
	while (B.top()) {
		cout << "removing: " << B.top() << endl;
		B.deleteNode(B.top());
	}
	system("pause");

	return 0;
}
