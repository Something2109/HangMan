#ifndef _wordfile_h
#define _wordfile_h
#include <iostream>
#include <vector>
#include <string>
#include "menu.h"
using namespace std;

void menu();

bool checkLetter(string& getWord) {
	for (int i = 0; i < getWord.length(); i++) {
		if (getWord[i] < 'A' || (getWord[i] > 'Z' && getWord[i] < 'a') || getWord[i] > 'z') {
			return false;
		}
		if (getWord[i] >= 'A' && getWord[i] <= 'Z') {
			getWord[i] += 'a' - 'A';
		}
	}
	return true;
}

bool checkDup(string getWord, vector <string> word) {
	for (int i = 0; i < word.size(); i++) {
		if (getWord == word[i]) {
			return false;
		}
	}
	return true;
}

void writeWordFile() {
	ifstream file("word.txt");
	if (file.is_open()) {
		int n;
		file >> n;
		string getWord;
		vector <string> word;
		for (int i = 0; i < n; i++) {
			file >> getWord;
			word.push_back(getWord);
		}
		cout << "Enter: ";
		cin >> getWord;
		while (getWord[0] != '0') {
			if (!checkLetter(getWord) ) {
				cout << "Wrong letter" << endl;
			}
			else {
				if (!checkDup(getWord, word)) {
					cout << "Duplicate" << endl;
				}
				else {
					string SaveCheck;
					do {
						cout << "Do you want to enter " << getWord << " (0: no, 1: yes): ";
						cin >> SaveCheck;
					} while (SaveCheck[0] != '0' && SaveCheck[0] != '1');
					if (SaveCheck[0] == '1') {
						word.push_back(getWord);
						cout << "Saved!" << endl;
					}
				}
			}
			cout << "Enter: ";
			cin >> getWord;
		}
		ofstream infile("word.txt");
		infile << word.size() << endl;
		for (int i = 0; i < word.size(); i++) {
			infile << word[i] << endl;
		}
		cout << "Your change has been saved" << endl;
	}
	menu();
}

#endif
