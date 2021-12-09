#include "settings.h"
#include "searchbox.h"

#include "FlatSelector.h"

class FlatWrapper: public Object {
public:
  FlatWrapper(FlatAndTravelTime _flat): flat(_flat) {};
  std::string info();
private:
  FlatAndTravelTime flat;
};

class OverflowProject : public Wt::WApplication
{
public:
  OverflowProject(const Wt::WEnvironment& env);
  SearchBox<FlatWrapper> *searchbox;
};

int run_server(int argc, char **argv);