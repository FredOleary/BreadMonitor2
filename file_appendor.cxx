#include <iostream>
#include <ctime>
#include "file_appendor.h"
#include "utility.h"

void FileAppendor::open(std::string name) {
	fileStream.open(name);
};
void FileAppendor::close() {
	fileStream.close();
};


void FileAppendor::error(std::string message) {
	fileStream << message << std::endl;
}
void FileAppendor::warning(std::string message) {
	fileStream << message << std::endl;;
}
void FileAppendor::info(std::string message) {
	fileStream << message << std::endl;
}

