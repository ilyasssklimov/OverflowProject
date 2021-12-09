#include <iostream>
#include "sqlite_database.h"


int main()
{
    std::string db_name = PATH_TO_DB;
    SQLiteDataBase db = SQLiteDataBase(db_name);

    return 0;
}