#include "Round.hpp"


Round::Round(Player &_actingPlayer, double timeSpent, char letterGuess, char trueLetter, Phrase phraseState)
: actingPlayer(_actingPlayer)
{
    this->timeSpent = timeSpent;
    this->letterGuess = letterGuess;
    this->trueLetter = trueLetter;
    this->phraseState = phraseState;
}

bool Round::isGuessed()
{
    return tolower(letterGuess) == tolower(trueLetter);
}
std::string Round::getView()
{
    std::stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(2);
    sstream << timeSpent;
    std::string view = "Current phrase state: " + phraseState.toPlayerString() + "\n"
        + "Time spent: " + sstream.str() + " seconds\n"
        + "Acting player: " + actingPlayer.getName() + "\n"
        + actingPlayer.getName() + "'s guess was '" + letterGuess + "'\n";

    if (isGuessed())
    {
        view += actingPlayer.getName() + " was right!";
    }
    else
    {
        view += actingPlayer.getName() + " was wrong... '" + trueLetter + "' was the actual letter!";
    }

    return view;
}
double Round::getTimeSpent()
{
    return timeSpent;
}