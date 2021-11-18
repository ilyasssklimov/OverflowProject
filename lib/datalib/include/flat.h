#ifndef __FLAT_H__
#define __FLAT_H__


#include <iostream>
#include <string>
#include <vector>


class Flat
{
public:
    Flat(int price, std::string city, std::string address, int rooms, int square, int floor, std::vector<std::string> photo_urls, std::map<std::string, int> nearest_metro, std::vector<int> flat_likes);
    ~Flat() = default;
    
    int get_price();
    std::string get_city()
    std::string get_address();
    int get_rooms();
    int get_square();
    int get_floor();
    std::vector<std::string> get_photo_urls();
    std::map<std::string, int> get_nearest_metro();
    std::vector<int> get_likes();
    
private:
    int price;
    std::string city;
    std::string address;
    int rooms;
    int square;
    int floor;
    std::vector<std::string> photo_urls;
    std::map<std::string, int> nearest_metro;
    std::vector<int> flat_likes;
};


#endif  // __FLAT_H__