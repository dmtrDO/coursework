#ifndef PHRASE_HPP
#define PHRASE_HPP
#include <string>
#include <cctype>


#define MIN_PHRASE_SIZE 10
#define MAX_PHRASE_SIZE 40


class Phrase
{
private:
    std::string phrase;
	std::string playerViewPhrase;
	int lettersTotal;
	int lettersGuessed;
	char letter;
    bool guessPhrase;
public:
    Phrase();

    bool setPhrase(std::string phrase);
    bool isGuessed();
    bool guessLetter(char letter);
    char getGuessedLetter();
    std::string toPlayerString();
};
#endif