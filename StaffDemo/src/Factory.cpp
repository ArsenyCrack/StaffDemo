#include "Factory.h"

int FFF(std::string A) {
    int Z = 0;
    int i = 0;
    int k = 1;
    while (i < A.size()) {
        Z += (A[i])*k;
        k *= 10;
        i++;
    }
    return Z;
}

void Factory::read_staff(std::string& path) {
    std::ifstream staff_info(path);
    while (!staff_info.eof()) {
        std::vector<std::string> person;
        std::string field_of_employee;
        for (int i = 0; i < 6; i++) {
            getline(staff_info, field_of_employee);
            person.push_back(field_of_employee);
        }
        int id = FFF(person[0]);
        std::string name = person[1];
        int work_time = FFF(person[3]);
        int salary = FFF(person[2]);
        int project_id = FFF(person[5]);
        Positions position;
        std::string a = person[4];
        if (a == "programmer") {
            position = Positions::programmer;
        } else if (a == "team_leader") {
            position = Positions::team_leader;
        } else if (a == "cleaner") {
            position = Positions::cleaner;
        } else if (a == "driver") {
            position = Positions::driver;
        } else if (a == "project_manager") {
            position = Positions::project_manager;
        } else if (a == "senior_manager") {
            position = Positions::senior_manager;
        } else if (a == "tester") {
            position = Positions::tester;
        }
        Project *project = nullptr;

        for (const auto project1: projects) {
            if (project1->get_id() == project_id) {
                project = project1;
                break;
            }
        }
        std::vector<const Employee *> team_manager;
        std::vector<const Programmer *> team_programmer;
        std::vector<const Project *> projects_for_manager;
        Employee *worker = nullptr;
        switch (position) {
            case Positions::programmer:
                worker = new Programmer(id, name, work_time, salary, 1000, position);
                staff.push_back(worker);
                break;
            case Positions::team_leader:
                worker = new TeamLeader(id, name, work_time, salary,1000, position);
                staff.push_back(worker);
                break;
            case Positions::cleaner:
                worker = new Cleaner(id, name, salary, work_time, position);
                staff.push_back(worker);
                break;
            case Positions::driver:
                worker = new Driver(id, name, salary, work_time, position);
                staff.push_back(worker);
                break;
            case Positions::tester:
                worker = new Tester(id, name, work_time, salary, 1000, position);
                staff.push_back(worker);
                break;
            case Positions::project_manager:
                worker = new ProjectManager(id, name, salary, work_time, position, team_manager, project);
                staff.push_back(worker);
                break;
            case Positions::senior_manager:
                worker = new SeniorManager(id, name, salary, work_time, position, team_manager, projects_for_manager);
                staff.push_back(worker);
                break;

        }

    }
}
void Factory::read_projects(std::string& path) {
    std::ifstream projects_info(path);
    while (!projects_info.eof()) {
        std::vector<std::string> st_project;
        std::string field_of_project;
        for (int i = 0; i < 3; i++) {
            getline(projects_info, field_of_project);
            st_project.push_back(field_of_project);
        }
        int id = FFF(st_project[0]);
        int budget = FFF(st_project[1]);
        int number_of_employees = FFF(st_project[2]);
        projects.push_back(new Project(id, budget, number_of_employees));
    }
}
void Factory::Make_staff() {
    std::string staff_info("..//..//staff_info.txt");
    std::string projects_info("..//..//projects_info.txt");
    read_projects(projects_info);
    read_staff(staff_info);
}