#include "home.h"
#include <gtest/gtest.h>
#include <Wt/WServer.h>
#include <Wt/Test/WTestEnvironment.h>

int main() {
    char* args[7];
    auto f = [&](int n, const std::string& s) {args[n] = new char[s.length() + 1]; strcpy(args[n], s.c_str());};
    int ix = 0;
    f(ix++, "fsserver");
    f(ix++, "--docroot");
    f(ix++, ".");
    f(ix++, "--http-address");
    f(ix++, "0.0.0.0");
    f(ix++, "--http-port");
    f(ix++, "8888");

    Test::WTestEnvironment environment;
    OverflowProject app(environment);
    
    /*
    Wt::WServer myServer(args[0]);
    myServer.setServerConfiguration(7, args, WTHTTP_CONFIGURATION);
    myServer.run();
    */
    // Somewhere
    for (auto it = std::begin(args); it != std::end(args); ++it)
        delete [] *it;
}

/*
void testX() {
  Test::WTestEnvironment environment;
  MyApplication app(environment);
  ...
}
*/