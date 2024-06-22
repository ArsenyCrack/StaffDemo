#include "Employee.h"

Project::Project(int id, int budget, int number_of_employees) {
    this->id = id;
    this->budget = budget;
    this->number_of_employees = number_of_employees;
}


Employee::Employee(int id, std::string name, int salary, int work_time, Positions position) {
    this->id = id;
    this->name = name;
    this->salary = salary;
    this->work_time = work_time;
    this->position = position;
}
