#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include "ParseJson.h"


std::vector<int> ParseJson::parse_json(std::string json){
    rapidjson::Document d;

    d.Parse(json.c_str());
	int size = 0;
	rapidjson::Value elemenst;
	try{
		elemenst = d["rows"];
		size = elemenst.Size();
	}
	catch(...){
		std::cout << "Wrong JSON\n";
	}
	std::vector<int> result;
	try{
		for(int i = 0; i < size; i++){
			result.push_back(elemenst[i]["elements"][0]["duration"]["value"].GetInt());
		}
	}
	catch(...){
		std::cout << "Wrong Index\n";
	}
    return result;
}
