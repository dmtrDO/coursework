#include "Host.hpp"



void Host::askName()
{
    std::string input;
    bool mark = true;
    while (mark)
    {
        mark = false;
        std::cout << "Enter name: ";
        getline(std::cin, input);
        if (input.empty() || input.size() == 1 || input.size() > MAX_NAME_SIZE)
        {
            if (input.empty())
            {
                std::cout << "Error: You have entered an empty value.\n";
            }
            else if (input.size() == 1)
            {
                std::cout << "Error: The name cannot consist of a single character\n";
            }
            else
            {
                std::cout << "Error: You have entered a value that is too large.\n";
            }
            mark = true;
        }
        else
        {
            for (size_t i = 0; i < input.size(); i++)
            {
                if (!isalpha(input[i])) 
                {
                    std::cout << "Error: All characters must be alphabetical.\n";
                    mark = true;
                    break;
                }
            }
        }
    }
    input[0] = toupper(input[0]);
    for (size_t i = 1; i < input.size(); i++)
    {
        input[i] = tolower(input[i]);
    }
    name = input;
}
bool Host::askIfPhraseFromFile()
{
    int gameMode;
    do
    {
        std::cout << "Who will provide the word: Host (enter 1) or computer (enter 2): ";
        std::cin >> gameMode;
        std::cin.ignore();
        if (std::cin.fail())
        { 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue; 
        }
        if (gameMode != 1 && gameMode != 2)
        { 
            std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
        }
    } while (gameMode != 1 && gameMode != 2);
    return (bool)(gameMode - 1);
}

void Host::askPhrase(Phrase &phrase)
{
    std::string temp;
    std::cout << "Rule: only spaces and alphabetic characters are allowed (10 - 40 letters)\n";
    std::cout << "Enter phrase: ";
    std::getline(std::cin, temp);
    if(!phrase.setPhrase(temp)){
        do
        {
            std::cout << "Review the rules and enter the correct phrase: ";
            std::getline(std::cin, temp);   
        } while(!phrase.setPhrase(temp));
    }
}

int Host::askNumberOfPlayers()
{
    int numberOfPlayers;
    do
    {
        std::cout << "Please input the number of players (1 to 4): ";
        std::cin >> numberOfPlayers;
        std::cin.ignore();
        if (std::cin.fail()) { 
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        if (numberOfPlayers < 1 || numberOfPlayers > 4) { 
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
        }
    } while (numberOfPlayers < 1 || numberOfPlayers > 4);
    return numberOfPlayers;
}

bool Host::askRestart()
{
    bool restartGame;
    char choice;
    do
    {
        std::cout << "Do you want to restart the game? (y/n): ";
        std::cin >> choice;
        if (std::cin.fail())
        { 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid input. Please enter a character." << std::endl;
            continue; 
        }
        if (choice != 'y' && choice != 'n')
        { 
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
        std::cin.ignore(10000, '\n'); 
    } while (choice != 'y' && choice != 'n');
    restartGame = (choice == 'n') ? false : true; 
    return restartGame;
}

std::string Host::getName() const
{
    return name;
}