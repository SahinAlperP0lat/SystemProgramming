#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database(const std::string& connection_str);
    ~Database();

    pqxx::connection* getConnection();
    void insertStudent(int id, const std::string& name);

private:
    pqxx::connection* conn;
};

#endif
