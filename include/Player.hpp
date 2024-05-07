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
    void setScore(int score);
    std::string getName() const;
    int getAge() const;
    int getScore() const;
    std::string getView() const;
};
#endif