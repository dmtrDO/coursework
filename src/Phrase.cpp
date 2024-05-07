#include "Phrase.hpp"


Phrase::Phrase()
{
	lettersGuessed = 0;
}
bool Phrase::setPhrase(std::string phrase)
{
	if (phrase.size() < MIN_PHRASE_SIZE)
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
	return guessMark;
}
bool Phrase::guessLetter(char letter)
{
	int startLettersGuessed = lettersGuessed;
	for (size_t i = 0; i < phrase.size(); i++)
	{
		if (phrase[i] == letter) {
			lettersGuessed++;
			this->letter = letter;
			playerViewPhrase[i] = letter;
		}
	}
	guessMark = startLettersGuessed - lettersGuessed != 0;
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