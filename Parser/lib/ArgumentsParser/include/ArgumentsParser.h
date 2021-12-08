#ifndef PARSER_APARTMENTS_H
#define PARSER_APARTMENTS_H

#include <vector>
#include <curl/curl.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


class ArgumentsParser{
public:
    ArgumentsParser(std::string, std::string, size_t);
    ~ArgumentsParser();
    std::vector<std::string> URLS_to_str();
    rapidjson::Document str_to_json();
    size_t json_to_db();

private:
    std::vector<std::string> urls;
    std::vector<std::string>  context;
    rapidjson::Document jsons;
    size_t time_delay;
};

#endif //PARSER_APARTMENTS_H
