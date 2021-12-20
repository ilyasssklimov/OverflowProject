#ifndef __SELECTOR_H__
#define __SELECTOR_H__

#include <vector>
#include "sqlite_database.h"
#include "FlatAndTravelTime.h"

class Selector{
public:
    virtual std::vector<FlatAndTravelTime> get_by_travel_time(int count, std::string dest) = 0;
};

#endif
