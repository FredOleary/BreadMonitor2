#include <iostream>
#include "Appendor.h"

class ConsoleAppendor : public Appendor {
	public:
		void open(std::string name) {};
		void close() {};
		void error(std::string message);
		void warning(std::string message);
		void info(std::string message);
};
