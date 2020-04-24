#include "Circular_List.h"

#include <iostream>

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

	int Circular_List::traverseForward(int travel) {
		//if rand num is even, traversal is forwards
		
		if (showDetails) { std::cout << "\n\tTraversing Forwards: "; }//cp
		for (int i = 0; i < travel; i++) {
			index = index->next;
			if(showDetails) { std::cout << index->data << ' '; } //teting traversal 
		}
		if (showDetails) { std::cout << std::endl; } //cp

		return index->data;
	}

	int Circular_List::traverseBackward(int travel) {
		//if rand num is odd, traversal is backkwards
		
		if (showDetails) { std::cout << "\n\tTraversing Backwards: "; }//cp
		for (int i = 0; i < travel; i++) {
			index = index->previous;
			if (showDetails) { std::cout << index->data << ' '; } //teting traversal 
		}
		if (showDetails) { std::cout << std::endl; }
		
		return index->data;
	}

	void Circular_List::deleteCurrentPosition() {
		node* temp = index;

		node* prev = index->previous;
		node* next = index->next;

		prev->next = next;
		next->previous = prev;

		index = index->next;

		if (showDetails) { std::cout << "\tDeleting node: " << temp << std::endl; }
		delete temp;
	}

	void Circular_List::setShowDetails(bool d) {
		showDetails = d;
	}
