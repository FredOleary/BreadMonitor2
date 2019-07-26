#pragma once
#include <vector>
#include "Ilogger.h"
#include "Appendor.h"

class Logger : Ilogger {
public:
	virtual ~Logger() {};
	virtual void error(std::string name) = 0;
	virtual void warning(std::string name) = 0;
	virtual void info(std::string name) = 0;

	void addAppendor(Appendor* appendor);

private:
	std::string makeMessage(std::string message, std::string messageType);



	std::vector<Appendor*> appendors;

};

