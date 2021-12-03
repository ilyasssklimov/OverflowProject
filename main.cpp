#include <curl/curl.h>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

#include "FlatSelector.h"


int main() {
	setlocale(LC_ALL,"Rus");
	FlatSelector selector = FlatSelector();

	std::vector<FlatAndTravelTime> flats = selector.get_by_travel_time(5, "Рубцовская наб., 2/18, Москва");

	for(FlatAndTravelTime i : flats){
		std::cout << i.get_flat()->get_address() << "  Время в пути: " << i.get_travel_time() << std::endl;
	}
	return 0;
}
