#include <gtest/gtest.h>
#include "db_exception.h"
#include "sqlite_database.h"


TEST(DATABASE, CONNECT)
{
    try {
        std::string db_name = PATH_TO_DB;
        SQLiteDataBase db = SQLiteDataBase(db_name);
    }
    catch (ConnectionError) {
        ADD_FAILURE();
    }
}


TEST(DATABASE, ADD_FLAT)
{
    std::string db_name = PATH_TO_DB;
    SQLiteDataBase db = SQLiteDataBase(db_name);

    std::string title = "title_1";
    int price = 1000;
    Flat flat = Flat(title, price);

    EXPECT_TRUE(db.add_flat(flat) == true);
}


TEST(DATABASE, ADD_FLATS)
{
    std::string db_name = PATH_TO_DB;
    SQLiteDataBase db = SQLiteDataBase(db_name);

    std::string title_1 = "title_1";
    int price_1 = 1000;
    Flat flat_1 = Flat(title_1, price_1);

    std::string title_2 = "title_2";
    int price_2 = 500;
    Flat flat_2 = Flat(title_2, price_2);

    std::vector<Flat> flats = { flat_1, flat_2 };
    EXPECT_TRUE(db.add_flats(flats) == true);
}


TEST(DATABASE, GET_ALL_FLATS)
{
    std::string db_name = PATH_TO_DB;
    SQLiteDataBase db = SQLiteDataBase(db_name);

    db.delete_flats();

    std::string title_1 = "title_1";
    int price_1 = 1000;
    Flat flat_1 = Flat(title_1, price_1);

    std::string title_2 = "title_2";
    int price_2 = 500;
    Flat flat_2 = Flat(title_2, price_2);

    std::vector<Flat> flats = { flat_1, flat_2 };
    EXPECT_TRUE(db.add_flats(flats) == true);

    std::vector<Flat> getting_flats = db.get_all_flats();

    EXPECT_EQ(getting_flats[0].get_title(), title_1);
    EXPECT_EQ(getting_flats[0].get_price(), price_1);

    EXPECT_EQ(getting_flats[1].get_title(), title_2);
    EXPECT_EQ(getting_flats[1].get_price(), price_2);
}