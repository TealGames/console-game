#include <string>
#include <array>
#include "HelperFunctions.hpp"

namespace Utils
{
	void Log(const LogType& logType, const std::string& str)
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
			std::string errMessage = "Tried to log message of message type "
				"that is not defined: ";
			Log(LogType::Error, errMessage);
			return;
		}
		std::cout << "\nLOG: " << str << std::endl;
	}
}
