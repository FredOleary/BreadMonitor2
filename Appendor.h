#pragma once
#include <iostream>

class Appendor {
public:
	virtual void open() {};
	virtual void close() {};

	virtual ~Appendor() {};
	virtual void error(std::string name) = 0;
	virtual void warning(std::string name) = 0;
	virtual void info(std::string name) = 0;
};

