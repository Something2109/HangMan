#ifndef _score_h
#define _score_h
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Score {
	string name;
	int wordNumb = 0;
	int wrongGuess = 0;
public:
	Score() {
		string name;
		wordNumb = 0;
		wrongGuess = 0;
	}
	Score(string _name, int _wordNumb, int _wrongGuess) {
		name = _name;
		wordNumb = _wordNumb;
		wrongGuess = _wrongGuess;
	}
	void setName(string str) {
		name = str;
	}
	string getName() {
		return name;
	}
	void setWordNumb(int n) {
		wordNumb = n;
	}
	int getWordNumb() {
		return wordNumb;
	}
	void setWrongGuess(int n) {
		wrongGuess = n;
	}
	int getWrongGuess() {
		return wrongGuess;
	}
	void swap(Score& b) {
		Score a(name, wordNumb, wrongGuess);
		name = b.name;
		wordNumb = b.wordNumb;
		wrongGuess = b.wrongGuess;
		b = a;
	}
};

ostream& operator<< (ostream& out, Score a) {
	out << setw(17) << a.getName() << setw(15) << a.getWordNumb() << setw(15) << a.getWrongGuess() << endl;
	return out;
}// define outstream of Score

ofstream& operator<< (ofstream& out, Score a) {
	out << a.getName() << ' ' << a.getWordNumb() << ' ' << a.getWrongGuess() << endl;
	return out;
}// define out file stream of Score

void printScore(int wrongGuess) {
	cout << "Your try: " << wrongGuess << endl;
} // print score to screen

void printToFile(string answerWord, int wrongGuess) {
	ofstream file("score.txt", ofstream::app);
	if (file.is_open()) {
		string name;
		do {
			cout << "Your name (pls enter equal or less than 15 character): ";
			cin >> name;
			cout << endl;
		} while (name.length() > 15);
		Score save;
		save.setName(name);
		save.setWordNumb(answerWord.length());
		save.setWrongGuess(wrongGuess);
		file << save;
	}
	else {
		cout << "score file not found" << endl;
		cout << endl;
	}
} // print in score.txt file

void rankingScoreList(vector <Score>& scoreList);

vector <Score> getScore() {
	ifstream file("score.txt");
	vector <Score> scoreList;
	while (!file.eof()) {
		string list;
		getline(file, list);
		Score save;
		string name;
		int wordNumb, wrongGuess, point;
		stringstream ss(list);
		ss >> name >> wordNumb >> wrongGuess >> point;
		save.setName(name);
		save.setWordNumb(wordNumb);
		save.setWrongGuess(wrongGuess);
		scoreList.push_back(save);
	}
	rankingScoreList(scoreList);
	return scoreList;
} // get the scores from file

void rankingScoreList(vector <Score> &scoreList) {
	for (int i = 0; i < scoreList.size() - 1; i++) {
		for (int j = i + 1; j < scoreList.size() - 1; j++) {
			if (scoreList[j].getWordNumb() > scoreList[i].getWordNumb()) {
				scoreList[j].swap(scoreList[i]);
			}
			else {
				if (scoreList[j].getWrongGuess() < scoreList[i].getWrongGuess() && scoreList[j].getWordNumb() == scoreList[i].getWordNumb()) {
					scoreList[j].swap(scoreList[i]);
				}
			}
		}
	}
} // sort score list
#endif
