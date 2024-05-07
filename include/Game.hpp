#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <fstream>


#include "RoundMaker.hpp"
#include "Statistics.hpp"
#include "Host.hpp"


class Game
{
private:
    Phrase phrase;
    RoundMaker roundMaker;
    Statistics statistics;
    Host host;
    std::vector<Player> players;


    void play();
    void restart();
public:
    Game();

    void start();
    std::string chooseRandomPhrase();
};
#endif