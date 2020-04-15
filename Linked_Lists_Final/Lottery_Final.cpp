#include "Circular_List.h"

#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>

using namespace std;


const int lotto_choices = 6;	//6 choices of numbers in the lottery
const int lotto_min_num = 1;	//can choose nums from 1
const int lotto_max_num = 40;	//to 40


void UserPicks(int*& userL);
void LottoPicks(int*& genL);

bool AlreadyChosen(int*& arr, int test); //returns true if test num has alaready been chosen previously in array
bool OutOfBounds(int test);

int RandNum(int min, int max);
bool EvenIsTrue(int num);

int CompareLotteryPicks(int*& userL, int*& genL); //return how many user got the same

void Results(int c);

void CenterString(string s);

void DisplayLotteryNums(int*& lotto, string s);

int main() {
	int correct = 0; //amount that user got the same

	//dynaimcally allocate arrrays
	int* userLotto = new int[lotto_choices];
	int* genLotto = new int[lotto_choices];

	//get user lottery pickings
	UserPicks(userLotto);

	//now generate the rand lottery numbers
	LottoPicks(genLotto);

	//Compare generated and user lottery picks and return amount that are the same
	correct = CompareLotteryPicks(userLotto, genLotto);

	system("CLS"); //clear screen from user input

	cout << endl;
	DisplayLotteryNums(userLotto, "   Your picks:");
	DisplayLotteryNums(genLotto, "   Lottery picks:");
	cout << endl;

	//dispays results of how many were correct and the "winnings"
	Results(correct);

	//test if gennerated lotto worked.... IT WORKED!!
	/*
	cout << "gen lotto: \n";
	for (int i = 0; i < lotto_choices; i++) {
		cout << genLotto[i] << " ";
	}
	*/


	//prevent memory leakage
	delete[] userLotto;
	delete[] genLotto;
}

void DisplayLotteryNums(int*& lotto, string s) { //displays a neat row of the selected lottery numbers
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		// an error occourred
		cerr << "Cannot determine console size." << endl;
	}
	else
	{
		//cout << "\n\nThe console is " << csbi.srWindow.Right - csbi.srWindow.Left << " wide." << endl; //checkpoint
	}

	int c_width = csbi.srWindow.Right - csbi.srWindow.Left;

	/*
	   __
	 /    \
	|  23  |
	 \ __ /
	*/

	int spaces = 6;
	//6 * 6 = 36

	int length = lotto_choices * spaces;
	length += 4; //to fix right-adjustment

	int position = (int)((c_width - length) / 2);
	cout << s;
	for (int i = 0; i < position - s.length(); i++) {
		cout << ' ';
	}

	for (int i = 0; i < lotto_choices; i++) {
		cout << setw(6) << lotto[i];
	}

	cout << endl;
}

void Results(int c) {
	switch (c) {
		case 0:
			CenterString("You matched 0 numbers.");
			cout << endl;
			CenterString("---Better luck next time---");
			cout << endl;
			break;
		case 1:
			CenterString("You only matched 1 number.");
			cout << endl;
			CenterString("You get your money back.");
			cout << endl;
			break;
		case 2:
			CenterString("You matched 2 numbers.");
			cout << endl;
			CenterString("You've won $15.");
			cout << endl;
			break;
		case 3:
			CenterString("You matched 3 numbers.");
			cout << endl;
			CenterString("You've won $250.");
			cout << endl;
			break;
		case 4:
			CenterString("You matched 4 numbers.");
			cout << endl;
			CenterString("You've won $20,000.");
			cout << endl;
			break;
		case 5:
			CenterString("You missed the jackpot by one.");
			cout << endl;
			CenterString("You've won $100,000.");
			cout << endl;
			break;
		case 6:
			CenterString("CONGRATULATIONS! You matched all 6 numbers.");
			cout << endl;
			CenterString("You've won $100 million.");
			cout << endl;
			break;
		default:
			cout << "Results() error.. I guess you lost lol";
			break;
	}
}

int CompareLotteryPicks(int*& userL, int*& genL) {
	int correct = 0;

	for (int i = 0; i < lotto_choices; i++) {
		if (userL[i] == genL[i]) {
			correct++;
			cout << "Correct! At position " << i + 1 << endl; //checkpoint?
		}
	}

	return correct;
}

void UserPicks(int*& userL) {
	//get ALL user lottery picks with ALL input validation
	int num;

	for (int i = 0; i < lotto_choices; i++) {
		do {
			try {
				cout << endl << "Pick lottery number #" << i + 1 << ": ";
				cin >> num;
				//catch any user input mistakes
				if (!cin) {
					throw 0;
				}
			}
			catch (int param) {
				cin.clear();
				cin.ignore(256, '\n');

				cout << "Caught exception";
			}

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

void LottoPicks(int*& genL) {
	//get ALL generated lottery picks
	//delete picked nums from list
	//choose random traversal amount

	int rand;

	Circular_List Lottery; //create linked list in heap, resets when function is finished

	srand(time(0)); //random seed

	for (int i = 0; i < lotto_choices; i++) {
		rand = RandNum(lotto_min_num, lotto_max_num);

		//cout << "\nRand num: " << rand << endl; //checkpoint 

		if (EvenIsTrue(rand)) {
			//even num traverses forward
			genL[i] = Lottery.traverseForward(rand);
			Lottery.deleteCurrentPosition();
		}
		else if (!EvenIsTrue(rand)) {
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

void CenterString(string s) {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		// an error occourred
		cerr << "Cannot determine console size." << endl;
	}
	else
	{
		//cout << "\n\nThe console is " << csbi.srWindow.Right - csbi.srWindow.Left << " wide." << endl; //checkpoint
	}


	int c_width = csbi.srWindow.Right - csbi.srWindow.Left;
	int length = s.size();
	int position = (int)((c_width - length) / 2);
	for (int i = 0; i < position; i++) {
		cout << ' ';
	}
	cout << s;
}