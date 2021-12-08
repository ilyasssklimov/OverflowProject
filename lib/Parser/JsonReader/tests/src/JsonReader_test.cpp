#include "gtest/gtest.h"
#include "JsonReader.h"
#include "UrlsReader.h"
#include "rapidjson/document.h"
#include <vector>


TEST(JsonReader_find_json, JsonReader_find_json) {
    std::string json = "<html>{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}</html>";
    std::string json_otvet = "{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> vector_json;
    vector_json.push_back(json);
    auto *jsonReader = new JsonReader(&vector_json);
    std::vector<std::string> *a = jsonReader->find_json("{\"hello\"(.*)]}");
    EXPECT_TRUE(a->at(0) == json_otvet);
}

TEST(JsonReader_find_json, JsonReader_find_json_error) {
    std::string json = "<html>{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}</html>";
    std::string json_otvet = "{\"hello\": \"world\","
                             " \"t\": true,"
                             " \"f\": false,"
                             " \"n\": \"null\","
                             " \"i\": \"123\","
                             " \"pi\": 3.1416,"
                             " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> vector_json;
    vector_json.push_back(json);
    auto *jsonReader = new JsonReader(&vector_json);
    std::vector<std::string> *a = jsonReader->find_json("8789879"); // ошибочный поиск
    EXPECT_TRUE(a->at(0).empty() == true);
}

TEST(Read_Json_strs_to_json, Read_Json_strs_to_json) {
    std::string json_otvet = "{\"hello\": \"world\","
                             " \"t\": true,"
                             " \"f\": false,"
                             " \"n\": \"null\","
                             " \"i\": \"123\","
                             " \"pi\": 3.1416,"
                             " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> vector_json;
    vector_json.push_back(json);
    auto *jsonReader = new JsonReader(&vector_json);
    std::vector<std::string> *a = jsonReader->find_json("{\"hello\"(.*)]}");
    jsonReader->strs_to_json()
    EXPECT_TRUE(a->at(0) == json_otvet);
}

TEST(Read_Json_strs_to_json, Read_Json_strs_to_json_null){
    JsonReader readJson(NULL);
    rapidjson::Document *document = readJson.strs_to_json();
    EXPECT_EQ(document, NULL);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



