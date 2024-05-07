#ifndef HOST_HPP
#define HOST_HPP
#include <iostream>

#include "Phrase.hpp"


#define MAX_NAME_SIZE 40


class Host
{
private:
    std::string name;
public:
    void askName();
    bool askIfPhraseFromFile();
    void askPhrase(Phrase &phrase);
    int askNumberOfPlayers();
    bool askRestart();
    std::string getName() const;
};
#endif