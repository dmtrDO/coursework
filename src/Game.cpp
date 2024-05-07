#include "Game.hpp"


void Game::play()
{
    int actingPlayerIndex = 0;

    std::cout << "Welcome to The Field of Wonders!" << std::endl;

    host.askName();
    int playersNumber = host.askNumberOfPlayers();
    for (int i = 0; i < playersNumber; i++)
    {
        players.push_back(Player());
        players[i].askName();
        players[i].askAge();

        std::cout << "Welcome, " << players[i].getName() << "!" << std::endl;
    }
    bool isFromFile = host.askIfPhraseFromFile();
    if (isFromFile)
    {
        phrase.setPhrase(chooseRandomPhrase());
    }
    else
    {
        host.askPhrase(phrase);
    }
    std::cout << "Let The Field of Wonders begin!" << std::endl;

    while (!phrase.isGuessed())
    {
        Round round = roundMaker.makeRound(players[actingPlayerIndex]);

        if (!round.isGuessed())
        {
            actingPlayerIndex = (actingPlayerIndex + 1) % players.size();
        }

        statistics.addRound(round);
    }


    std::cout << phrase.getPlayerView() << std::endl;
    std::cout << "The phrase is guessed, it's time for results!" << std::endl;
    std::cout << statistics.getView() << std::endl;
}
void Game::restart()
{
    statistics.reset();
    players.clear();
}


Game::Game()
: roundMaker(phrase), statistics(players)
{
    srand(time(0));
}

void Game::start()
{
    while (true)
    {
        play();

        bool isRestart = host.askRestart();
        if (isRestart)
        {
            restart();
        }
        else
        {
            std::cout << "The game is closing..." << std::endl;
            break;
        }
    }
}
std::string Game::chooseRandomPhrase()
{
    std::vector<std::string> phrases;
    std::string line;
    std::ifstream file("phrases.txt");
    
    while(std::getline(file, line))
    { 
        if (line.back() == '\n') {
            line.pop_back();
        }
        phrases.push_back(line);  
    }

    return phrases[rand() % phrases.size()];
}