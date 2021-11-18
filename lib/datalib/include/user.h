#ifndef __USER_H__
#define __USER_H__


#include <iostream>
#include <string>
#include <vector>


class User
{
public:
    User(std::string name, std::string surname, std::string address, int age, std::string city, std::vector<int> user_likes);
    ~User() = default;
    
    std::string get_full_name();
    std::string get_address();
    int get_age();
    std::string get_city();
    std::vector<int> get_likes();
    
private:
    std::string name;
    std::string surname;
    std::string address; 
    int age;
    std::string city;
    std::vector<int> user_likes;
};


#endif  // __USER_H__