#include "db.hpp"
#include <iostream>

Database::Database(const std::string& connection_str) {
    try {
        conn = new pqxx::connection(connection_str);
        if (conn->is_open()) {
            std::cout << "Connected to database successfully\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Database connection failed: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

Database::~Database() {
    if (conn) {
        conn->disconnect();
        delete conn;
    }
}

pqxx::connection* Database::getConnection() {
    return conn;
}

void Database::insertStudent(int id, const std::string& name) {
    try {
        pqxx::work txn(*conn);
        txn.exec("INSERT INTO students VALUES (" +
                 txn.quote(id) + ", " +
                 txn.quote(name) + ")");
        txn.commit();

        std::cerr << "[INFO] Student inserted: " << id << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Insert failed: " << e.what() << std::endl;
    }
}
