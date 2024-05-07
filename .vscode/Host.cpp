#include <iostream>
#include <string>

class Host {
private:
    std::string name;

public:
    Host(std::string n) : name(n) {}

    std::string getName() const {
        return name;
    }

    void askName(std::string n) {
        name = n;
    }

    int askNumberOfPlayer() {
        int numberOfPlayer;
        do {
            std::cout << "Введіть кількість гравців (від 1 до 4): ";
            std::cin >> numberOfPlayer;
        } while (numberOfPlayer < 1 || numberOfPlayer > 4);
        return numberOfPlayer;
    }


    bool askRestart() {
        bool restartGame;
        char choice;
        do {
            std::cout << "Чи бажаєте ви завершити гру? (y/n): ";
            std::cin >> choice;
        } while (choice != 'y' && choice != 'n');
        restartGame = (choice == 'n') ? true : false;
        return restartGame;
    }

    int askIfPhraseFromFile() {
        int gameMode;
        do {
            std::cout << "Хто буде загадувати слово: Хост (введіть 1) або комп'ютер (введіть 2): ";
            std::cin >> gameMode;
        } while (gameMode != 1 && gameMode != 2);
        return gameMode;
    }
    
    void askPhrase(Phrase &phrase) {
        string temp;
        do{
        std::cout << "Введіть фразу: ";
        std::cin >> temp;
        } while(!phrase.setPhrase(temp));
    }   

};

int main() {
    Host host("Host");

    std::cout << "Ім'я господаря: " << host.getName() << std::endl;

    int players = host.askNumberOfPlayer();
    std::cout << "Кількість гравців: " << players << std::endl;

    bool continueGame = host.askRestart();
    if (!continueGame) {
        std::cout << "Гра завершилась." << std::endl;
    } else {
        std::cout << "Гра продовжується." << std::endl;
    }

    int mode = host.askIfPhraseFromFile();
    if (mode == 1) {
        std::cout << "Слово буде загадувати Хост." << std::endl;
    } else {
        std::cout << "Слово буде загадувати комп'ютер." << std::endl;
    }

    return 0;
}
