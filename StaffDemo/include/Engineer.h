#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include "Interfaces.h"
#include "Personal.h"

class Engineer : public Project_Budget, public Personal {
 public:
    Engineer(int id, std::string name, int work_time, int salary, Positions position);
    void calc_salary() override;
    int calc_budget_part(float part) const override;
    void print_info() const override;
 protected:
    Project *project;
};

class Programmer : public Engineer {
 public:
    Programmer(int id, std::string name, int work_time, int salary, int payment, Positions position);
    void calc_salary() override;
    int calc_pro_additions() const override;
};

class Tester : public Engineer {
 public:
    Tester(int id, std::string name, int work_time, int salary, int payment, Positions position);
    void calc_salary() override;
    int calc_pro_additions() const override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id, std::string name, int work_time, int salary, int payment, Positions position);
    void calc_salary() override;
    int calc_Heads() override;
};
#endif
