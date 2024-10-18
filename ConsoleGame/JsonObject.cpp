#include <string>
#include <algorithm>
#include "JsonObject.hpp"
#include "HelperFunctions.hpp"
#include "StringUtil.hpp"

namespace Utils
{
	JsonObject::JsonObject() : _propertyName(""), _propertyValue(0),
		PROPERTY_NAME(_propertyName) {}

	JsonObject::JsonObject(const std::string& propertyName, const int val)
		: _propertyName(propertyName), _propertyValue(val), PROPERTY_NAME(propertyName) {}

	JsonObject::JsonObject(const std::string& propertyName, const double val)
		: _propertyName(propertyName), _propertyValue(val), PROPERTY_NAME(propertyName) {}

	JsonObject::JsonObject(const std::string& propertyName, const std::string& val)
		: _propertyName(propertyName), _propertyValue(val), PROPERTY_NAME(propertyName) {}

	JsonObject::JsonObject(const std::string& propertyName, const Utils::JsonObject& val)
		: _propertyName(propertyName), _propertyValue(nullptr), PROPERTY_NAME(propertyName) {}


	JsonObject& JsonObject::ParseJson(const std::string& json)
	{
		std::string transformed = Utils::StringUtil(json).trim().ToString();
		transformed = transformed.replace(transformed.begin(), transformed.end(), " ", "");
	}

	const std::optional<int> JsonObject::TryGetInt()
	{
		return TryGetType<int>();
	}

	const std::optional<double> JsonObject::TryGetDouble()
	{
		return TryGetType<double>();
	}

	const std::optional<std::string> JsonObject::TryGetString()
	{
		return TryGetType<std::string>();
	}

	const std::optional<JsonObject&> JsonObject::TryGetObject()
	{
		return TryGetType<JsonObject&>();
	}
}