#include <vector>
#include <string>
#include <curl/curl.h>


class GetTravelTime{
public:
    std::vector<int> make_request(std::vector<std::string> origins, std::string dest);
private:
    std::string get_encoded_request(CURL *curl, std::vector<std::string> origins, std::string dest);
    std::string send_request(std::vector<std::string> origins, std::string dest);
};
