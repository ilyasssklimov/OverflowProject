#include "db_exception.h"


ConnectionError::ConnectionError(const std::string &what_arg):
        std::runtime_error("Incorrect connection to database. Please check your db file: " + what_arg) {}


ParamsError::ParamsError(const std::string &what_arg):
        std::runtime_error("Incorrect params in params of function. " + what_arg) {}


RequestError::RequestError(const std::string &what_arg):
        std::runtime_error("Incorrect request to database. " + what_arg) {}
