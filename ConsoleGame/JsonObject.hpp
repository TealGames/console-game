#pragma once
#include <string>
#include <variant>
#include <any>
#include <optional>
#include <iostream>
#include "HelperFunctions.hpp"

namespace Utils
{
	class JsonObject
	{
	private:
		std::string _propertyName;
		std::any _propertyValue;

		template<typename T>
		T GetType()
		{
			T val = {};
			try
			{
				val{ std::any_cast<T>(_propertyValue) };
			}
			catch (const std::bad_any_cast e)
			{
				return {};
			}
			return val;
		}

		template<typename T>
		bool HasType()
		{
			try 
			{
				T val{std::any_cast<T>(_propertyValue)};
			}
			catch (const std::bad_any_cast e)
			{
				return false;
			}
			return false;
		}

		static JsonObject& ParseJson(const std::string& json);

	public:
		const std::string& PROPERTY_NAME;

		JsonObject();
		JsonObject(const std::string& propertyName, const int val);
		JsonObject(const std::string& propertyName, const double val);
		JsonObject(const std::string& propertyName, const std::string& val);
		JsonObject(const std::string& propertyName, const JsonObject& val);

		template<typename T>
		const std::optional<T> TryGetType()
		{
			if (HasType<T>()) return std::optional<T>(GetType<T>());
			else return std::nullopt;
		}

		const std::optional<int> TryGetInt();
		const std::optional<double> TryGetDouble();
		const std::optional<std::string> TryGetString();
		const std::optional<JsonObject&> TryGetObject();
	};
}