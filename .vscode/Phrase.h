#include <iostream>
#define MIN_PHRASE_SIZE 10
class Phrase {
	std::string phrase;
	std::string playerViewPhrase;
	int lettersTotal;
	int lettersGuessed;
	char letter;
	bool guessMark;
public:
	Phrase() {
		lettersGuessed = 0;
	}
	bool setPhrase(std::string phrase) {
		if (phrase.size() < MIN_PHRASE_SIZE) {
			return false;
		}
		if (!isalpha(phrase.front()) || !isalpha(phrase.back())) {
			return false;
		}
		for (size_t i = 1; i < phrase.size() - 1; i++) {
			if (!isalpha(phrase[i]) && phrase[i] != ' ') {
				return false;
			}
			if (phrase[i] == ' ') {
				if (!isalpha(phrase[i - 1]) || !isalpha(phrase[i + 1])) {
					return false;
				} else {
					playerViewPhrase[i] = ' ';
				}
			} 
		}
		this->phrase = phrase;
		lettersTotal = phrase.size();
		playerViewPhrase.assign(lettersTotal, '*');
		for (size_t i = 1; i < phrase.size() - 1; i++) {
			if (phrase[i] == ' ') {
				playerViewPhrase[i] = ' ';
			}
		}
		return true;
	}
	bool isGuessed() {
		return guessMark;
	}
	bool guessLetter(char letter) {
		int startLettersGuessed = lettersGuessed;
		for (size_t i = 0; i < phrase.size(); i++) {
			if (phrase[i] == letter) {
				lettersGuessed++;
				this->letter = letter;
				playerViewPhrase[i] = letter;
			}
		}
		guessMark = startLettersGuessed - lettersGuessed != 0;
		return guessMark;
	}
	char getGuessedLetter() {
		return letter;
	}
	std::string getPlayerView() {
		return playerViewPhrase;
	}
	std::string getView() {
		return phrase;
	}
};