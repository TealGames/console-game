#include <iostream>
#include <unordered_set>
#include <string>
#include <array>
#include "HelperFunctions.hpp"
#include "GameOption.hpp"

int main()
{
	// const GameOption options[3] = {GameOption("Play"), GameOption("Restart"), GameOption("Quit")};
	// GameOption play("Play");

	std::cout << "Welcome to Chess!\n";
	std::cout << "What would you like to do?";

	std::string str = "Hello";
	GameOption::IsValidCommand(str);
	GameOption var("thing");
	var.GetCommand();
	std::unordered_set<std::string> allCommands = GameOption::GetAllCommands();
	//  std::array<std::string, 3> arr = { "", "", "" };
	//  auto it = allCommands.begin();
	//  for (int i = 0; i < allCommands.size(); i++) {
	//	arr.at(i) = *it;
	//	std::advance(it, 1);
	//  }
	Utils::Log(Utils::LogType::Log, Utils::ToStringIterable(allCommands));
}
