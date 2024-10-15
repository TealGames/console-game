#pragma once
#include <string>
#include <sstream>
#include <iostream>

namespace Utils
{
	/// <summary>
	/// A more versatile version of to_string meant to handle not just numbers
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	template <typename T>
	std::string ToString(const T &obj)
	{
		std::ostringstream oss;
		oss << obj;
		return oss.str();
	}

	enum class LogType
	{
		Error,
		Warning,
		Log,
	};

	void Log(const LogType& logType, const std::string& str);

	template <typename T>
	void Log(const LogType &logType, const T &obj)
	{
		std::string objAsStr = Utils::ToString(obj);
		Log(logType, objAsStr);
	}

	template <typename T>
	std::string ToStringIterable(const T &collection)
	{
		std::string str = "[";
		int index = 0;
		for (const auto &element : collection)
		{
			str += Utils::ToString(element);
			if (index < collection.size() - 1)
				str += ", ";
			index++;
		}
		str += "]";
		return str;
	}

	double ToRadians(const double);
	double ToDegrees(const double);
	bool ApproximateEquals(double, double);
}
