#ifndef __FLAT_H__
#define __FLAT_H__


#include <iostream>
#include <string>


using std::string;


class Flat
{
public:
    explicit Flat(const string &title, const int price, const int price_per_area=0,
                  const string &address="", const string &description="",
                  const string &station="", const string &property="", const int floor=0,
                  const int floor_max=0, const string &photo=""):
                  title_(title), price_(price), price_per_area_(price_per_area),
                  address_(address), description_(description), station_(station),
                  property_(property), floor_(floor), floor_max_(floor_max), photo_(photo) {}
    ~Flat() = default;

    string get_title() const;
    int get_price() const;
    int get_price_per_area() const;
    string get_address() const;
    string get_description() const;
    string get_station() const;
    string get_property() const;
    int get_floor() const;
    int get_floor_max() const;
    string get_photo() const;

    void set_title(const string &new_title);
    void set_price(const int new_price);
    void set_price_per_area(const int new_price);
    void set_address(const string &new_address);
    void set_description(const string &new_description);
    void set_station(const string &new_station);
    void set_property(const string &new_property);
    void set_floor(const int new_floor);
    void set_floor_max(const int new_floor);
    void set_photo(const string &new_photo);

private:
    string title_;
    int price_;
    int price_per_area_;
    string address_;
    string description_;
    string station_;
    std::string property_;
    int floor_;
    int floor_max_;
    string photo_;
};


#endif  // __FLAT_H__