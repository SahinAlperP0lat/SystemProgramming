#include "db.hpp"
#include <iostream>

Database::Database(const std::string& connection_str) {
    try {
        conn = new pqxx::connection(connection_str);
        if (conn->is_open()) {
            std::cout << "Connected to database successfully\n";
        }
    } catch (const std::exception& e) {
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

void Database::createTableIfNotExists() {
    try {
        pqxx::work txn(*conn);
        txn.exec(R"(
            CREATE TABLE IF NOT EXISTS students (
                id INT PRIMARY KEY,
                name TEXT NOT NULL,
                surname TEXT NOT NULL,
                department TEXT NOT NULL,
                email TEXT NOT NULL
            );
        )");
        txn.commit();
        std::cerr << "[INFO] Table checked/created.\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Table creation failed: " << e.what() << std::endl;
    }
}

void Database::insertStudent(const Student& s) {
    try {
        pqxx::work txn(*conn);
        txn.exec_params(
            "INSERT INTO students (id, name, surname, department, email) VALUES ($1,$2,$3,$4,$5)",
            s.id, s.name, s.surname, s.department, s.email
        );
        txn.commit();
        std::cerr << "[INFO] Student inserted: " << s.id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Insert failed: " << e.what() << std::endl;
    }
}

std::vector<Student> Database::listStudents() {
    std::vector<Student> result;
    try {
        pqxx::work txn(*conn);
        pqxx::result r = txn.exec("SELECT id, name, surname, department, email FROM students ORDER BY id");
        txn.commit();

        for (const auto& row : r) {
            Student s;
            s.id = row["id"].as<int>();
            s.name = row["name"].as<std::string>();
            s.surname = row["surname"].as<std::string>();
            s.department = row["department"].as<std::string>();
            s.email = row["email"].as<std::string>();
            result.push_back(s);
        }

        std::cerr << "[INFO] Listed " << result.size() << " students.\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] List failed: " << e.what() << std::endl;
    }
    return result;
}

void Database::updateStudent(int id, const std::string& name,
                             const std::string& surname,
                             const std::string& department,
                             const std::string& email) {
    try {
        pqxx::work txn(*conn);
        txn.exec_params(
            "UPDATE students SET name=$1, surname=$2, department=$3, email=$4 WHERE id=$5",
            name, surname, department, email, id
        );
        txn.commit();
        std::cerr << "[INFO] Student updated: " << id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Update failed: " << e.what() << std::endl;
    }
}

void Database::deleteStudent(int id) {
    try {
        pqxx::work txn(*conn);
        txn.exec_params("DELETE FROM students WHERE id=$1", id);
        txn.commit();
        std::cerr << "[INFO] Student deleted: " << id << "\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Delete failed: " << e.what() << std::endl;
    }
}
