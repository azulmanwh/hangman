#include <iostream>

using namespace std;
bool gameState = true;
int lives = 6;

void display(char foundLetters[]) {
	for (int i = 0; i < 6; i++) {
		cout << foundLetters[i];
	}
	cout << endl;
}

bool checkWin(char foundLetters[]) {
	int temp = 0;

	for (int i = 0; i < 6; i++) {
		if (foundLetters[i] == '_') {
			return false;
		}
		else {
			temp++;
		}
	}
	if (temp == 6) {
		return true;
	}
	
}

bool checkLetters(char letter, char foundLetters[], char wordList[]) {
	int temp = 0;
	int temp2 = 0;
	for (int i = 0; i < 6; i++) {
		if (letter == foundLetters[i]) {
			temp = 1;
		}
	}
	if (temp < 1) {
		for (int i = 0; i < 6; i++) {
			if (letter == wordList[i]) {
				foundLetters[i] = letter;
				return true;
			}
			else {
				temp2++;
			}
		}
	}
	if (temp2 == 6) {
		cout << "That letter is not in the word!" << endl;
		return false;
	}
	else {
		cout << "You already used that letter!" << endl;
		return false;
	}
}

void guess(string word, char foundLetters[]) {
	char char_array[7];

	strcpy_s(char_array, word.c_str());

	char userGuess;
	cout << "Enter a guess: ";
	cin >> userGuess;

	system("cls");

	if (!checkLetters(userGuess, foundLetters, char_array)) {
		lives--;
	}
}

int main() {
	int ranNum = rand() % 10;

	char letters[6]{ '_', '_', '_', '_', '_', '_' };

	string words[5]{
		"tomato", "tables", "genres", "window", "carpet"
	};

	do {
		display(letters);
		guess(words[ranNum], letters);
		if (checkWin(letters)) {
			gameState = false;
			system("cls");
			display(letters);
			cout << "You guessed it!" << endl;
		}
	} while (gameState && (lives > 0));
}
