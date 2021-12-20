#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "SelectorException.h"
#include "JsonParser.h"

std::vector<int> JsonParser::parse_json(const std::string& json){
	rapidjson::Document d;

    d.Parse(json.c_str());
	size_t size = 0;
	rapidjson::Value elemenst;
	
	if(!d.HasMember("rows")) {
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
		return {};
	}
	elemenst = d["rows"];
	size = elemenst.Size();
		
	std::vector<int> result;
	for(size_t i = 0; i < size; i++){
		using rapidjson::Value;

		if(elemenst.Size() <= i) return {};
		if(!elemenst[i].HasMember("elements")) return {};
		const Value & array = elemenst[i]["elements"];

		if(!array.IsArray()) return {};
		if(!array[0].HasMember("duration")) return {};
		const Value &duration = array["duration"];

		if(!duration.HasMember("value")) return {};
		result.push_back(duration["value"].GetInt());
	}
    return result;
}
