#ifndef __PG_DATABASE_H__
#define __PG_DATABASE_H__


#include <iostream>
#include <memory>
#include <string>
#include <libpq-fe.h>
#include "database_params.h"


class PGDataBase: public DataBase
{
public:
    PGDataBase(DataBaseParams &params);
    
    bool connect_db() override;
    std::unique_ptr<PGconn> get_connection();
    
private:
    std::unique_ptr<PGconn> connection;
    DataBaseParams params;
};
    

#endif  // __PG_DATABASE_H__