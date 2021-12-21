#include <iostream>
#include "sqlite_database.h"


int main()
{
    std::string db_name = path_to_db;
    SQLiteDataBase db = SQLiteDataBase(db_name);

    return 0;
}