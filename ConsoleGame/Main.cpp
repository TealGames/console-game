#include <iostream>
#include <format>
#include <conio.h>
#include <string>
#include "HelperFunctions.h"
#include "GameOption.h"

std::string format_input(std::string);

std::string get_command_from_option(const GameOption&);
GameOption& option_from_input(std::string);

int main()
{  
	std::cout << "Welcome to Chess!\n";
	std::cout << "What would you like to do?";
	//GameOption& option= option_from_input;
}

std::string get_command_from_option(const GameOption& option) 
{
	return std::to_string(option);
}

std::string format_input(std::string str) 
{

}
