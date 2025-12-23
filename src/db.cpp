#include "db.hpp"
#include <iostream>

Database::Database() {
    // Docker-compatible connection string
    connection_string =
        "host=db "
        "dbname=sis_db "
        "user=sis_user "
        "password=sis_pass "
        "port=5432";
}

bool Database::connect() {
    try {
        pqxx::connection conn(connection_string);
        return conn.is_open();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}
