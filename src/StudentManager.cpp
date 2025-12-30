#include "StudentManager.h"
#include <pqxx/pqxx>
#include <iostream>

StudentManager::StudentManager(Database* db) : db(db) {}

void StudentManager::addStudent(int id, const std::string& name, const std::string& surname,
                                const std::string& department, const std::string& email) {
    try {
        pqxx::work W(*db->getConnection());
        W.exec_params("INSERT INTO students (id, name, surname, department, email) VALUES ($1,$2,$3,$4,$5)",
                      id, name, surname, department, email);
        W.commit();
        std::cout << "Student added successfully\n";
    } catch (const std::exception &e) {
        std::cerr << "Error adding student: " << e.what() << std::endl;
    }
}

