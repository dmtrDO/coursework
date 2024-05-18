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
        try 
        {
            phrase.setPhrase(chooseRandomPhrase());
        } catch (int num) 
        {
            std::cout << "\nUnexpected error: " << num << " correct strings in file\n\n";
            std::cout << "In this case, the host will be the one to guess the phrase\n";
            host.askPhrase(phrase);
        }
    }
    else
    {
        host.askPhrase(phrase);
    }
    std::cout << "\nLet The Field of Wonders begin!" << std::endl;

    while (!phrase.isGuessed())
    {
        Round round = roundMaker.makeRound(players[actingPlayerIndex]);

        if (!round.isGuessed())
        {
            actingPlayerIndex = (actingPlayerIndex + 1) % players.size();
        }

        statistics.addRound(round);
    }


    std::cout << phrase.toPlayerString() << std::endl;
    std::cout << "The phrase is guessed, it's time for results!" << std::endl;
    std::cout << statistics.toString() << std::endl;
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
    std::ifstream file("phrases.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Failed to open file" << std::endl;
        exit(1);
    }
    std::vector<std::string> phrases;
    std::string line;
    char ch;
    while (file.get(ch))
    {
        if (ch == '\n') 
        {
            phrases.push_back(line);
            line.erase();
            continue;
        }
        if (isalpha(ch) || ch == ' ') 
        {
            line += ch;
        }
    }
    file.close();
    if (phrases.size() == 0) 
    {
        throw 0;
    } 
    else 
    {
        for (size_t i = 0; i < phrases.size(); i++) 
        {
            if (phrases[i].empty()) throw 0;
        }
    }
    return phrases[rand() % phrases.size()];
}
