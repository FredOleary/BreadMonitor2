#pragma once
#include <vector>
#include "Ilogger.h"
#include "Appendor.h"

class Logger : public ILogger {
public:
	void error(std::string name);
	void warning(std::string name);
	void info(std::string name);

	void addAppendor(Appendor* appendor);

private:
	std::string makeMessage(std::string message, std::string messageType);
	std::vector<Appendor*> appendors;

};

