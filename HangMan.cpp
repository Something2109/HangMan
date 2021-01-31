#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "game.h"
#include "menu.h"
using namespace std;

int main() {
	srand(time(NULL));
	menu();
	return 0;
}

/*int main() {
	int wrongGuess;
	cin >> wrongGuess;
	cout << "________" << endl;
	cout << '|' << setw(7) << ((wrongGuess >= 1) ? '|' : ' ' ) << endl;
	cout << '|' << setw(7) << ((wrongGuess >= 2) ? 'O' : ' ') << endl;
	cout << '|' << setw(6) << ((wrongGuess >= 4) ? '/' : ' ') << ((wrongGuess >= 3) ? '|' : ' ') << ((wrongGuess >= 5) ? '\\' : ' ') << endl;
	cout << '|' << setw(6) << ((wrongGuess >= 6) ? '/' : ' ') << ((wrongGuess == 7) ? " \\" : " " ) << endl;
	cout << '|' << endl;
	cout << '|' << endl;
	cout << "|_______" << endl;
}*/