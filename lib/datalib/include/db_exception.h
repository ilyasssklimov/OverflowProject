#ifndef __DB_EXCEPTION_H__
#define __DB_EXCEPTION_H__


#include <string>
#include <stdexcept>


class ConnectionError: public std::runtime_error {
public:
    explicit ConnectionError(const std::string &what_arg);
};


class ParamsError: public std::runtime_error {
public:
    explicit ParamsError(const std::string &what_arg);
};


class RequestError: public std::runtime_error {
public:
    explicit RequestError(const std::string &what_arg);
};


#endif  // __DB_EXCEPTION_H__
