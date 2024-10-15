#include <string>
#include <array>
#include <format>
#include <numbers>
#include <cmath>
#include <limits>
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
		std::cout << "\n"+logTypeMessage+": " << str << std::endl;
	}

	double ToRadians(const double deg)
	{
		return deg* (std::numbers::pi/180.0);
	}

	double ToDegrees(const double rad)
	{
		return rad * (180.0 / std::numbers::pi);
	}

	/// <summary>
	/// To handle approximate equivalence between floating numbers
	/// </summary>
	/// <param name="d1"></param>
	/// <param name="d2"></param>
	/// <returns></returns>
	bool ApproximateEquals(double d1, double d2)
	{
		double diff = std::fabs(d2- d1);
		return diff < std::numeric_limits<double>().epsilon();
	}
}
