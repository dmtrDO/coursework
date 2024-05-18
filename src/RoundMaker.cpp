#include "RoundMaker.hpp"

char RoundMaker::askLetter()
{
    std::string input;
    bool mark = true;
    while (mark)
    {
        mark = false;
        std::cout << "Enter a character: ";
        std::getline(std::cin, input);
        if (input.empty() || input.size() > 1 || !isalpha(input.front()))
        {
            if (input.empty())
            {
                std::cout << "Error: You haven't entered anything.\n";
            }
            else if (input.size() > 1)
            {
                std::cout << "Error: You have entered more than one character.\n";
            } 
            else
            {
                std::cout << "Error: You have entered a non-alphabetic character.\n";
            }
            mark = true;
        }
    }
    return input.front();
}

RoundMaker::RoundMaker(Phrase &_phrase)
: phrase(_phrase) {}

Round RoundMaker::makeRound(Player &actingPlayer)
{
    timer.start();

    std::cout << "It's " << actingPlayer.getName() << "'s turn!" << std::endl;
    std::cout << "Phrase: " << phrase.getPlayerView() << std::endl;
    Phrase phraseState = phrase;
    //char letterGuess = actingPlayer.askLetter();
    char letterGuess = askLetter();
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