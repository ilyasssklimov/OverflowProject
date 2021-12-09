#include "test.h"

TEST(SEARCHBOX_TEST, OBJ_COUNT) {
    Wt::Test::WTestEnvironment environment;
    OverflowProject app(environment);
    std::string title = "Flat1";
    int price = 10000;
    FlatParams params = FlatParams(title, price);
    Flat flat = Flat(params);
    FlatAndTravelTime flat_ = FlatAndTravelTime(&flat, 0);
    std::function<std::vector<FlatWrapper>(Wt::WString)> get_data = [flat_](Wt::WString input) {
      return std::vector<FlatWrapper>{FlatWrapper(flat_), FlatWrapper(flat_), FlatWrapper(flat_), FlatWrapper(flat_)};
    };
    app.searchbox->get_data = get_data;
    EXPECT_EQ(app.searchbox->data.size(), 4);
}

TEST(FLATWRAPPER_TEST, INFO) {
    std::string title = "Flat";
    int price = 10000;
    FlatParams params = FlatParams(title, price);
    Flat flat = Flat(params);
    FlatAndTravelTime flat_ = FlatAndTravelTime(&flat, 0);
    FlatWrapper flatw = FlatWrapper(flat_);
    EXPECT_EQ(flatw.info(), "");
}