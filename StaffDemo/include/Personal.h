#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
 public:
    Personal(int id, std::string name, int salary, int work_time, Positions position);
    int get_salary() const {return salary;};
    void set_salary(int x) {this->salary = x;};
    int calc_bonus_salary(int bonus = 0) const override;
    void print_info() const override;
    int calc_base_salary(int salary, int work_time_salary) const override;
 protected:
    int salary;
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name, int salary, int workTime, Positions position);
    void calc_salary() override;
    int calc_bonus_salary(int bonus = 4) const override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name, int salary, int workTime, Positions position);
    void calc_salary() override;
};
#endif
