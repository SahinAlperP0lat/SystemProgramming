#ifndef DB_HPP
#define DB_HPP

#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database();
    bool connect();

private:
    std::string connection_string;
};

#endif
