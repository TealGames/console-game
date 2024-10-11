#include <string>
#include "HelperFunctions.h"

std::string trim(const std::string& str)
{
	std::string::const_iterator startIt = str.begin();
	std::string::const_iterator endIt = str.end();

	int start = 0;
	int end = str.length();
	for (auto it = startIt; it != endIt; it++)
	{
		if (!std::isspace(*it)) break;
		else start++;
	}

	for (auto it = endIt - 1; it != startIt; it--)
	{
		if (!std::isspace(*it)) break;
		else end--;
	}

	return str.substr(start, end);
}

std::string to_lowercase(std::string& str) 
{
	std::string result;
	for (auto& c : str) 
	{
		result += (char)tolower(c);
	}
	return result;
}