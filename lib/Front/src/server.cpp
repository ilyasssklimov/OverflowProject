#include "server.h"

/*
Отображение информационного текста о Flat.
*/
std::string FlatWrapper::info() {
  std::stringstream ss;
  Flat *f = flat.get_flat();
  int t = flat.get_travel_time();
  ss << f->get_title() << std::endl << std::endl << f->get_description() << std::endl << std::endl <<
    "Цена: " << f->get_price();
  std::string out = ss.str();
  std::cout << out << std::endl;
  return out;
}

OverflowProject::OverflowProject(const Wt::WEnvironment& env) : WApplication(env)
{
  auto theme = std::make_shared<Wt::WBootstrapTheme>();
  theme->setVersion(Wt::BootstrapVersion::v3);
  setTheme(theme);
  useStyleSheet(Wt::WLink("https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"));
  require("https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js");
  setTitle(Settings::General::site_title);
  setBodyClass("bg-primary text-white");
  root()->addStyleClass("container vh-100 vw-100");
  auto site_label = root()->addWidget(std::make_unique<Wt::WText>(Settings::General::site_title));
  site_label->setAttributeValue("style", "font-size: 74px;");
  site_label->setStyleClass("row justify-content-center align-items-center h-50 m-4");
  site_label->setId("site_label");
  /*
    Получение данных от FlatSelector.
  */
  std::function<std::vector<FlatWrapper>(Wt::WString)> _get_data = [](Wt::WString input) {
    std::vector<FlatAndTravelTime> res = FlatSelector().get_by_travel_time(10, input.toUTF8());
    if (res.size() == 0) {
      std::cout << "Ошибка на стороне FlatSelector: пустой массив." << std::endl;
    }
    std::vector<FlatWrapper> out = {};
    for (auto flat: res) {
      out.push_back(FlatWrapper(flat));
    }
    return out;
  };
  searchbox = root()->addWidget(std::make_unique<SearchBox<FlatWrapper>>(_get_data));
}

int run_server(int argc, char **argv)
{
  /*
   * Your main method may set up some shared resources, but should then
   * start the server application (FastCGI or httpd) that starts listening
   * for requests, and handles all of the application life cycles.
   *
   * The last argument to WRun specifies the function that will instantiate
   * new application objects. That function is executed when a new user surfs
   * to the Wt application, and after the library has negotiated browser
   * support. The function should return a newly instantiated application
   * object.
   */
  return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
    /*
     * You could read information from the environment to decide whether
     * the user has permission to start a new application
     */
    return std::make_unique<OverflowProject>(env);
  });
}