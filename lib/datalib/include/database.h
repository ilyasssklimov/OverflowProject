#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <iostream>
#include <string>
#include <vector>
#include "flat.h"
#include "db_config.h"


class IDataBase {
public:
    virtual ~IDataBase() = default;

    virtual void add_flat(const Flat &flat) = 0;
    virtual void add_flats(const std::vector<Flat> &flat) = 0;

    virtual std::vector<Flat> get_all_flats() = 0;
    virtual std::vector<Flat> get_random_flats(int num) = 0;
};


#endif  // __DATABASE_H__