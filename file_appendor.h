#pragma once
#include <iostream>
#include <iostream>
#include <fstream>
#include <memory>
#include "Appendor.h"

class FileAppendor : public Appendor {
public:
	void open(std::string name);
	void close();
	void error(std::string message);
	void warning(std::string message);
	void info(std::string message);

private:
	std::ofstream fileStream; 

};
