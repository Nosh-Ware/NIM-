// NIM++.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
long Total = 0;
long subtractMax = 0;
long pastTotal = 0;
long tempInput = 0;
bool playersTurn = false;

int main(bool debug) {
	if (Total == 0) {
		cout << "Enter the total we wil start with" << endl;
		cin >> Total;
	}
	while (Total <= 1) {
		cout << "The start total cannot be smaller than 1" << endl;
		cout << "Enter a new value" << endl;
		cin >> Total;
	}

	if (subtractMax == 0) {
		cout << "Enter the highest amount you will be able to subtract from the total" << endl;
		cin >> subtractMax;
	}
	while (subtractMax >= Total) {
		cout << "The highest possible amount cannot be larger than the total" << endl;
		cout << "Enter a new value" << endl;
		cin >> subtractMax;
		while (subtractMax <= 0) {
			cout << "The highest possible amount cannot be smaller than 0" << endl;
			cout << "Enter a new value" << endl;
			cin >> subtractMax;
		}
	}
	while (subtractMax <= 0) {
		cout << "The highest possible amount cannot be smaller than 0" << endl;
		cout << "Enter a new value" << endl;
		cin >> subtractMax;
	}
	
	cout << "We will start with" << Total << " and subtract with values up to " << subtractMax << endl;
	cout << "Lets start, I'll go first" << endl;
	
	while (Total > 0) {
		pastTotal = Total;

		if (playersTurn) {
			
			cin >> tempInput;
			while (tempInput > subtractMax || tempInput <= 0) {
				cout << "Thats not a valid number to subtract, try something else..." << endl;
				cin >> tempInput;
			}
			cout << "Total " << Total << " - " << tempInput << " = ";
			Total -= tempInput;
			cout << Total << endl;

			playersTurn = false;
		}
		else {
			if (Total % subtractMax != 0) {
				tempInput = Total % subtractMax;
			}
			else {
				tempInput = 1;
			}

			cout << "Here I go:" << endl;
			cout << "Total " << Total << " - " << tempInput << " = ";
			Total -= tempInput;
			cout << Total << endl;

			playersTurn = true;
		}

	}

	if (!playersTurn) {
		cout << "Congradulations! You Won!" << endl;
		cout << "See you next time!" << endl;
	}
	else {
		cout << "I Win! Better Luck Next Time!" << endl;
	}

	system("PAUSE");
}