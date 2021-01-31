#ifndef _game_h
#define _game_h
#include <iostream>
#include <string>
#include <fstream>
#include "score.h"
#include "menu.h"
using namespace std;

string getAnswerWord();
char inputGuessChar(char guessedLetter[]);
void printAnswer(string answerWord, string& guessWord, char guessChar, int& wrongGuess);
void gameOver(string answerWord,int wrongGuess);

void playGame() {
	ifstream file("word.txt");
	if (file.is_open()) {
		string answerWord = getAnswerWord();
		string guessWord(answerWord.length(), '-');
		int wrongGuess = 0;
		char guessedLetter[26]; //check answered letter
		gameScreen(wrongGuess);
		cout << guessWord << endl;
		do {
			char guessChar = inputGuessChar(guessedLetter);
			printAnswer(answerWord, guessWord, guessChar, wrongGuess);
		} while (answerWord != guessWord && wrongGuess < 7);
		gameOver(answerWord, wrongGuess);
	} // can open word file
	else {
		cout << "Word file not found." << endl;
		cout << endl;
	} // cannot open word file
}

string getAnswerWord() {
	string answerWord;
	int numberOfWord;
	ifstream file("word.txt"); 
	file >> numberOfWord; // take the number of word in file
	for (int i = 0; i <= (rand() % numberOfWord); i++) {
		file >> answerWord;
	} // get to a random word
	return answerWord;
}

char inputGuessChar(char guessedLetter[]) {
	string guessString;
	cout << "Guess a letter: ";
	cin >> guessString;
	char guessChar = guessString[0]; // take first character of the cin string
	while (guessChar < 'A' || (guessChar > 'Z' && guessChar < 'a') || guessChar > 'z') {
		cout << endl;
		cout << "You entered the wrong character, guess again: ";
		cin >> guessChar;
	} // wrong character
	while (guessChar == guessedLetter[guessChar - 'a'] || guessChar == guessedLetter[guessChar - 'A']) {
		cout << endl;
		cout << "You've entered that character, guess again: ";
		cin >> guessChar;
	} // duplicated letter
	if (guessChar >= 'A' && guessChar <= 'Z') {
		guessChar += ('a' - 'A');
	} // change uppercase
	guessedLetter[guessChar - 'a'] = guessChar;
	return guessChar;
}

void printAnswer(string answerWord, string& guessWord, char guessChar, int& wrongGuess) {
	int change = 0;
	for (int i = 0; i < answerWord.length(); i++) {
		if (answerWord[i] == guessChar) {
			guessWord[i] = guessChar;
			change++;
		}
	} // change guessWord
	if (change == 0) {
		wrongGuess++;
		gameScreen(wrongGuess);
		cout << guessWord << endl;
		cout << "You guess the wrong letter, try again." << endl;
	} // cout if wrong letter
	else {
		gameScreen(wrongGuess);
		cout << guessWord << endl;
		cout << "You guess " << change << ((change == 1) ? " correct letter" : " correct letters") << endl;
	} // cout if right letter
	printScore(wrongGuess);
	cout << endl;
}

void gameOver(string answerWord, int wrongGuess) {
	if (wrongGuess < 7) {
		cout << "You have successfully escaped the execution." << endl;
		cout << "The answer is " << answerWord << endl;
		printToFile(answerWord, wrongGuess);
	} // win
	else {
		cout << "You died." << endl;
		cout << "The answer is " << answerWord << endl;
		cout << endl;
	} // lose
	menu();
}

#endif