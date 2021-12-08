#ifndef __DATABASE_PARAMS_H__
#define __DATABASE_PARAMS_H__


#include <iostream>
#include <string>


class DataBaseParams
{
public:
    DataBaseParams(std::string host, int port, std::string name, std::string user, std::string password);
    ~DataBaseParams() = default;
    
    std::string get_host();
    int get_port();
    std::string get_name();
    std::string get_user();
    std::string get_password();

private:
    std::string host;
    int port;
    std::string name;
    std::string user;
    std::string password;
};


#endif  // __DATABASE_PARAMS_H__