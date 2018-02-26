#include <iostream>
#include <ctime>

using namespace std;

//Create a container for our list data
struct node {
	int data;
	node* next;
};

/**
* Class: intLinkedList
* Purpose:
*     Implements a singly linked list that holds integers.
* Methods:
*     void  frontSert(int x)
*     node* find(int key)
*     node* remove(int key)
*     void  print()
*/
class intLinkedList {
private:
	node* Head;
public:
	intLinkedList() {
		Head = NULL;
	}
	void frontSert(int x) {
		//empty list case
		if (!Head) {
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		else {//not empty list
			node* T = new node;
			T->data = x;
			T->next = Head;
			Head = T;
		}
	}

	node* Find(int key) {
		node* temp = Head;
		while (temp) {
			if (temp->data == key) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void orderedSert(int key) { //this will edit the linked list and put it in ascending order
		if (!Head) {
			Head = new node;
			Head->data = key;
			Head->next = NULL;
		}
		else {//not empty list
			node* T = new node;
			T->data = key;
			T->next = NULL;
			node* temp = Head;
			node* prev = Head; //this will keep track of the node previous to temp.
			while (temp) {
				if (T->data <= temp->data) { //if it is bigger tha the first node
					if (temp == Head) {
						T->next = Head;
						Head = T;
						return;
					}
					else { //if the node is bigger than a node but not as big as another node
						prev->next = T;
						T->next = temp;
						return;
					}

				}
				if (temp->next == NULL) {//if the node if bigger than all the other nodes.
					temp->next = T;
					return;
				}
				if (temp != Head)
					prev = temp;
				temp = temp->next;
			}
		}
	}
	
	void Remove(int key){
		node* result = Find(key);
		if (result) {
			node* temp = Head;
			while (temp->next != result) {
				temp = temp->next;
			}
			temp->next = result->next;
		}
	}

	void print() {
		node* p = Head;
		while (p) {
			cout << p->data << endl;
			p = p->next;
		}
	}
};

int main() {
	// seed random number generator
	srand(2);

	// ummmm
	cout << "Hello World!\n";

	// declare instance of intLinkedList turning
	// a class definition into an "object"
	intLinkedList mylist;

	//Load 10 random ints into our list
	for (int i = 0; i<10; i++) {
		int h = rand() % 100;
		cout << h << endl;
		mylist.orderedSert(h);
		cout << endl;
		mylist.print();
		cout << endl; 
	}

	//print the list
	mylist.print();
	system("pause");
}
