#include "Statistics.hpp"


Statistics::Statistics(std::vector<Player> &_players)
: players(_players) {}

void Statistics::reset()
{
    rounds.clear();
}
void Statistics::addRound(const Round& round)
{
    rounds.push_back(round);
}
std::vector<std::pair<int, Player>> Statistics::getPlaces()
{
    std::vector<std::pair<int, Player>> rankedPlayers;

    std::vector<Player*> sortedPlayers(players.size());
    std::transform(players.begin(), players.end(), sortedPlayers.begin(),
        [](Player& p)
        {
            return &p;
        });
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player* a, Player* b)
    {
        return a->getScore() > b->getScore();
    });

    int rank = 1;
    int prevScore = sortedPlayers[0]->getScore();
    for (Player* player : sortedPlayers)
    {
        if (player->getScore() < prevScore)
        {
            rank += 1;
            prevScore = player->getScore();
        }
        rankedPlayers.emplace_back(rank, *player);
    }

    return rankedPlayers;
}
std::string Statistics::toString()
{
    std::vector<std::pair<int, Player>> places = getPlaces();
    double totalTimeSpent = 0;

    std::string view = '\n' + std::string(15, '-') + " Results " + std::string(15, '-') + "\n";
    for (size_t i = 0; i < rounds.size(); i++)
    {
        view += '\n';
        view += std::string(15, '-') + " Round " + std::to_string(i + 1) + " " + std::string(15, '-') + "\n";
        view += rounds[i].toString() + "\n";
        totalTimeSpent += rounds[i].getTimeSpent();
    }

    std::stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(2);
    sstream << totalTimeSpent;
    view += '\n';
    view += std::string(5, '-') + " Game lasted for " + sstream.str() + " seconds " + std::string(5, '-') + "\n";
    view += std::string(15, '-') + " Ratings " + std::string(15, '-') + "\n";
    for (size_t i = 0; i < places.size(); i++)
    {
        view += std::to_string(places[i].first) + ". " + places[i].second.toString();
        if (i != places.size() - 1)
        {
            view += "\n";
        }
    }

    return view;
}