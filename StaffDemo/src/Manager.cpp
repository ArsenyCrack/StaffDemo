#include "Manager.h"
#include <iostream>

ProjectManager::ProjectManager(int id, const std::string &name, int salary, int work_time,
                               Positions position,
                               std::vector<const Employee*>& team,
                               const Project* project) :
        Employee(id, name, salary, work_time, position),
        team(team), project(project) {}


void ProjectManager::print_info() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "ID : " << this->id << std::endl;
    std::cout << "Name : " << this->name << std::endl;
    std::cout << "Position : " << this->position << std::endl;
    std::cout << "Work time : " << this->work_time << std::endl;
    std::cout << "Payment : " << this->payment << std::endl;
    std::cout << "Salary : " << this->salary << std::endl;
    std::cout << "Project id : " << project->get_id() << std::endl;
    std::cout << "Project budget : " << project->get_budget() << std::endl;
    std::cout << "Project num_of_employees : " << project->get_num_of_employees() << std::endl;
    std::cout<<"team: "<<std::endl;
    for (const auto subordinate : team) {
        std::cout<<'\t';
        std::cout<<subordinate->get_id()<<' '<<subordinate->get_name()<<'\n';
    }
    std::cout << "------------------------------" << std::endl;
}

void ProjectManager::set_payment_for_worker(double x) {
    payment_for_worker = x;
}

void ProjectManager::set_budget_part(double x) {
    budget_part = x;
}

void ProjectManager::set_project(const Project *new_project) {
    project = new_project;
}

double ProjectManager::bonus_for_worker() const {
    return payment_for_worker * team.size();
}

void ProjectManager::calc_salary() {
    this->payment += calc_budget_part(0.3) + calc_pro_additions();
}

int ProjectManager::calc_budget_part(float part) const {
    return part * project->get_budget();
}

int ProjectManager::calc_pro_additions() const {
    return bonus_for_worker();
}

SeniorManager::SeniorManager(int id, const std::string &name, int salary, int work_time, Positions position,
                             std::vector<const Employee *> &team, std::vector<const Project *> &projects) : ProjectManager(id, name, salary, work_time, position, team, nullptr), projects(projects) {}

void SeniorManager::calc_salary() {
    double salary = 0;
    for (const auto project : projects) {
        salary += project->get_budget() * budget_part;
    }
    salary+= team.size() * payment_for_worker;
    this->payment += salary;
}

void SeniorManager::print_info() const {
    ProjectManager::print_info();
    std::cout<<"Projects id: "<<'\n';
    for (const auto project : projects) {
        std::cout<<project->get_id()<<", ";
    }
}