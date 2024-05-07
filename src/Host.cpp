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
        std::cout << "Хто буде загадувати слово: Хост (введіть 1) або комп'ютер (введіть 2): ";
        std::cin >> gameMode;
    } while (gameMode != 1 && gameMode != 2);
    return (gameMode - 1);
}
void Host::askPhrase(Phrase &phrase)
{
    std::string temp;
    do
    {
        std::cout << "Введіть фразу: ";
        std::getline(std::cin, temp);
    } while(!phrase.setPhrase(temp));
}
int Host::askNumberOfPlayers() 
{
    int numberOfPlayer;
    do
    {
        std::cout << "Введіть кількість гравців (від 1 до 4): ";
        std::cin >> numberOfPlayer;
    } while (numberOfPlayer < 1 || numberOfPlayer > 4);
    return numberOfPlayer;
}
bool Host::askRestart()
{
    bool restartGame;
    char choice;
    do
    {
        std::cout << "Чи бажаєте ви завершити гру? (y/n): ";
        std::cin >> choice;
    } while (choice != 'y' && choice != 'n');
    restartGame = (choice == 'n') ? true : false;
    return restartGame;
}
std::string Host::getName() const
{
    return name;
}