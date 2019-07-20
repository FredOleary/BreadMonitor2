#include <unistd.h>
#include <iostream>
#include <ctime>
#include "configuration.h"
	
Configuration::Configuration(){
	startTime = std::time(nullptr);
	endTime = std::time(nullptr);
	durationInHours = 12; // 12 hour duration
	endTime += (durationInHours*60*60);	
	name = "Batch";
	serverURL = "http://192.168.50.5:3000/";
	recipePtr = nullptr;

	// Read the recipe file
	try {
		// Config file 'recipe.txt' should be in same directory as executable.
		std::ifstream recipe("recipe.txt", std::ifstream::in);
		if (recipe.good()) {
			recipePtr = JsonWrapper::Create(recipe);

		}
	}catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

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
JsonWrapper* Configuration::getRecipe() const {
	return recipePtr;
}
void Configuration::setName( std::string newName ){
	name = newName;
}

void Configuration::setDuration( int durationInHoursIn ){
	durationInHours = durationInHoursIn;
	endTime = startTime + (durationInHours*60*60);
}

void Configuration::setServerURL(std::string serverURLIn)
{
	std::cout << serverURLIn << std::endl;
	serverURL = serverURLIn;
}

