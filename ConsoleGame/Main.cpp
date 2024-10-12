#include <iostream>
#include <format>
#include <conio.h>
#include <string>
#include <array>
#include "HelperFunctions.h"
#include "GameOption.h"

int main()
{
	GameOption("Play"), GameOption("Restart"), GameOption("Quit");

	std::cout << "Welcome to Chess!\n";
	std::cout << "What would you like to do?";
	std::unordered_set<std::string> allCommands = GameOption::GetAllCommands();
	//std::array<std::string, 3> arr = { "", "", "" };
	//auto it = allCommands.begin();
	//for (int i = 0; i < allCommands.size(); i++) {
	//	arr.at(i) = *it;
	//	std::advance(it, 1);
	//}
	Utils::Log(Utils::ToStringIterable(allCommands));
}
