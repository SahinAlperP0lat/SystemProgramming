#include "db.hpp"

int main() {
    Database db("host=db port=5432 dbname=sis_db user=sis_user password=sis_pass");
    return 0;
}
