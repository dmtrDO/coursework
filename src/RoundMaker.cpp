#include "RoundMaker.hpp"


RoundMaker::RoundMaker(Phrase &_phrase)
: phrase(_phrase) {}

Round RoundMaker::makeRound(Player &actingPlayer)
{
    timer.start();

    std::cout << "It's " << actingPlayer.getView() << "'s turn!" << std::endl;
    std::cout << "Phrase: " << phrase.getPlayerView() << std::endl;
    Phrase phraseState = phrase;
    char letterGuess = actingPlayer.askLetter();
    char trueLetter = phrase.getGuessedLetter();
    bool isGuessed = phrase.guessLetter(letterGuess);

    timer.stop();

    std::cout << actingPlayer.getView() << " thinks the letter is '" << letterGuess << "'!" << std::endl;
    if (isGuessed)
    {
        actingPlayer.setScore(actingPlayer.getScore() + 1);

        std::cout << actingPlayer.getView() << "'s guess was right!" << std::endl;
    }
    else
    {
        std::cout << actingPlayer.getView() << "'s guess was wrong!" << std::endl;
    }

    Round round = Round(actingPlayer,
        timer.getElapsedTime(),
        letterGuess,
        trueLetter,
        phraseState);
    return round;
}