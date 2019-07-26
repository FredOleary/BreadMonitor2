
#pragma once
#include <vector>
#include "reading.h"
#include "new_logger.h"

class Observer{
	public:
	virtual ~Observer() {};
	virtual bool open(std::string name) = 0;
	virtual void close() const = 0;
	virtual void update(std::vector<ReadingPtr>) = 0;
};
