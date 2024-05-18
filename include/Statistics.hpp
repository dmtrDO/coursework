#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <vector>
#include <algorithm>
#include <utility>

#include "Round.hpp"


class Statistics
{
private:
    std::vector<Round> rounds;
    std::vector<Player> &players;
public:
    Statistics(std::vector<Player> &_players);

    void reset();
    void addRound(const Round& round);
    std::vector<std::pair<int, Player>> getPlaces();
    std::string toString();
};
#endif