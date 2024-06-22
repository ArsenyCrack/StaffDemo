#include "Personal.h"

Personal::Personal(int id, std::string name, int work_time, int salary, Positions position) : Employee(id, name, salary, work_time, position) {
    this->salary = salary;
}

int Personal::calc_bonus_salary(int bonus) const {
    return 0;
}

int Personal::calc_base_salary(int salary, int work_time_salary) const {
    return salary * work_time_salary;
}

void Personal::print_info() const {
    std::cout << "------------------------------" << std::endl;
    std::cout << "ID : " << get_id() << std::endl;
    std::cout << "Name : " << get_name() << std::endl;
    std::cout << "Position : " << this->position << std::endl;
    std::cout << "Work time : " << get_work_time() << std::endl;
    std::cout << "Payment : " << get_payment() << std::endl;
    std::cout << "Salary : " << get_salary() << std::endl;
    std::cout << "------------------------------" << std::endl;
}

Driver::Driver(int id, std::string name, int work_time, int salary, Positions position) : Personal(id, name, work_time, salary, position) {}

int Driver::calc_bonus_salary(int bonus) const {
    if (this->work_time > 10) {
        return bonus;
    }
}

void Driver::calc_salary() {
    this->payment = calc_bonus_salary(4) + Personal::calc_base_salary(this->salary, this->work_time);
}

Cleaner::Cleaner(int id, std::string name, int work_time, int salary, Positions position) : Personal(id, name, work_time, salary, position) {}

void Cleaner::calc_salary() {
    this->payment = Personal::calc_base_salary(this->salary, this->work_time);
}
