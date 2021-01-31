#ifndef _wordfile_h
#define _wordfile_h
#include <iostream>
#include <vector>
#include <string>
#include "menu.h"
using namespace std;

void menu();
void fileMenu(vector <string>& word);

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

void readSourceFile(vector <string>& word) {
	ifstream file("word.txt");
	int n;
	file >> n;
	string getWord;
	for (int i = 0; i < n; i++) {
		file >> getWord;
		word.push_back(getWord);
	}
}

void readWordFile(vector <string> &word) {
	cout << "Enter file name: ";
	string path;
	cin >> path;
	ifstream file(path);
	if (file.is_open()) {
		string getWord;
		do {
			file >> getWord;
			if (!checkLetter(getWord)) {
				continue;
			}
			else {
				if (!checkDup(getWord, word)) {
					continue;
				}
				else {
					word.push_back(getWord);
				}
			}
		} while (!file.eof());
	}
	else {
		cout << "cannot find file" << endl;
	}
}

void addWord(vector <string> &word) {
	string getWord;
	cout << "Enter: ";
	cin >> getWord;
	while (getWord[0] != '0') {
		if (!checkLetter(getWord)) {
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
}

void saveToSourceFile(vector <string> word) {
	ofstream infile("word.txt");
	infile << word.size() << endl;
	for (int i = 0; i < word.size(); i++) {
		infile << word[i] << endl;
	}
	cout << "Your change has been saved" << endl;
	cout << endl;
}

void writeWordFile() {
	ifstream file("word.txt");
	vector <string> word;
	if (file.is_open()) {
		readSourceFile(word);
		fileMenu(word);
		saveToSourceFile(word);
	}
	menu();
}

#endif
