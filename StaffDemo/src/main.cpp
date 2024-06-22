#include "Factory.h"

int main() {
    Factory Apple;
    Apple.Make_staff();
    for (const auto staff: Apple.staff) {
        staff->calc_salary();
        std::cout<<std::endl;
    }
    for (const auto staff: Apple.staff) {
        staff->print_info();
        std::cout<<std::endl;
    }
}