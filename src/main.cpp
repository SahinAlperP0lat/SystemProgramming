#include <iostream>
#include "db.hpp"

int main() {
    std::cout << "Student Information System - C++ App\n";

    Database db;
    if (db.connect()) {
        std::cout << "Database connection successful.\n";
    } else {
        std::cout << "Database connection failed.\n";
    }

    return 0;
}
