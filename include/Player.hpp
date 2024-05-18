#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>


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
    char askLetter() const;
    void addScore();
    std::string getName() const;
    int getAge() const;
    int getScore() const;
    std::string toString() const;
};
#endif