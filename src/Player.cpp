#include "Player.hpp"


Player::Player()
{
	name = "Unknown";
	score = 0;
	age = 0;
}
void Player::askName()
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
void Player::askAge()
{
	std::string input;
	bool mark = true;
	while (mark)
	{
		mark = false;
		std::cout << "Enter age: ";
		getline(std::cin, input);
		if (input.empty() || input.size() > 3 || input.find_first_not_of("0123456789") != std::string::npos || input.front() == '0' || stoi(input) > 130)
		{
			if (input.empty())
			{
				std::cout << "Error: You have entered an empty value.\n";
			}
			else if (input.size() > 3)
			{
				std::cout << "Error: You have entered a value that is too large.\n";
			}
			else if (input.find_first_not_of("0123456789") != std::string::npos)
			{
				std::cout << "Error: You have entered a non-numeric value or a value that is less than zero.\n";
			}
			else if (input[0] == '0')
			{
				std::cout << "Error: Zero can't be at the beginning.\n";
			}
			else
			{
				std::cout << "Error: You probably not a human. Maybe you meant " << input.substr(0, 2) << " ?\n";
			}
			mark = true;
		}
	}
	age = stoi(input);
}
void Player::addScore()
{
	this->score += 1;
}
int Player::getAge() const
{
	return age;
}
std::string Player::getName() const
{
	return name;
}
int Player::getScore() const
{
	return score;
}
std::string Player::toString() const
{
	return name + ", " + std::to_string(age) + "y.o., score: " + std::to_string(score);
}