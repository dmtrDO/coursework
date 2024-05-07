#include "Statistics.hpp"


class Statistics
{
private:
    std::vector<Round> rounds;
    std::vector<Player> &players;
public:
    Statistics(std::vector<Player> &_players)
    : players(_players) {}

    void reset()
    {
        rounds.clear();
    }
    void addRound(const Round& round)
    {
        rounds.push_back(round);
    }
    std::vector<std::pair<int, Player&>> getPlaces(std::vector<Player> &players)
    {
        std::vector<std::pair<int, Player&>> rankedPlayers;

        std::vector<Player&> sortedPlayers(players.size());
        std::transform(players.begin(), players.end(), sortedPlayers.begin(),
            [](Player& p)
            {
                return &p;
            });
        std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](Player& a, Player& b)
        {
            return a.getScore() > b.getScore();
        });

        int rank = 1;
        int prevScore = sortedPlayers[0].getScore();
        for (Player& player : sortedPlayers)
        {
            if (player.getScore() < prevScore)
            {
                rank += 1;
                prevScore = player.getScore();
            }
            rankedPlayers.emplace_back(rank, player);
        }

        return rankedPlayers;
    }
    std::string getView()
    {
        std::vector<std::pair<int, Player&>> places = getPlaces(players);

        std::string view = std::string(5, '-') + " Results " + std::string(10, '-') + "\n";
        for (int i = 0; i < rounds.size(); i++)
        {
            view += std::string(2, '-') + " Round " + std::to_string(i + 1) + " " + std::string(5, '-') + "\n";
            view += rounds[i].getView() + "\n";
        }

        view += std::string(5, '-') + " Ratings " + std::string(10, '-') + "\n";
        for (int i = 0; i < places.size(); i++)
        {
            view += std::to_string(places[i].first) + ". " + places[i].second.getView();
            if (i != places.size() - 1)
            {
                view += "\n";
            }
        }
    }
};