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
    std::string view = "Current phrase state: " + phraseState.getPlayerView() + "\n"
        + "Time spent: " + std::to_string(timeSpent) + " seconds\n"
        + "Phrase: " + phraseState.getPlayerView() + "\n"
        + "Acting player: " + actingPlayer.getView() + "\n"
        + actingPlayer.getName() + "'s guess was " + letterGuess + "\n";

    if (isGuessed())
    {
        view += actingPlayer.getName() + " was right!";
    }
    else
    {
        view += actingPlayer.getName() + " was wrong... " + trueLetter + " was the actual letter!";
    }

    return view;
}
double Round::getTimeSpent()
{
    return timeSpent;
}