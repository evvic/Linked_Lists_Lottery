#include "Circular_List.h"

#include <iostream>

using namespace std;

//Creating a circular doubly linked list

struct node {
	node* previous;
	int data;
	node* next;
};



//original linked list format
class list {
private:
	node* head, * tail;
public:
	list() {
		head = NULL;
		tail = NULL;
	}

	void createnode(int value) {
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;


		try {
			if (head == NULL) {
				//in this case the entire list is empty so head = tail = temp (of first created node)
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else {
				tail->next = temp->next; //added the ->next to temp
				tail = temp;

			}
		}
		catch (int param) {
			cout << "\nERROR createnode()\n";
		}
	}

	void display() {
		//loops through list till tail pointing to NULL is found, NULL terminates loop
		node* temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}

	//insert value at head
	void insert_start(int val) {
		node* temp = new node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	//inserts value into linked list at any position between head to tail
	void insert_position(int pos, int val) {
		node* pre = new node;
		node* cur = new node;
		node* temp = new node;

		cur = head;

		try {
			for (int i = 0; i < pos; i++) {
				if (cur == NULL) {
					throw 66;
				}
				pre = cur;
				cur = cur->next;
			}
		}
		catch (int p) {
			cout << "\nERROR: " << p << "   insert_position() list.\n";
			cout << "\nCannot insert value to linked list\n";
		}

		temp->data = val;
		pre->next = temp;
		temp->next = cur;
	}

	void delete_first() {
		node* temp = new node;
		temp = head;

		head = head->next;

		delete temp;
	}

	void delete_last() {
		node* cur = new node;
		node* pre = new node;

		cur = head;

		while (cur->next != NULL) {
			pre = cur; //previous = current
			cur = cur->next;
		}

		tail = pre;
		pre->next = NULL;
		delete cur;
	}

	void delete_position(int pos) {
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

int main() {

}