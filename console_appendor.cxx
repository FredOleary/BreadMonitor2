#include <iostream>
#include <ctime>
#include "console_appendor.h"
#include "utility.h"

void ConsoleAppendor::error(std::string message){
	std::cerr << message << std::endl;
}
void ConsoleAppendor::warning(std::string message){
	std::cerr << message << std::endl;;
}
void ConsoleAppendor::info(std::string message){
	std::cout << message << std::endl;
}

