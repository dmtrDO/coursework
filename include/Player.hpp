#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <cctype>


#define MAX_NAME_SIZE 40


class Player
{
private:
    std::string name;
    int age;
    int score;
public:
    Player();

    void askName();
    void askAge();
    void addScore();
    std::string getName() const;
    int getAge() const;
    int getScore() const;
    std::string toString() const;
};
#endif