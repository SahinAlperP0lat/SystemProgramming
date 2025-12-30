#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "db.hpp"
#include <string>

class StudentManager {
public:
    StudentManager(Database* db);
    void addStudent(int id, const std::string& name, const std::string& surname,
                    const std::string& department, const std::string& email);
    void listStudents();
    void updateStudent(int id, const std::string& field, const std::string& new_value);
    void deleteStudent(int id);

private:
    Database* db;
};

#endif
