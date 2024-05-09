#include "Phrase.hpp"


Phrase::Phrase()
{
	lettersGuessed = 0;
	guessPhrase = false;
}
bool Phrase::setPhrase(std::string phrase)
{
	letter = phrase[0];
	lettersGuessed = 0;
	guessPhrase = false;
	if (phrase.size() < MIN_PHRASE_SIZE)
	{
		return false;
	}
	if (phrase.size() > MAX_PHRASE_SIZE)
	{
		return false;
	}
	if (!isalpha(phrase.front()) || !isalpha(phrase.back()))
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
			} else {
				playerViewPhrase[i] = ' ';
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
	guessMark = false;
	if (phrase[lettersGuessed] == ' ') lettersGuessed++;
	if (tolower(phrase[lettersGuessed]) == tolower(letter)) {
		playerViewPhrase[lettersGuessed] = letter;
		lettersGuessed++;
		this->letter = phrase[lettersGuessed];
		guessMark = true;
	}
	bool guessMark = startLettersGuessed - lettersGuessed != 0;
	if (phrase == playerViewPhrase) guessPhrase = true;
	return guessMark;
}
char Phrase::getGuessedLetter()
{
	return letter;
}
std::string Phrase::getPlayerView()
{
	return playerViewPhrase;
}
std::string Phrase::getView()
{
	return phrase;
}