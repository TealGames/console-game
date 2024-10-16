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

	template <typename T1, typename T2>
	bool IterableHas(const T1& collection, const T2& findElement)
	{
		if (T1.size() <= 0) return false;

		for (const auto& element : collection)
		{
			if (&element == &findElement || element == findElement)
			{
				return true;
			}
		}
		return false;
	}

	double ToRadians(const double);
	double ToDegrees(const double);
	bool ApproximateEquals(double, double);

	bool IsInifinity(double);
	bool IsNegInifinity(double);
}
