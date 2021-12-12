#include "test.h"

TEST(SEARCHBOX_TEST, OBJ_COUNT) {
  Wt::Test::WTestEnvironment environment;
  OverflowProject *app = new OverflowProject(environment);
  std::string title = "Flat1";
  int price = 10000;
  FlatParams params = FlatParams(title, price);
  Flat flat = Flat(params);
  FlatAndTravelTime flat_ = FlatAndTravelTime(&flat, 0);
  std::function<std::vector<FlatWrapper>(Wt::WString)> get_data = [flat_](Wt::WString input) {
    return std::vector<FlatWrapper>{FlatWrapper(flat_), FlatWrapper(flat_), FlatWrapper(flat_), FlatWrapper(flat_)};
  };
  app->searchbox->get_data = get_data;
  app->searchbox->showresults();
  EXPECT_EQ(app->searchbox->data.size(), 4);
  delete app;
}

TEST(FLATWRAPPER_TEST, INFO) {
  /*
  Проверка вывода при наличии файла шаблона.
  */
  std::ofstream f("info.xml");
  f << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
  "<messages>"
  "<message id=\"info\">"
  "${title} ${price}"
  "</message>"
  "</messages>";
  f.close();
  Wt::Test::WTestEnvironment environment;
  environment.setDocRoot(".");
  OverflowProject *app = new OverflowProject(environment);
  std::string title = "Flat";
  int price = 10000;
  FlatParams params = FlatParams(title, price);
  Flat flat = Flat(params);
  FlatAndTravelTime flat_ = FlatAndTravelTime(&flat, 0);
  FlatWrapper flatw = FlatWrapper(flat_);
  std::function<std::vector<FlatWrapper>(Wt::WString)> get_data = [flatw](Wt::WString input) {
    return std::vector<FlatWrapper>{flatw};
  };
  app->searchbox->get_data = get_data;
  app->searchbox->showresults();
  flatw = app->searchbox->data[0];
  std::stringstream result;
  flatw.info()->renderTemplate(result);
  EXPECT_EQ(result.str(), title+" "+std::to_string(price));
  delete app;
}

TEST(FLATWRAPPER_TEST, INFO_NOT_FOUND) {
  /*
    Проверка вывода при отсутствии файла шаблона.
  */
  std::string title = "Flat";
  int price = 10000;
  FlatParams params = FlatParams(title, price);
  Flat flat = Flat(params);
  FlatAndTravelTime flat_ = FlatAndTravelTime(&flat, 0);
  FlatWrapper flatw = FlatWrapper(flat_);
  EXPECT_EQ(flatw.info()->templateText().toUTF8(), "??info??");
}