#include <iostream>
#include <ctime>
#include "logger.h"
#include "utility.h"


void Logger::error(std::string message) {
	std::string logMessage = makeMessage(message, "ConsoleLogger::error ");
	for (auto it = appendors.begin(); it != appendors.end(); ++it) {
		(*it)->error(logMessage);
	}

}
void Logger::warning(std::string message) {
	std::string logMessage = makeMessage(message, "ConsoleLogger::warning ");
	for (auto it = appendors.begin(); it != appendors.end(); ++it) {
		(*it)->warning(logMessage);
	}
}
void Logger::info(std::string message) {
	std::string logMessage = makeMessage(message, "ConsoleLogger::info ");
	for (auto it = appendors.begin(); it != appendors.end(); ++it) {
		(*it)->info(logMessage);
	}
}

void Logger::addAppendor(Appendor* appendor)
{
	appendors.push_back(appendor);
}

std::string Logger::makeMessage(std::string message, std::string messageType) {
	std::time_t nowTime = std::time(nullptr);
	std::string logMessage = stripTimeLinefeed(std::asctime(std::localtime(&nowTime))) + messageType + message;
	return logMessage;
}
