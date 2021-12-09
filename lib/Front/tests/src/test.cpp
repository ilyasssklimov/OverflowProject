#include "server.h"
#include <gtest/gtest.h>
#include <Wt/WServer.h>
#include <Wt/Test/WTestEnvironment.h>

int main() {
    Test::WTestEnvironment environment;
    OverflowProject app(environment);
}