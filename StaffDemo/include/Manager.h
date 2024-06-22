#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager: public Employee, public Project_Budget {
public:
    ProjectManager(int id, const std::string& name, int salary, int work_time, Positions position, std::vector<const Employee*>& team, const Project* project);
    double bonus_for_worker() const;
    int calc_budget_part(float part) const override;
    int calc_pro_additions() const override;
    void set_payment_for_worker(double x);
    void set_budget_part(double x);
    void set_project(const Project* new_project);
    void calc_salary() override;
    void print_info() const override;

protected:
    std::vector<const Employee*> team;
    double payment_for_worker = 1;
    double budget_part = 0.01;

private:
    const Project* project;
};

class SeniorManager : public ProjectManager {
public:
    SeniorManager(int id, const std::string& name, int salary, int work_time, Positions position, std::vector<const Employee*>& team, std::vector<const Project*>& projects);

    void calc_salary() override;
    void print_info() const override;

private:
    std::vector<const Project*> projects;
};


#endif
