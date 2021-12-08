#include "FlatSelector.h"
#include "GetTravelTime.h"

FlatSelector::FlatSelector(){
    std::string db_name = "overflow.db";
    db = new SQLiteDataBase(db_name);
}

std::vector<std::string> FlatSelector::get_addr_vect(std::vector<Flat> flats){
    std::vector<std::string> result;

    for(Flat &sel_flat : flats){
        result.push_back(sel_flat.get_address());
    }

    return result;
}



std::vector<int> FlatSelector::get_travel_time(std::vector<std::string> origins, std::string dest){
    std::vector<int> result;
    
	GetTravelTime calc_time = GetTravelTime();
	result = calc_time.make_request(origins, dest);

    return result;
}

std::vector<FlatAndTravelTime> FlatSelector::get_by_travel_time(int count, std::string dest){
    std::vector<FlatAndTravelTime> result;

    std::vector<Flat> origins = db->get_random_flats(count);
    
    if(origins.empty()){
        fprintf(stderr, "FlatSelector::get_by_travel_time - db->get_random_flats empty\n");
        return {};
    }

    std::vector<std::string> origins_addr = get_addr_vect(origins);
    std::vector<int> travel_time = get_travel_time(origins_addr, dest);

    if(travel_time.empty()){
        fprintf(stderr, "FlatSelector::get_by_travel_time - travel_time empty\n");
        return {};
    }

    int length = origins_addr.size();
    for(int i = 0; i < length; i++){
        result.push_back(FlatAndTravelTime(&origins[i], travel_time[i]));
    }
    return result;
}
