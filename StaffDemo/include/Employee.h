#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>

enum Positions {
    programmer,
    team_leader,
    project_manager,
    senior_manager,
    cleaner,
    driver,
    tester,
};
class Project {
 public:
    Project(int id, int budget, int number_of_employees);
    int get_num_of_employees() const {return number_of_employees;};
    int get_budget() const {return budget;};
    int get_id() const {return id;};
    void set_num_of_employees(int x) {this->number_of_employees = x;};
    void set_id(int x) {this->id = x;};
    void set_budget(int x) {this->budget = x;};
 private:
    int id;
    int budget;
    int number_of_employees;
};

class Employee {
 public:
    Employee(int id, std::string name, int salary, int work_time, Positions position);
    int get_id() const {return id;};
    std::string get_name() const {return name;};
    int get_work_time() const {return work_time;};
    int get_payment() const {return payment;};
    virtual void calc_salary() = 0;
    virtual void print_info() const = 0;
    void set_id(int x) {this->id = x;};
    void set_name(std::string x) {this->name = x;};
    void set_work_time(int x) {this->work_time = x;};
    void set_payment(int x) {this->payment = x;};

 protected:
    Positions position;
    int salary;
    int payment;
    int work_time;
    std::string name;
    int id;
    std::vector<std::string> enum_print = {"programmer",
                                           "team_leader",
                                           "project_manager",
                                           "senior_manager",
                                           "cleaner",
                                           "driver",
                                           "tester"};

};

#endif
