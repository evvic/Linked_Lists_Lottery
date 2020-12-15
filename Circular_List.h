//random num is drawn to count how many nodes are traversed

#ifndef CIRCULAR_LIST_H_INCLUDED
#define CIRCULAR_LIST_H_INCLUDED

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
	bool showDetails = false;
public:
	Circular_List();
	void populateList(); // 1 - 40

	int traverseForward(int travel); //even rand int
	int traverseBackward(int travel); //odd rand int

	void deleteCurrentPosition();

	void setShowDetails(bool d);
};

#endif // !CIRCULAR_LIST_H_INCLUDED
