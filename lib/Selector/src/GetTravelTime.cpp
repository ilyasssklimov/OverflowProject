#include <curl/curl.h>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

#include "GetTravelTime.h"
#include "ParseJson.h"


#define API_KEY "AIzaSyCYs2rbbVWwrEe6LBLcpnLuykpFUSJBUKk"


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string GetTravelTime::get_encoded_request(CURL *curl, std::vector<std::string> origins, std::string dest){

	std::string enc_dest = curl_easy_escape(curl, dest.c_str(), dest.length());
    std::string enc_request_string =  "?destinations=" + enc_dest;

	std::string enc_origins;

	for(std::string origin : origins) {
		enc_origins +=  origin + "|";
	}
	enc_origins.pop_back();
	enc_origins = curl_easy_escape(curl, enc_origins.c_str(), enc_origins.length());
	enc_request_string += "&origins=" + enc_origins;
	
	enc_request_string += "&key=";
	enc_request_string += API_KEY;

	return enc_request_string;
}

std::string GetTravelTime::send_request(std::vector<std::string> origins, std::string dest){
	CURLcode res;
	std::string json;
	CURL* curl = curl_easy_init();

	std::string enc_request = "https://maps.googleapis.com/maps/api/distancematrix/json" + get_encoded_request(curl, origins, dest);
	curl_easy_setopt(curl, CURLOPT_URL, enc_request.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &json);

  	res = curl_easy_perform(curl);

 	curl_easy_cleanup(curl);

	if(res != CURLE_OK){
		json = "err";
	}

	 return json;
}


std::vector<int> GetTravelTime::make_request(std::vector<std::string> origins, std::string dest){
	ParseJson parser = ParseJson();

	std::string json = send_request(origins, dest);
	std::vector<int> time = parser.parse_json(json);

    return time;
}
