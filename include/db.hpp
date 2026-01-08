#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    std::string surname;
    std::string department;
    std::string email;
};

class Database {
public:
    Database(const std::string& connection_str);
    ~Database();

    void createTableIfNotExists(); // optional but good
    void insertStudent(const Student& s);
    std::vector<Student> listStudents();
    void updateStudent(int id, const std::string& name,
                       const std::string& surname,
                       const std::string& department,
                       const std::string& email);
    void deleteStudent(int id);

private:
    pqxx::connection* conn;
};

#endif
