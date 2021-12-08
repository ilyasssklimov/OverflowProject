#include "gtest/gtest.h"
#include "UrlsReader.h"
#include <vector>

TEST(UrlsReader_set_urls, UrlsReader_set_urls) {
    auto *readUrls = new UrlsReader;
    std::string url = "https://www.domofond.ru", base = "?Page=";
    std::vector<std::string> *urls_set = readUrls->set_urls(url, base, 10);
    for (int i = 0; i < urls_set->size(); i++) {
        EXPECT_TRUE(urls_set->at(i) == (url + base + std::to_string(i + 1)));
    }
}

TEST(UrlsReader_set_urls, UrlsReader_set_urls_null) {
    auto *readUrls = new UrlsReader;
    std::string *temp = nullptr;
    std::vector<std::string> *urls_set = readUrls->set_urls(*temp, *temp, 1);
    EXPECT_TRUE(urls_set == nullptr);
}

TEST(UrlsReader_parser_urls, UrlsReader_parser_urls) {
    auto *readUrls = new UrlsReader;
    std::string url = "https://www.domofond.ru", base = "?Page=";
    readUrls->set_urls(url, base, 1);
    std::vector<std::string> *context = readUrls->parser_urls();
    EXPECT_TRUE(context->empty() == false);
    delete readUrls;
}

TEST(UrlsReader_parser_urls, UrlsReader_parser_urls_error) {
    auto *readUrls = new UrlsReader;
    std::string url = " ", base = " ";
    readUrls->set_urls(url, base, 1);
    std::vector<std::string> *context = readUrls->parser_urls();
    EXPECT_TRUE(context->at(0) == "FAIL_READ");
    delete readUrls;
}

TEST(UrlsReader_parser_urls, UrlsReader_parser_urls_null) {
    auto *readUrls = new UrlsReader;
    std::vector<std::string> *context = readUrls->parser_urls();
    EXPECT_TRUE(context == nullptr);
    delete readUrls;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



