#include "Circular_List.h"

#include <iostream>
#include <time.h>

using namespace std;


const int lotto_choices = 6;	//6 choices of numbers in the lottery
const int lotto_min_num = 1;	//can choose nums from 1
const int lotto_max_num = 40;	//to 40



void UserPicks(int *&userL);
void LottoPicks(int *&genL);

int RandNum(int min, int max);
bool EvenIsTrue(int num);

int main() {
	//dynaimcally allocate arrrays
	int* userLotto = new int[lotto_choices];
	int* genLotto = new int[lotto_choices];

	//get user lottery pickings
	UserPicks(userLotto);

	//now generate the rand lottery numbers
	LottoPicks(genLotto);

	//then compare

	//did they win?

	//test if gennerated lotto worked.... IT WORKED!!
	cout << "gen lotto: \n";
	for (int i = 0; i < lotto_choices; i++) {
		cout << genLotto[i] << " ";
	}


	//prevent memory leakage
	delete[] userLotto;
	delete[] genLotto;
}

void UserPicks(int *&userL) {
	//get ALL user lottery picks with ALL input validation
}

void LottoPicks(int *&genL) {
	//get ALL generated lottery picks
	//delete picked nums from list
	//choose random traversal amount

	int rand;

	Circular_List Lottery; //create linked list in heap, resets when function is finished

	for (int i = 0; i < lotto_choices; i++) {
		rand = RandNum(lotto_min_num, lotto_max_num);

		if ( EvenIsTrue(rand) ) {
			//even num traverses forward
			genL[i] = Lottery.traverseForward(rand);
			Lottery.deleteCurrentPosition();
		}
		else if( !EvenIsTrue(rand) ) {
			//odd num traverses backward
			genL[i] = Lottery.traverseBackward(rand);
			Lottery.deleteCurrentPosition();
		}
		else {
			cout << "\n\tError. Was not even or odd?\n";
			i--;
			cout << "\tTrying again.\n";
		}		
	}
	//no need to return, pass by reference
}

bool EvenIsTrue(int num) {
	if (num % 2 == 0) {
		return true;
	}
	else return false;;
}

int RandNum(int min, int max) {
	srand(time(0));

	return rand() % max + min;
}