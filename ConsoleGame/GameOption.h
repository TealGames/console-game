#pragma once
#include <string>

class GameOption 
{
private:
	std::string option;

public:
	const std::string Options[3];
	const std::string& Option;

	GameOption(const std::string& opt);

	std::string get_command();
	bool is_valid_command();
};