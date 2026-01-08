#include "db.hpp"
#include <iostream>

int main() {
    Database db("host=db port=5432 dbname=sis_db user=sis_user password=sis_pass");

    db.createTableIfNotExists();

    Student s1{1, "Ali banning", "Nur", "CENG", "ali@example.com"};
    db.insertStudent(s1);

    auto students = db.listStudents();
    for (const auto& s : students) {
        std::cout << s.id << " " << s.name << " " << s.surname
                  << " " << s.department << " " << s.email << "\n";
    }

    db.updateStudent(1, "Ali", "Nur", "AI", "ali@example.com");

    db.deleteStudent(1);

    return 0;
}
