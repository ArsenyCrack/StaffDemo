#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_
class Heading {
 public:
    virtual ~Heading() = default;
    virtual int calc_Heads() = 0;
};

class Work_Base_Time {
 public:
    virtual ~Work_Base_Time() = default;
    virtual int calc_bonus_salary(int bonus) const = 0;
    virtual int calc_base_salary(int salaryValue, int workTimeValue) const = 0;
};

class Project_Budget {
 public:
    virtual ~Project_Budget() = default;
    virtual int calc_budget_part(float part) const = 0;
    virtual int calc_pro_additions() const = 0;
};

#endif
