#include "flat.h"


string Flat::get_title() const {
    return title_;
}


int Flat::get_price() const {
    return price_;
}


int Flat::get_price_per_area() const {
    return price_per_area_;
}


string Flat::get_address() const {
    return address_;
}


string Flat::get_description() const {
    return description_;
}


string Flat::get_station() const {
    return station_;
}


string Flat::get_property() const {
    return property_;
}


int Flat::get_floor() const {
    return floor_;
}


int Flat::get_floor_max() const {
    return floor_max_;
}


string Flat::get_photo() const {
    return photo_;
}


void Flat::set_title(const string &title)
{
    title_ = title;
}


void Flat::set_price(const int price) {
    price_ = price;
}


void Flat::set_price_per_area(const int price) {
    price_per_area_ = price;
}


void Flat::set_address(const string &address) {
    address_ = address;
}


void Flat::set_description(const string &description) {
    description_ = description;
}


void Flat::set_station(const string &station) {
    station_ = station;
}


void Flat::set_property(const string &property) {
    property_ = property;
}


void Flat::set_floor(const int floor) {
    floor_ = floor;
}


void Flat::set_floor_max(const int floor) {
    floor_max_ = floor;
}


void Flat::set_photo(const string &photo) {
    photo_ = photo;
}
