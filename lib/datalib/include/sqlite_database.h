#ifndef __SQLite_DATABASE_H__
#define __SQLite_DATABASE_H__

#define UNUSED(x) (void)(x)


#include <iostream>
#include <string>
#include <sqlite3.h>
#include <memory>
#include "database.h"


class SQLite3 {
public:
    SQLite3();
    ~SQLite3();

    sqlite3 *connection;
};


class SQLiteDataBase: public IDataBase {
public:
    explicit SQLiteDataBase(const std::string& db_name);
    SQLiteDataBase(SQLiteDataBase &db);

    ~SQLiteDataBase() override = default;

    void select_flats();
    void delete_flats();

    void add_flat(const Flat &flat) override;
    void add_flats(const std::vector<Flat> &flats) override;

    std::vector<Flat> get_all_flats() override;
    std::vector<Flat> get_random_flats(int num) override;

private:
    std::unique_ptr<SQLite3> connection;
    void create_tables();
};


#endif  // __SQLite_DATABASE_H__