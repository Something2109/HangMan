#ifndef _menu_h
#define _menu_h
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "score.h"
#include "game.h"
#include "wordfile.h"
using namespace std;

void chooseMenu();
void playGame();
void writeWordFile();
vector <Score> getScore(ifstream file);

void menu() {
	cout << setw(22) << "HangMan" << endl;
	cout << setw(23) << "0) New game" << endl;
	cout << setw(25) << "1) High score" << endl;
	cout << setw(30) << "2) Write word file" << endl;
	cout << setw(24) << "3) Exit game" << endl;
	cout << endl;
	chooseMenu();
}

void scoreMenu() {
	ifstream file("score.txt");
	if (file.is_open()) {
		cout << setw(4) << "Rank" << setw(17) << "Name" << setw(15) << "Word Number" << setw(15) << "Wrong Guess" << endl;
		vector <Score> scoreList = getScore();
		for (int i = 0; i < scoreList.size() - 1; i++) {
			cout << setw(4) << i + 1 << scoreList[i];
		}
		cout << endl;
	}
	else {
		cout << "score file not found" << endl;
		cout << endl;
	}
	menu();
}

void chooseMenu() {
	cout<< setw(20) << "Choose: ";
	string choose;
	cin >> choose;
	cout << endl;
	switch (choose[0]) {
	case '0': {
		playGame();
		break;
	}
	case '1': {
		scoreMenu();
		break;
	}
	case '2': {
		writeWordFile();
	}
	case '3': {
		break;
	}
	default: {
		chooseMenu();
	}
	}
}

void gameScreen(int wrongGuess) {
	cout << "________" << endl;
	cout << '|' << setw(7) << ((wrongGuess >= 1) ? '|' : ' ') << endl;
	cout << '|' << setw(7) << ((wrongGuess >= 2) ? 'O' : ' ') << endl;
	cout << '|' << setw(6) << ((wrongGuess >= 4) ? '/' : ' ') << ((wrongGuess >= 3) ? '|' : ' ') << ((wrongGuess >= 5) ? '\\' : ' ') << endl;
	cout << '|' << setw(6) << ((wrongGuess >= 6) ? '/' : ' ') << ((wrongGuess == 7) ? " \\" : " ") << endl;
	cout << '|' << endl;
	cout << '|' << endl;
	cout << "|_______" << endl;
}
#endif