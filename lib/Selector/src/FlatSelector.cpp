#include "FlatSelector.h"
#include "GetTravelTime.h"




std::vector<Flat> select_rand_flats(int count){
    std::vector<Flat> result;

    result.push_back(Flat(std::string("Москва"), std::string("Бауманская ул., 33/2 строение 8")));
    result.push_back(Flat(std::string("Москва"), std::string("Краснопрудная ул., 26")));
    result.push_back(Flat(std::string("Москва"), std::string("ул. 2-я Рыбинская")));
    result.push_back(Flat(std::string("Москва"), std::string("Бутырская ул., 79")));
    result.push_back(Flat(std::string("Москва"), std::string("ул. Линии Октябрьской Железной Дороги, 2с1")));

    return result;
}


std::vector<std::string> FlatSelector::get_addr_vect(std::vector<Flat> flats){
    std::vector<std::string> result;

    for(Flat &sel_flat : flats){
        result.push_back(sel_flat.get_city() + ", " + sel_flat.get_address());
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

    std::vector<Flat> origins = select_rand_flats(count);
     
    std::vector<std::string> origins_addr = get_addr_vect(origins);
    std::vector<int> travel_time = get_travel_time(origins_addr, dest);

    int length = origins_addr.size();
    for(int i = 0; i < length; i++){
        result.push_back(FlatAndTravelTime(&origins[i], travel_time[i]));
    }
    return result;
}
