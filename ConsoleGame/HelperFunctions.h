#pragma once
#include <string>
#include <iostream>

namespace Utils 
{
	/*template <typename T, size_t N>
	std::string ToStringArray(const std::array<T, N>&);*/
	template <typename T, size_t N>
	std::string ToStringArray(const std::array<T, N>& arr)
	{
		std::string str;
		for (int i = 0; i < arr.size(); i++)
		{
			//str += std::to_string(arr[i]);
			std::cout << "type for arr is" << to_string(typeid(arr[i]));
			//if (i < arr.size() - 1) str += "\n";
		}
		return str;
	}

	/*template <typename T>
	std::string ToStringIterable(const T&);*/
	template <typename T>
	std::string ToStringIterable(const T& collection)
	{
		std::string str;
		for (int i = 0; i < collection.size(); i++)
		{
			str += std::to_string(collection[i]);
			if (i < collection.size() - 1) str += "\n";
		}
		return str;
	}
}

