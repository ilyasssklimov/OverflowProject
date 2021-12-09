#include "gtest/gtest.h"
#include "ArgumentsParser.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <vector>

TEST(ArgumentsParser_all, ArgumentsParser_URLS_to_str){
    ArgumentsParser *apartments;
    std::string base = "https://www.domofond.ru?";
    std::string get = "Page=";
    apartments = new ArgumentsParser(base, get, 1);
    apartments->URLS_to_str();
    apartments->str_to_json("{\"itemsState\":(.*)}}");
    std::string name = "overflow.db";
    apartments->json_to_db(name);
    //проверка на наличе полей в бд. Пока не понятно как тестить
}

TEST(ArgumentsParser_all, ArgumentsParser_URLS_to_str_null){
    ArgumentsParser *apartments;
    std::string base = "https://www.domofond.ru?";
    std::string get = "Page=";
    apartments = new ArgumentsParser(base, get, 1);
    apartments->str_to_json("{\"itemsState\":(.*)}}");
    std::string name = "overflow.db";
    apartments->json_to_db(name);
    EXPECT_EQ(apartments, NULL);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

