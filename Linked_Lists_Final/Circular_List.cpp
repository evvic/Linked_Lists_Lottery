#include "Circular_List.h"

#include <iostream>

using namespace std; //might not use this in final buiild for this class

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//WATCH THIS VIDEO TO CREATE TRAVERSING FUCNTIONS UP AND DOWN LIST
//https://www.youtube.com/watch?v=5s0x8bc9DvQ
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


struct node {
	node* previous;
	int data;
	node* next;
};

class Circular_List
{
private:
	node* index; //keeps track of the current position in the list
	node* start;
	node* tail;
public:

	Circular_List() { //constructor
		start = NULL;
		index = NULL;
		tail = NULL;

		//must now create list of nodes containing ints from 1 - 40
		populateList();
	}

	void populateList() {
		//initial nod intialization
		node* temp = new node;
		temp->data = 1;
		temp->previous = NULL;
		start = temp;
		tail = temp;

		//loop populating rest
		for (int i = 2; i < 41; i++) {
			temp = new node;
			temp->data = i;
			temp->previous = tail;
			tail->next = temp;;
			tail = temp;
		}

		//circular
		tail->next = start;
		start->previous = tail;
	}


	//WORK ON THIS FUNCTION	
	void deleteDrawnNumber(int pos) {
		node* cur = new node;
		node* pre = new node;

		cur = head;

		for (int i = 0; i < pos; i++) {
			pre = cur;
			cur = cur->next;
		}

		pre->next = cur->next;
	}


};
