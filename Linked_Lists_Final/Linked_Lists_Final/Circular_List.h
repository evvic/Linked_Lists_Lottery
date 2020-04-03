
//random num is drawn to count how mmany nodes are traversed
//if rand num is odd, traversal is backkwards
//if rand num is even, traversal is forwards

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
	node index; //keeps track of the current position in the list
	node* start;
	node* tail;
public:
	Circular_List();
	void populateList();
	void deleteDrawnNumber(int pos);

};

#endif // !CIRCULAR_LIST_H_INCLUDED