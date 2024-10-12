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
	std::string ToString(const T& obj) 
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

	void Log(const LogType logType, const std::string& str) 
	{
		std::string logTypeMessage;
		switch (logType) 
		{
			case LogType::Error:
				logTypeMessage = "ERROR";
				break;
			case LogType::Warning:
				logTypeMessage = "WARNING";
				break;
			case LogType::Log:
				logTypeMessage = "LOG";
				break;
			default:
				std::string errMessage = std::format("Tried to log message of message type "
					"that is not defined: {}", logType);
				Log(LogType::Error, errMessage);
				return;
		}
		std::cout << "LOG: " << str << std::endl;
	}

	template<typename T>
	void Log(const T& obj)
	{
		std::string objAsStr = Utils::ToString(obj);
		Log(objAsStr);
	}

	template <typename T>
	std::string ToStringIterable(const T& collection)
	{
		std::string str;
		int index = 0;
		for (const auto& element : collection)
		{
			str += Utils::ToString(element);
			if (index < collection.size() - 1) str += "\n";
			index++;
		}
		return str;
	}
}

