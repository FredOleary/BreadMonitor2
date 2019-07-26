#pragma once
#include <vector>
#include "Appendor.h"

class ILogger{
	public:
	virtual ~ILogger(){};
	virtual void error(std::string name) = 0;
	virtual void warning(std::string name) = 0;
	virtual void info(std::string name) = 0;


};

