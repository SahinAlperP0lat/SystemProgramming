#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../include/db.hpp"
#include "../include/StudentManager.h"

TEST_CASE("Database connection works", "[database]") {
    Database db("dbname=student_db user=student_user password=password123 host=db port=5432");
    REQUIRE(db.getConnection()->is_open() == true);
}

TEST_CASE("Add student works", "[student]") {
    Database db("host=db port=5432 dbname=sis user=postgres password=yourpassword");
    StudentManager sm(&db);
    REQUIRE_NOTHROW(sm.addStudent(1, "John", "Doe", "CS", "john@example.com"));
}
