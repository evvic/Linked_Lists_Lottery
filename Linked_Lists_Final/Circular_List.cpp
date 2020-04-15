#include "Circular_List.h"

#include <iostream>

using namespace std; //might not use this in final buiild for this class

/*
struct node {
	node* previous;
	int data;
	node* next;
};
*/

	Circular_List::Circular_List() { //constructor
		start = NULL;
		index = NULL;
		tail = NULL;

		//must now create list of nodes containing ints from 1 - 40
		populateList();
	}

	void Circular_List::populateList() {
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
			tail->next = temp;
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
	//int Circular_List::drawLotteryNumber() {}
	///\



	int Circular_List::traverseForward(int travel) {
		//if rand num is even, traversal is forwards

		//node* temp = index;
		//might not need temp if index is keeping track

		
		//cout << "\nForwards: "; //cp
		for (int i = 0; i < travel; i++) {
			index = index->next;
			//cout << index->data << ' '; //teting traversal
		}
		//cout << endl; //cp
		

		return index->data;
	}

	int Circular_List::traverseBackward(int travel) {
		//if rand num is odd, traversal is backkwards

		
		//cout << "\nBackwards: "; //cp
		for (int i = 0; i < travel; i++) {
			index = index->previous;
			//cout << index->data << ' '; //teting traversal
		}
		//cout << endl; //cp
		

		return index->data;
	}


	//WORK ON THIS FUNCTION	
	void Circular_List::deleteCurrentPosition() {
		node* temp = index;

		node* prev = index->previous;
		node* next = index->next;

		prev->next = next;
		next->previous = prev;

		index = index->next;

		delete temp;
	}
