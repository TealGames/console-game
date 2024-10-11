#include "GameOption.h"
#include <iostream>

GameOption::GameOption(const std::string& opt) : 
	Options{"Play", "Restart", "Quit"},
	option(opt), Option(option) {}

bool GameOption::is_valid_command(std::string& command)
{
	command= command.lowwer
}