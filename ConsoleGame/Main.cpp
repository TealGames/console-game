#include <iostream>
#include <format>
#include <conio.h>
#include <string>
#include "HelperFunctions.h";

std::string format_input(std::string str);

int main()
{  
	std::cout << "Welcome to Chess!\n";
	std::string str = "   hello ";
	std::cout << trim(str);
}
