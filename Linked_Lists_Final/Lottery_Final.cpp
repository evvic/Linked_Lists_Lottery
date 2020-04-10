#include "Circular_List.h"

#include <iostream>
#include <time.h>

using namespace std;


const int lotto_choices = 6;	//6 choices of numbers in the lottery
const int lotto_min_num = 1;	//can choose nums from 1
const int lotto_max_num = 40;	//to 40


void UserPicks(int *&userL);
void LottoPicks(int *&genL);

bool AlreadyChosen(int *&arr, int test); //returns true if test num has alaready been chosen previously in array
bool OutOfBounds(int test);

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


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//WORK ON CATCHING EXCEPTIONS (I.E. USER ENTERS -99999...999999)
void UserPicks(int *&userL) {
	//get ALL user lottery picks with ALL input validation
	int num;

	for (int i = 0; i < lotto_choices; i++) {
		do {
			cout << endl << "Pick lottery number #" << i + 1 << ": ";
			cin >> num;
		} while (OutOfBounds(num) || AlreadyChosen(userL, num));

		userL[i] = num;
	}
}

bool AlreadyChosen(int*& arr, int test) { //returns true if test matches any nums in arr
	for (int i = 0; i < lotto_choices; i++) {
		if (arr[i] == test) {
			cout << endl << "The number " << test << " has already been chosen.";
			cout << endl << "Cannot choose the same number more than once." << endl;
			return true;
		}
	}
	return false;
}

bool OutOfBounds(int test) { //true if out of bounds
	if (test < lotto_min_num) {
		cout << "\nChosen lottery number cannot be below " << lotto_min_num << '.' << endl;
		return true;
	}
	else if (test > lotto_max_num) {
		cout << "\nChosen lottery number cannot be above " << lotto_max_num << '.' << endl;
		return true;
	}
	else {
		return false;
		//number was NOT out of bounds
	}
}


void LottoPicks(int *&genL) {
	//get ALL generated lottery picks
	//delete picked nums from list
	//choose random traversal amount

	int rand;

	Circular_List Lottery; //create linked list in heap, resets when function is finished

	srand(time(0)); //random seed

	for (int i = 0; i < lotto_choices; i++) {
		rand = RandNum(lotto_min_num, lotto_max_num);

		cout << "\nRand num: " << rand << endl;

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
	return rand() % max + min;
}