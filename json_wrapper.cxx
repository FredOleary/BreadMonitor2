#include "json_wrapper.h"
#include "third_party/json.hpp"

class JsonWrapperImpl : public JsonWrapper {
	private:
		nlohmann::json jsonInst;
	public:
		JsonWrapperImpl(){ }
		~JsonWrapperImpl(){
		}
		JsonWrapperImpl(std::ifstream& file) {
			jsonInst = nlohmann::json::parse(file);
		}


		JsonWrapperImpl( std::string jsonString ){
			jsonInst = nlohmann::json::parse(jsonString.c_str());
		}
		void addStringMember( std::string key, std::string value){
			jsonInst[key.c_str()] = value;
		}
		void addDoubleMember( std::string key, double value){
			jsonInst[key.c_str()] = value;
		}
		void addIntMember( std::string key, int value){
			jsonInst[key.c_str()] = value;
		}

		void addObjectMember(std::string key, JsonWrapper* jsonObjectPtr) {
			jsonInst[key.c_str()] = (static_cast<JsonWrapperImpl*>(jsonObjectPtr))->jsonInst;
		}

		std::string getJsonString(){
			return jsonInst.dump();
		}

		int getIntValue( std::string key ){			
			return jsonInst[key.c_str()].get<int>();	
		}

};


JsonWrapper::JsonWrapper(){
		
};
JsonWrapper::~JsonWrapper(){
		
};



JsonWrapper* JsonWrapper::Create(){
	return new JsonWrapperImpl();

}
	
JsonWrapper* JsonWrapper::Create(std::string jsonString){
	return new JsonWrapperImpl(jsonString);
}

JsonWrapper* JsonWrapper::Create(std::ifstream& file)
{
	//return nullptr;
	return new JsonWrapperImpl(file);
}

