#include "Phrase.hpp"

Phrase::Phrase()
{
	lettersGuessed = 0;
	guessPhrase = false;
}
bool Phrase::setPhrase(std::string phrase)
{
	for (size_t i = 0; i < phrase.size(); i++) {
		phrase[i] = tolower(phrase[i]);
	}
	letter = phrase[0];
	lettersGuessed = 0;
	guessPhrase = false;
	if (phrase.size() < MIN_PHRASE_SIZE || phrase.size() > MAX_PHRASE_SIZE || !isalpha(phrase.front()) || !isalpha(phrase.back()))
	{
		return false;
	}
	for (size_t i = 1; i < phrase.size() - 1; i++)
	{
		if (!isalpha(phrase[i]) && phrase[i] != ' ')
		{
			return false;
		}
		if (phrase[i] == ' ')
		{
			if (!isalpha(phrase[i - 1]) || !isalpha(phrase[i + 1]))
			{
				return false;
			}
		}
	}
	this->phrase = phrase;
	lettersTotal = phrase.size();
	playerViewPhrase.assign(lettersTotal, '*');
	for (size_t i = 1; i < phrase.size() - 1; i++)
	{
		if (phrase[i] == ' ')
		{
			playerViewPhrase[i] = ' ';
		}
	}
	return true;
}
bool Phrase::isGuessed()
{
	return guessPhrase;
}
bool Phrase::guessLetter(char letter)
{
	letter = tolower(letter);
	int startLettersGuessed = lettersGuessed;
	if (phrase[lettersGuessed] == letter)
	{
		playerViewPhrase[lettersGuessed] = letter;
		lettersGuessed++;
	}
	if (phrase[lettersGuessed] == ' ') lettersGuessed++;
	this->letter = phrase[lettersGuessed];
	if (phrase == playerViewPhrase) guessPhrase = true;
	return startLettersGuessed - lettersGuessed != 0;
}
char Phrase::getGuessedLetter()
{
	return letter;
}
std::string Phrase::toPlayerString()
{
	return playerViewPhrase;
}