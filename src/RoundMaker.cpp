#include "RoundMaker.hpp"


RoundMaker::RoundMaker(Phrase &_phrase)
: phrase(_phrase) {}

Round RoundMaker::makeRound(Player &actingPlayer)
{
    timer.start();

    std::cout << "It's " << actingPlayer.getName() << "'s turn!" << std::endl;
    std::cout << "Phrase: " << phrase.getPlayerView() << std::endl;
    Phrase phraseState = phrase;
    char letterGuess = actingPlayer.askLetter();
    char trueLetter = phrase.getGuessedLetter();
    bool isGuessed = phrase.guessLetter(letterGuess);

    timer.stop();

    std::cout << actingPlayer.getName() << " thinks the letter is '" << letterGuess << "'!" << std::endl;
    if (isGuessed)
    {
        actingPlayer.addScore();
        std::cout << actingPlayer.getName() << "'s guess was right!" << std::endl;
    }
    else
    {
        std::cout << actingPlayer.getName() << "'s guess was wrong!" << std::endl;
    }

    Round round = Round(actingPlayer,
        timer.getElapsedTime(),
        letterGuess,
        trueLetter,
        phraseState);
    return round;
}