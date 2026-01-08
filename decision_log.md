Project Information

Project: Student Information System with Docker Containers

Course: System Programming

Team Size: 3 Members

Start Date: 12/12/2025

Last Updated: 09/01/2026
Log Entries
ID: 001 - Technology Stack Selection

    Date: 12/12/2025

    Status: [ACCEPTED]

    Context: The project requires a distributed system architecture to demonstrate system programming skills.

    Decision:

        Language: C++ (Standard C++11 or higher).

        OS: Ubuntu Linux.

        Containerization: Docker & Docker Compose.

        Database: PostgreSQL.

    Reasoning: These technologies are mandatory requirements of the course curriculum. Additionally, C++ provides low-level system control, and PostgreSQL is a robust, open-source relational database suitable for transactional data.

ID: 002 - Version Control Strategy (Git Flow)

    Date: 12/12/2025

    Status: [ACCEPTED]

    Context: Three developers will be working simultaneously, requiring a strategy to prevent conflicts and maintain code quality.

    Decision: Adopt a strict branching strategy:

        main: Production-ready code only.

        develop: Integration branch for ongoing development.

        feature/*: Individual branches for specific tasks (e.g., feature/add-student-crud).

        Rule: No direct pushes to main or develop. All changes via Pull Requests (PRs).

    Reasoning: Ensures code review happens before merging. Keeps the stable version isolated from experimental features.

ID: 003 - Project Management Methodology

    Date: 13/12/2025

    Status: [ACCEPTED]

    Context: Tasks need to be distributed and tracked among 3 team members (PM, DevOps, Dev).

    Decision: Use GitHub Projects (Kanban Board) for task tracking and GitHub Issues for technical discussions.

    Reasoning: Centralizes communication within the repository. Provides visibility on "To Do", "In Progress", and "Done" tasks, which is a graded success indicator.

ID: 004 - Database Connectivity Library

    Date: 19/12/2025

    Status: [ACCEPTED]

    Context: The C++ application needs a reliable method to communicate with the PostgreSQL container.

    Decision: Use libpqxx.

    Reasoning: It is the official C++ client API for PostgreSQL. It supports transactions (pqxx::work), exception handling, and is thread-safe, meeting the project's technical requirements for transaction management.

ID: 005 - Build System Selection

    Date: 20/12/2025

    Status: [ACCEPTED]

    Context: The C++ project has multiple source files and external dependencies (libpqxx).

    Decision: Use CMake (CMakeLists.txt).

    Reasoning: CMake is the industry standard for C++ projects, offers better cross-platform support than raw Makefiles, and integrates easily with IDEs and CI pipelines.

ID: 006 - Container Orchestration & Networking

    Date: 26/12/2025

    Status: [ACCEPTED]

    Context: The Application and Database containers need to communicate in a private network and start simultaneously.

    Decision: Use Docker Compose (docker-compose.yml).

    Reasoning: Allows defining multi-container applications in a single file. Automates network creation (containers can reach each other by service name, e.g., db) and volume management for data persistence.

ID: 007 - CI/CD Pipeline Tool

    Date: 28/12/2025

    Status: [ACCEPTED]

    Context: Automated testing and build verification are required to ensure no broken code is merged.

    Decision: Use GitHub Actions.

    Reasoning: Native integration with GitHub. We configured .github/workflows/ci.yml to compile the C++ code and build Docker images on every Pull Request to the develop branch.

ID: 008 - Documentation Architecture

    Date: 08/01/2026

    Status: [ACCEPTED]

    Context: The project documentation was becoming too large for a single README file.

    Decision: Split documentation into specific files:

        INSTALL.md: Setup and installation steps.

        MANUAL.md: Usage guide, manual testing, and troubleshooting.

        README.md: General overview and project summary.

    Reasoning: improved readability and user experience. Separates "Day 1 Setup" tasks from "Day 2 Operations" tasks (Closes Issue #26 & #27).

ID: 009 - Docker Hub Image Naming Convention

    Date: 08/01/2026

    Status: [ACCEPTED]

    Context: Images must be pushed to Docker Hub and be identifiable for grading.

    Decision: Adopt format: [school-username]/[project-name]-[component]:[tag].

        Example: user/sis-project-app:v1.0

    Reasoning: Complies with mandatory coursework rules and ensures clear ownership of the images.

Rejected Alternatives / Notes

    Raw SQL vs ORM: We decided to use raw SQL queries via libpqxx instead of a C++ ORM (like ODB) to demonstrate better understanding of SQL commands and system-level database interactions as required by the course objectives.

    SQLite vs PostgreSQL: SQLite was considered for simplicity, but rejected because the project requirements explicitly mandated PostgreSQL to demonstrate container networking.
