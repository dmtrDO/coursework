#ifndef ROUND_HPP
#define ROUND_HPP
#include <string>
#include <sstream>

#include "Player.hpp"
#include "Phrase.hpp"


class Round
{
private:
    Player &actingPlayer;
    double timeSpent;
    char letterGuess;
    char trueLetter;
    Phrase phraseState;
public:
    Round(Player &actingPlayer, double timeSpent, char letterGuess, char trueLetter, Phrase phraseState);

    bool isGuessed();
    std::string getView();
    double getTimeSpent();
};
#endif