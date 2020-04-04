#include "Circular_List.h"

#include <iostream>

using namespace std;

const int lottery_choices = 6;

//Creating a circular doubly linked list

struct node {
	node* previous;
	int data;
	node* next;
};


void UserPicks(int userL[lottery_choices]) {
	//get ALL user lottery picks with ALL input validation
}

int main() {
	int userLottery[lottery_choices];
	UserPicks(userLottery);

	int genLottery[lottery_choices];
	//now generate the rand lottery numbers

	//then compare

	//did they win?
}