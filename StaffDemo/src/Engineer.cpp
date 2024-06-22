#include "Engineer.h"
#include <ctime>

Engineer::Engineer(int id, std::string name, int work_time, int salary, Positions position) : Personal(id, name, salary, work_time, position) {
    set_payment(1000);
}

int Engineer::calc_budget_part(float part) const {
    return project->get_budget() * part;
}

void Engineer::calc_salary() {
    this->payment = this->payment + calc_budget_part(0.1) + Personal::calc_base_salary(this->salary, this->work_time);
}

void Engineer::print_info() const {
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
    std::cout << "------------------------------" << std::endl;
}

Programmer::Programmer(int id, std::string name, int work_time, int salary, int payment, Positions position) : Engineer(id, name, work_time, salary, position) {}

int Programmer::calc_pro_additions() const {
    if (this->work_time < 10) {
        return 0.5 * this->salary;
    }
}

void Programmer::calc_salary() {
    this->payment = Personal::calc_base_salary(this->salary, this->work_time) + Engineer::calc_budget_part(0.1) + calc_pro_additions();
}

Tester::Tester(int id, std::string name, int work_time, int salary, int payment, Positions position) : Engineer(id, name, work_time, salary, position) {}

int Tester::calc_pro_additions() const {
    srand(time(0));
    if ((rand() % 100 + 1) > 30) {
        return 0.5 * this->salary;
    }
}

void Tester::calc_salary() {
    this->payment = Personal::calc_base_salary(this->salary, this->work_time) + Engineer::calc_budget_part(0.1) + calc_pro_additions();
}

TeamLeader::TeamLeader(int id, std::string name, int work_time, int salary, int payment, Positions position) : Programmer(id, name, work_time, salary, payment, position) {}

int TeamLeader::calc_Heads() {
    return project->get_num_of_employees() * 50;
}

void TeamLeader::calc_salary() {
    this->payment = Personal::calc_base_salary(this->salary, this->work_time) + Engineer::calc_budget_part(0.2) + calc_Heads();
}
