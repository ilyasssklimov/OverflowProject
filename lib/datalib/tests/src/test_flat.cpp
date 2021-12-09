#include <gtest/gtest.h>
#include "flat.h"


Flat static generate_flat() {
    FlatParams flat_params = FlatParams("", 0);
    Flat flat = Flat(flat_params);

    return flat;
}


TEST(FLAT_TEST, TITLE)
{
    std::string new_title = "new_title";
    Flat flat = generate_flat();
    flat.set_title(new_title);

    EXPECT_EQ(new_title, flat.get_title());
}


TEST(FLAT_TEST, PRICE)
{
    int new_price = 1000;
    Flat flat = generate_flat();
    flat.set_price(new_price);

    EXPECT_EQ(new_price, flat.get_price());
}


TEST(FLAT_TEST, PRICE_PER_AREA)
{
    int new_price = 1000;
    Flat flat = generate_flat();
    flat.set_price_per_area(new_price);

    EXPECT_EQ(new_price, flat.get_price_per_area());
}


TEST(FLAT_TEST, ADDRESS)
{
    std::string new_address = "Moscow";
    Flat flat = generate_flat();
    flat.set_address(new_address);

    EXPECT_EQ(new_address, flat.get_address());
}


TEST(FLAT_TEST, DESCRIPTION)
{
    std::string new_description = "It is description";
    Flat flat = generate_flat();
    flat.set_description(new_description);

    EXPECT_EQ(new_description, flat.get_description());
}


TEST(FLAT_TEST, STATION)
{
    std::string new_station = "Izmaylovskaya";
    Flat flat = generate_flat();
    flat.set_station(new_station);

    EXPECT_EQ(new_station, flat.get_station());
}


TEST(FLAT_TEST, PROPERTY)
{
    std::string new_property = "Apartament";
    Flat flat = generate_flat();
    flat.set_property(new_property);

    EXPECT_EQ(new_property, flat.get_property());
}


TEST(FLAT_TEST, FLOOR)
{
    int new_floor = 10;
    Flat flat = generate_flat();
    flat.set_floor(new_floor);

    EXPECT_EQ(new_floor, flat.get_floor());
}


TEST(FLAT_TEST, FLOOR_MAX)
{
    int new_floor = 100;
    Flat flat = generate_flat();
    flat.set_floor_max(new_floor);

    EXPECT_EQ(new_floor, flat.get_floor_max());
}


TEST(FLAT_TEST, PHOTO)
{
    std::string new_photo = "https://some.com/url/";
    Flat flat = generate_flat();
    flat.set_photo(new_photo);

    EXPECT_EQ(new_photo, flat.get_photo());
}

