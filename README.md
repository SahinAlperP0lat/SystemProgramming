# System Programmig Term Project
# Team Members:
* Şahin Alper Polat - Project Manager - 220304002
* Ali Emir Nur - Docker and DevOps Engineer - 220304006
* Aqif Lohja - C++ Developer - 230304121

  
Student Information System with Docker Containers
Project Overview

Developed for the System Programming course, this project implements a distributed system using Ubuntu, Git, GitHub, and Docker. The system manages student records through a C++ application connected to a PostgreSQL database, both running in isolated Docker containers.
System Architecture

    Database Container: Runs PostgreSQL (official image: postgres:latest) with persistent volume management.

    Application Container: Custom C++ application utilizing libpqxx for database transactions.

    Networking: A private Docker network enables secure communication between containers.

Core Functions

The application supports the following CRUD operations:

    Save: Insert student ID, name, surname, department, and email.

    List: Retrieve and display student information.

    Update: Modify existing student records.

    Delete: Remove records from the database.

Technical Requirements

    Language: Modern C++ (C++11 or higher).

    Build System: CMake or Makefile.

    Infrastructure: Docker Compose (docker-compose.yml).

    CI/CD: Automated build and test pipeline via GitHub Actions.

Team and Roles

    Student 1 (Project Manager): Repository management, milestones, PR reviews, and Wiki documentation.

    Student 2 (Docker & DevOps Engineer): Dockerfile/Compose creation, CI/CD workflows, and Volume/Network management.

    Student 3 (C++ Developer): CRUD implementation, database connection layer, and unit testing.

Project Schedule

    Week 1 (19/12/2025): Initial setup and Week 1 activity report.

    Week 2 (26/12/2025): Docker containers and Docker Hub images ready.

    Week 3 (02/01/2026): C++ application basic functions completed.

    Final Submission (09/01/2026): All materials and documentation finalized.

Docker Hub Images

Images are named following the convention: [school-username]/[project-name]-[component]:[tag].

   PostgreSQL: Pending (Will be provided by Student 2 by Week 2)

C++ App: Pending (Will be provided by Student 2 by Week 2)
