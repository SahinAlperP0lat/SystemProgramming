====================================================
1) PROJECT SETUP AND START
====================================================

1.1 Open terminal and go to project directory
    cd ~/SystemProgramming

    (If project is not present)
    git clone https://github.com/SahinAlperP0lat/SystemProgramming.git
    cd SystemProgramming

(Extra) Clean Rebuild + Manual Table Creation (If Needed)
====================================================

1) Full reset (removes DB data) + rebuild + start
   NOTE: This will delete all existing database data because of "-v".

   docker compose down -v
   docker compose build --no-cache
   docker compose up -d

2) Check containers are running
   docker ps

   Expected:
   - sis-db  (postgres:15) Up (healthy)
   - sis-app (systemprogramming-app) Up

----------------------------------------------------
3) Manual creation of PostgreSQL table (ONLY if table does not exist)
----------------------------------------------------

3.1 Connect to PostgreSQL inside the database container
    IMPORTANT: In this project the DB container name is "sis-db".

    docker exec -it sis-db psql -U sis_user -d sis_db

3.2 Create the students table
    (Run inside psql)

    CREATE TABLE students (
        id SERIAL PRIMARY KEY,
        name TEXT,
        surname TEXT,
        department TEXT,
        email TEXT
    );

3.3 Verify table exists
    \dt

3.4 View table structure
    \d students

3.5 Exit psql
    \q

1.2 (If required) Check .env file
    nano .env

    Example:
    POSTGRES_USER=sis_user
    POSTGRES_PASSWORD=sis_pass
    POSTGRES_DB=sis_db
    DB_HOST=db
    DB_PORT=5432

1.3 Build and start Docker containers
    docker compose up -d --build

1.4 Verify containers are running
    docker ps

    Expected containers:
    - sis-db  (PostgreSQL – healthy)
    - sis-app (C++ application)
