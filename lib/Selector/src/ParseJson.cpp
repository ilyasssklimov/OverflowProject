#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include "ParseJson.h"

std::vector<int> ParseJson::parse_json(std::string json){
    rapidjson::Document d;

    d.Parse(json.c_str());
	size_t size = 0;
	rapidjson::Value elemenst;
	
	if(!d.HasMember("rows")) return {};
	elemenst = d["rows"];
	size = elemenst.Size();
		
	std::vector<int> result;
	for(size_t i = 0; i < size; i++){
		if(elemenst.Size() <= i) return {};
		if(!elemenst[i].HasMember("elements")) return {};
		if(!elemenst[i]["elements"].IsArray()) return {};
		if(!elemenst[i]["elements"][0].HasMember("duration")) return {};
		if(!elemenst[i]["elements"][0]["duration"].HasMember("value")) return {};
		result.push_back(elemenst[i]["elements"][0]["duration"]["value"].GetInt());
	}
    return result;
}
