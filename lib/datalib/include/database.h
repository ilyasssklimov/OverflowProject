#ifndef __DATABASE_H__
#define __DATABASE_H__


#include <iostream>
#include <string>
#include "user.h"
#include "flat.h"


class DataBase
{
public:
    virtual bool connect_db() = 0;
    virtual ~DataBase() = default;
    
    virtual bool add_user(User &user);
    virtual bool add_users(std::string<User> &users);
    virtual bool add_flat(Flat &flat);
    virtual bool add_flats(std::vector<Flat> &flat);
    
    virtual User get_user(int id);
    virtual std::vector<User> get_users(std::vector<int> ids);
    virtual Flat get_flat(int id);
    virtual std::vector<Flat> get_flats(std::vector<int> ids);
    
    virtual std::vector<Flat> get_random_flats(int num);
    virtual std::vector<Flat> get_all_flats();
};


#endif  // __DATABASE_H__