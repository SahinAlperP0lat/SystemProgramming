====================================================
1) DATABASE VERIFICATION (PostgreSQL)
====================================================

1.1 Enter PostgreSQL shell
    docker exec -it sis-db psql -U sis_user -d sis_db

1.2 List tables
    \dt

    Expected:
    students table exists
1.3 Show table structure
    \d students

    Columns:
    - id (SERIAL, primary key)
    - name
    - surname
    - department
    - email

1.4 Insert test students (manual verification)
    INSERT INTO students (name, surname, department, email)
    VALUES ('Ali','Nur','CENG','ali@example.com');

    INSERT INTO students (name, surname, department, email)
    VALUES ('Aqif','Lohja','CENG','aqif@example.com');

    INSERT INTO students (name, surname, department, email)
    VALUES ('Alper','Polat','CENG','alper@example.com');

1.5 List all students
    SELECT * FROM students;

1.6 Exit PostgreSQL
    \q

====================================================
2) RUNNING THE C++ APPLICATION
====================================================

2.1 Enter application container
    docker exec -it sis-app bash

2.2 Go to build directory
    cd /app/build

2.3 Run the application
    ./system_program

    Expected output:
    Connected to database successfully

====================================================
3) VERIFY C++ CRUD FUNCTIONS
====================================================

NOTE:
All operations below are implemented in C++ using libpqxx
and executed through database transactions.

----------------------------------------------------
3.1 CREATE (Insert Student)
----------------------------------------------------

Function:
- insertStudent(...)

Verification method:
- Run the application
- Insert a new student via C++ logic (hardcoded or function call)
- Check database:

    docker exec -it sis-db psql -U sis_user -d sis_db -c \
    "SELECT * FROM students;"

Expected:
- New student appears in table

----------------------------------------------------
3.2 READ (List Students)
----------------------------------------------------

Function:
- listStudents()

Verification method:
- Run C++ application
- Application queries students table
- Output printed to terminal

Expected:
- All rows displayed correctly

----------------------------------------------------
3.3 UPDATE (Update Student)
----------------------------------------------------

Function:
- updateStudent(id, ...)

Verification method:
- Update an existing student by ID
- Example change: department or email

Check in database:
    SELECT * FROM students WHERE id = <id>;

Expected:
- Updated values visible

----------------------------------------------------
3.4 DELETE (Delete Student)
----------------------------------------------------

Function:
- deleteStudent(id)

Verification method:
- Delete student by ID
- Verify removal

    SELECT * FROM students;

Expected:
- Deleted student no longer exists

----------------------------------------------------
3.5 TRANSACTION MANAGEMENT
----------------------------------------------------

All database operations use:
- pqxx::work
- commit() on success
- rollback on failure

Verification:
- Invalid insert/update does not corrupt database
- Errors are printed to console

----------------------------------------------------
3.6 ERROR HANDLING & LOGGING
----------------------------------------------------

Verification:
- Wrong connection parameters → error printed
- Invalid SQL → error message shown
- Application does not crash unexpectedly

====================================================
4) STOPPING THE PROJECT
====================================================

4.1 Stop containers
    docker compose down

4.2 Stop and remove database data (optional – deletes table)
    docker compose down -v
