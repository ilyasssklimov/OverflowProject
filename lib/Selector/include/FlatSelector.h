#include "Selector.h"

class FlatSelector: public Selector{
public: 
    std::vector<FlatAndTravelTime> get_by_travel_time(int count, std::string dest) override;
private:
    std::vector<std::string> get_addr_vect(std::vector<Flat> flats);
    std::vector<int> get_travel_time(std::vector<std::string> origins, std::string dest);
};
