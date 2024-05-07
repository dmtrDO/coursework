#include <string>
#include <fstream>

#include "Game.hpp"


class Game
{
private:
    Phrase phrase;
    RoundMaker roundMaker;
    Statistics statistics;
    Host host;
    std::vector<Player> players;


    void play()
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
    void restart()
    {
        statistics.reset();
        players.clear();
    }
public:
    Game();

    void start()
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
            }
        }
    }
    std::string chooseRandomPhrase()
    {
        srand(time(0));
        std::vector<std::string> phrases;
        std::string line;
        std::ifstream file("phrases.txt");
        
        while(std::getline(file, line))
        { 
            phrases.push_back(line);  
        }
    
        return phrases[rand() % phrases.size()];
    }
};