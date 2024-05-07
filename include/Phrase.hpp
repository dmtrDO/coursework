#ifndef PHRASE_HPP
#define PHRASE_HPP
#include <string>


#define MIN_PHRASE_SIZE 10


class Phrase
{
private:
    std::string phrase;
	std::string playerViewPhrase;
	int lettersTotal;
	int lettersGuessed;
	char letter;
	bool guessMark;
public:
    Phrase();

    bool setPhrase(std::string phrase);
    bool isGuessed();
    bool guessLetter(char letter);
    char getGuessedLetter();
    std::string getPlayerView();
    std::string getView();
};
#endif