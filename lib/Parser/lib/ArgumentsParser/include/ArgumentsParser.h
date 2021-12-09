#ifndef PARSER_APARTMENTS_H
#define PARSER_APARTMENTS_H

#include <vector>
#include <curl/curl.h>
#include "JsonReader.h"
#include "UrlsReader.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


class ArgumentsParser{
public:
    ArgumentsParser(std::string&, std::string&, size_t page_size);
    ~ArgumentsParser();
    std::vector<std::string>* URLS_to_str();
    std::vector<rapidjson::Document*>* str_to_json(std::string find_param);
    size_t json_to_db(std::string &name_db);

private:
    size_t page_size;
    std::string base_url;
    std::string get_param;
    std::vector<std::string>* context;
    std::vector<rapidjson::Document*>* jsons;
    UrlsReader *urlsReader;
    JsonReader *jsonReader;
};

#endif //PARSER_APARTMENTS_H
