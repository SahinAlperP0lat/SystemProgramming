#include "db.hpp"

int main() {
    Database db("host=localhost port=5432 dbname=sis user=postgres password=yourpassword");
    return 0;
}
