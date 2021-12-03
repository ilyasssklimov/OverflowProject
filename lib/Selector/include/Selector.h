#include <vector>
#include "FlatAndTravelTime.h"

class Selector{
public:
    virtual std::vector<FlatAndTravelTime> get_by_travel_time(int count, std::string dest) = 0;
};
