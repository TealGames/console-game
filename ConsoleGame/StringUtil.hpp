#pragma once
#include <string>

namespace Utils {
	class StringUtil {
	private:
		std::string str;
	public:
		StringUtil(std::string&);
		StringUtil& trim();
		StringUtil& to_lower_case();

		explicit operator std::string() const;
	};
}