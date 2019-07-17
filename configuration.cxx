#include <unistd.h>
#include <iostream>
#include <ctime>
#include "configuration.h"
#include "json_wrapper.h"
	
Configuration::Configuration(){
	startTime = std::time(nullptr);
	endTime = std::time(nullptr);
	durationInHours = 12; // 12 hour duration
	endTime += (durationInHours*60*60);	
	name = "Batch";
	serverURL = "http://192.168.50.5:3000/";

	// Read the recipe file
#ifndef foo
	try {
		// Config file 'recipe.txt' should be in same directory as executable.
		std::ifstream recipe("recipe.txt", std::ifstream::in);
		if (recipe.good()) {
			JsonWrapper* recipePtr = JsonWrapper::Create(recipe);

		}
	}catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
#endif
}

std::time_t Configuration::getStartTime() const {
	return startTime;
}
std::time_t Configuration::getEndTime() const{
	return endTime;
}
std::string Configuration::getName() const{
	return name;
}
std::string Configuration::getServerURL() const{
	return serverURL;
}
void Configuration::setName( std::string newName ){
	name = newName;
}

void Configuration::setDuration( int durationInHoursIn ){
	durationInHours = durationInHoursIn;
	endTime = startTime + (durationInHours*60*60);
}
