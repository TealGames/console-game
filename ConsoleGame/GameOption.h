#pragma once
#include <string>
#include <vector>
#include <unordered_set>

class GameOption 
{
private:
	std::string _option;
	static std::unordered_set<std::string> _allOptions;

public:
	const std::string& option;

	GameOption(const std::string& opt);
	~GameOption();

	static std::string& GetCommand(const GameOption&, bool);
	std::string& GetCommand(bool) const;
	static std::unordered_set<std::string> GetAllCommands();
	
	static bool IsValidCommand(std::string&, bool);
};