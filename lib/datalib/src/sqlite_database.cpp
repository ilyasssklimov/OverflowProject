#include <algorithm>
#include "sqlite_database.h"
#include "db_exception.h"


SQLite3::SQLite3() {
    connection = nullptr;
}


SQLite3::~SQLite3() {
    sqlite3_close(connection);
}


SQLiteDataBase::SQLiteDataBase(SQLiteDataBase &db) {
    connection->connection = db.connection->connection;
}


SQLiteDataBase::SQLiteDataBase(const std::string &db_name) {
    connection = std::make_unique<SQLite3>();
    int rc = sqlite3_open(db_name.c_str(), &(connection->connection));

    if (rc != SQLITE_OK) {
        throw ConnectionError(sqlite3_errmsg(connection->connection));
    }

    create_tables();
}


void SQLiteDataBase::create_tables() {
    char *error_msg;

    std::string create_flat = "create table if not exists flat("
                              "title          text     not NULL,"
                              "price          integer,"
                              "price_per_area integer,"
                              "address        text,"
                              "description    text,"
                              "station        text,"
                              "property       text,"
                              "floor          integer,"
                              "floor_max      integer,"
                              "photo          text"
                              ");";

    int rc = sqlite3_exec(connection->connection, create_flat.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
}


static int select_callback(void *, int argc, char **argv, char **) {
    for (int i = 0; i < argc; i++)
        std::cout << (argv[i] ? argv[i] : "NULL") << "     ";
    std::cout << std::endl;
    return 0;
}


void SQLiteDataBase::select_flats() {
    std::string sql_select_flat = "select * from flat";
    char *error_msg = nullptr;
    int rc = sqlite3_exec(connection->connection, sql_select_flat.c_str(), select_callback, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
}


static std::string generate_string(const Flat &flat) {
    std::string description = flat.get_description();
    std::replace(description.begin(), description.end(), '\'', '_');

    std::string sql_flat = "\'" + flat.get_title() + "\', " + std::to_string(flat.get_price()) +
                           ", " + std::to_string(flat.get_price_per_area()) + ", \'" +
                           flat.get_address() + "\', \'" + description + "\', \'" +
                           flat.get_station() + "\', \'" + flat.get_property() + "\', " +
                           std::to_string(flat.get_floor()) + ", " + std::to_string(flat.get_floor_max()) +
                           ", \'" + flat.get_photo() + "\'";
    return sql_flat;
}


void SQLiteDataBase::add_flat(const Flat &flat) {
    std::string sql_flat = "insert into flat (title, price, price_per_area, address, "
                           "description, station, property, floor, floor_max, photo) "
                           "values (" + generate_string(flat) + ");";

    char *error_msg;
    int rc = sqlite3_exec(connection->connection, sql_flat.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
}


void SQLiteDataBase::add_flats(const std::vector<Flat> &flats) {
    std::string sql_flats = "insert into flat "
                            "(title, price, price_per_area, address, "
                            "description, station, property, floor, "
                            "floor_max, photo) values";

    for (const Flat &flat: flats)
        sql_flats += "(" + generate_string(flat) + "),\n";

    sql_flats.erase(sql_flats.length() - 2, 2);
    sql_flats += ";";

    char *error_msg = nullptr;
    int rc = sqlite3_exec(connection->connection, sql_flats.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
}


static int get_callback(void *flats, int argc, char **argv, char**) {
    if (argc != 10)
        throw (ParamsError("In callback function."));

    auto &container = *static_cast<std::vector<Flat>*>(flats);
    Flat flat = Flat(argv[0], std::stoi(argv[1]), std::stoi(argv[2]),
                     argv[3], argv[4], argv[5], argv[6], std::stoi(argv[7]),
                     std::stoi(argv[8]), argv[9]);
    container.emplace_back(flat);

    return 0;
}


std::vector<Flat> SQLiteDataBase::get_all_flats() {
    std::string sql_select_flat = "select * from flat";
    std::vector<Flat> flats;

    char *error_msg;
    int rc = sqlite3_exec(connection->connection, sql_select_flat.c_str(), get_callback, &flats, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
    return flats;
}


std::vector<Flat> SQLiteDataBase::get_random_flats(int num) {
    std::string sql_select_flat = "select * from flat order by random() limit " + std::to_string(num) + ";";
    std::vector<Flat> flats;

    char *error_msg = nullptr;
    int rc = sqlite3_exec(connection->connection, sql_select_flat.c_str(), get_callback, &flats, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
    return flats;
}


void SQLiteDataBase::delete_flats() {
    std::string sql_delete_flat = "delete from flat";
    char *error_msg = nullptr;
    int rc = sqlite3_exec(connection->connection, sql_delete_flat.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::string errmsg = error_msg;
        sqlite3_free(error_msg);

        throw RequestError(errmsg);
    }
}
