#include "StringUtil.hpp"

namespace Utils
{
	StringUtil::StringUtil(std::string &s) : str(s) {}

	StringUtil &StringUtil::trim()
	{
		std::string::const_iterator startIt = str.begin();
		std::string::const_iterator endIt = str.end();

		int start = 0;
		int end = str.length();
		for (auto it = startIt; it != endIt; it++)
		{
			if (!std::isspace(*it))
				break;
			else
				start++;
		}

		for (auto it = endIt - 1; it != startIt; it--)
		{
			if (!std::isspace(*it))
				break;
			else
				end--;
		}

		str = str.substr(start, end);
		return *this;
	}

	StringUtil &StringUtil::to_lower_case()
	{
		std::string result;
		for (auto &c : str)
		{
			result += (char)tolower(c);
		}
		str = result;
		return *this;
	}

	StringUtil::operator std::string() const
	{
		return str;
	}
}