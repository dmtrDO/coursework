#ifndef ROUNDMAKER_HPP
#define ROUNDMAKER_HPP
#include <iostream>

#include "Round.hpp"
#include "Timer.hpp"


class RoundMaker
{
private:
    Phrase &phrase;
    Timer timer;
public:
    RoundMaker(Phrase &phrase);

    Round makeRound(Player &actingPlayer);
};
#endif