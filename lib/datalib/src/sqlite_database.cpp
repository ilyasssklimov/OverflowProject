#include "sqlite_database.h"
#include "db_exception.h"


SQLiteDataBase::SQLiteDataBase(const std::string &db_name) {
    connection = nullptr;
    int rc = sqlite3_open(db_name.c_str(), &connection);
    char *error_msg = nullptr;

    if (rc == SQLITE_OK && !create_tables(&error_msg)) {
        std::string message = error_msg;
        sqlite3_free(error_msg);
        time_t time_now = time(nullptr);
        throw ConnectionError(__FILE__, __LINE__, ctime(&time_now), error_msg);
    }
    else if (rc != SQLITE_OK){
        time_t time_now = time(nullptr);
        throw ConnectionError(__FILE__, __LINE__, ctime(&time_now), sqlite3_errmsg(connection));
    }
}


const sqlite3& SQLiteDataBase::get_connection() {
    return *connection;
}


SQLiteDataBase::~SQLiteDataBase() {
    sqlite3_close(connection);
}


bool SQLiteDataBase::create_tables(char **error_msg) {
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

    int rc = sqlite3_exec(connection, create_flat.c_str(), nullptr, nullptr, error_msg);
    if (rc == SQLITE_OK)
        return true;
    else
        return false;
}


static int select_callback(void *not_used, int argc, char **argv, char **column_name) {
    UNUSED(not_used);
    UNUSED(column_name);

    for (int i = 0; i < argc; i++)
        std::cout << (argv[i] ? argv[i] : "NULL") << "     ";
    std::cout << std::endl;
    return 0;
}


void SQLiteDataBase::select_flats() {
    std::string sql_select_flat = "select * from flat";
    char *error_msg = nullptr;
    if (sqlite3_exec(connection, sql_select_flat.c_str(), select_callback, nullptr, &error_msg) != SQLITE_OK) {
        fprintf(stderr, "Error while inserting: %s\n", error_msg);
        sqlite3_free(error_msg);
    }
}


static void get_flat_insert(Flat &flat, std::string &sql_flat) {
    sql_flat = "insert into flat (title, price, price_per_area, address, "
               "description, station, property, floor, floor_max, photo) "
               "values ('" + flat.get_title() + "', " + std::to_string(flat.get_price()) +
               ", " + std::to_string(flat.get_price_per_area()) + ", '" +
               flat.get_address() + "', '" + flat.get_description() + "', '" +
               flat.get_station() + "', '" + flat.get_property() + "', " +
               std::to_string(flat.get_floor()) + ", " + std::to_string(flat.get_floor_max()) +
               ", '" + flat.get_photo() + "');";
}


bool SQLiteDataBase::add_flat(Flat &flat) {
    std::string sql_insert_flat;
    get_flat_insert(flat, sql_insert_flat);
    char *error_msg = nullptr;

    if (sqlite3_exec(connection, sql_insert_flat.c_str(), nullptr, nullptr, &error_msg) == SQLITE_OK) {
        return true;
    }
    else {
        fprintf(stderr, "Error while inserting: %s\n", error_msg);
        sqlite3_free(error_msg);
        return false;
    }
}


bool SQLiteDataBase::add_flats(std::vector<Flat> &flats) {
    for (auto flat: flats) {
        if (!add_flat(flat))
            return false;
    }

    return true;
}


static int get_callback(void *flats, int argc, char **argv, char **column_name) {
    UNUSED(argc);
    UNUSED(column_name);

    auto &container = *static_cast<std::vector<Flat>*>(flats);
    FlatParams flat_params = FlatParams(argv[0], std::stoi(argv[1]), std::stoi(argv[2]),
                                        argv[3], argv[4], argv[5], argv[6], std::stoi(argv[7]),
                                        std::stoi(argv[8]), argv[9]);
    Flat flat = Flat(flat_params);
    container.push_back(flat);

    return 0;
}

std::vector<Flat> SQLiteDataBase::get_all_flats() {
    std::string sql_select_flat = "select * from flat";
    char *error_msg = nullptr;
    std::vector<Flat> flats;
    if (sqlite3_exec(connection, sql_select_flat.c_str(), get_callback, &flats, &error_msg) != SQLITE_OK) {
        fprintf(stderr, "Error while inserting: %s\n", error_msg);
        sqlite3_free(error_msg);
        return {};
    }
    return flats;
}


std::vector<Flat> SQLiteDataBase::get_random_flats(int num) {
    std::string sql_select_flat = "select * from flat order by random() limit " + std::to_string(num) + ";";
    char *error_msg = nullptr;
    std::vector<Flat> flats;
    if (sqlite3_exec(connection, sql_select_flat.c_str(), get_callback, &flats, &error_msg) != SQLITE_OK) {
        fprintf(stderr, "Error while inserting: %s\n", error_msg);
        sqlite3_free(error_msg);
        return {};
    }
    return flats;
}
