#include <iostream>
#include "GameOption.h"
#include "HelperFunctions.h"
#include "StringUtil.h"

std::unordered_set<std::string> GameOption::_allOptions;

GameOption::GameOption(const std::string& opt) : 
	_option(opt), option(_option) 
{
	if (GameOption::_allOptions.find(option) != _allOptions.end()) 
	{
		GameOption::_allOptions.insert(option);
	}
	else
	{
		std::cerr << "ERROR: tried to create duplicate game option named " << opt;
	}
}

GameOption::~GameOption()
{
	auto it = _allOptions.find(option);
	if (it!=_allOptions.end())
	{
		GameOption::_allOptions.erase(it);
	}
}

std::string& GameOption::GetCommand(const GameOption& option, bool convertToLower=false)
{
	std::string command(1, option._option[0]);
	if (convertToLower) {
		Utils::StringUtil strUtil(command);
		command = static_cast<std::string>(strUtil.to_lower_case());
	}
	return command;
}

std::string& GameOption::GetCommand(bool convertToLower = false) const
{
	return GetCommand(*this, convertToLower);
}

std::unordered_set<std::string> GameOption::GetAllCommands()
{
	return GameOption::_allOptions;
}

bool GameOption::IsValidCommand(std::string& command, bool caseSensitive=false)
{
	Utils::StringUtil strUtil(command);
	std::string& commandCheck= (std::string&)(strUtil.trim().to_lower_case());

	for (const std::string& str : GameOption::_allOptions)
	{
		const std::string& optionCommand = GetCommand(str);
		if (optionCommand == commandCheck) return true;
	}
	return false;
}