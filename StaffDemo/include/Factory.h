#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

class Factory {
 public:
    static const inline std::map<std::string, Positions> string_to_enum = {
            {"programmer", Positions::programmer},
            {"team_leader", Positions::team_leader},
            {"project_manager", Positions::project_manager},
            {"senior_manager", Positions::senior_manager},
            {"cleaner", Positions::cleaner},
            {"driver", Positions::driver},
            {"tester", Positions::tester}

    };
    void Make_staff();
    std::vector<Employee*> staff;
    std::vector<Project*> projects;
 private:
    void read_staff(std::string& path);
    void read_projects(std::string& path);
};
#endif