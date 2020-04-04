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

		//initialize index at start
		index = start;
	}

	//this function should use the traverse functions, rand num chooser, and delete drawn number
	//functions to pick and return each lottery number
	//should not be apart of the class however
	int drawLotteryNumber() {}
	///\



	int traverseForward(int travel) {
		//if rand num is even, traversal is forwards

		//node* temp = index;
		//might not need temp if index is keeping track

		for (int i = 0; i < travel; i++) {
			index = index->next;
		}

		return index->data;
	}

	int traverseBackward(int travel) {
		//if rand num is odd, traversal is backkwards

		for (int i = 0; i < travel; i++) {
			index = index->previous;
		}

		return index->data;
	}


	//WORK ON THIS FUNCTION	
	void deleteCurrentPosition() {
		node* temp = index;

		node* prev = index->previous;
		node* next = index->next;

		prev->next = next;
		next->previous = prev;

		index = index->next;

		delete temp;
	}

};
