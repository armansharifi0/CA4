#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public:
    Employee (int s, int h);
    int earning();
protected:
    int salary;
    int hour;
};

Employee::Employee(int s, int h)
{
    salary = s;
    hour = h;
}

int Employee::earning()
{
    return salary;
}

class Tactical_Employee : public Employee
{
public:
    Tactical_Employee(int w, int s)
        : Employee(w, s) {}
    int earning();
};

int Tactical_Employee::earning()
{
    int new_wage = 1.5 * (salary/hour);
    int extra_hour = hour - 140;
    return Employee::earning() + new_wage * extra_hour;
}



class Organization
{
public:
    Organization(vector<Employee> Es = {}, vector<Tactical_Employee> TEs = {});
    void add_Employee(Employee E);
    void add_TacEmployee(Tactical_Employee TE);
    int total_earnings(int avg_hrs);
private:
    vector<Employee> Employees;
    vector<Tactical_Employee> Tatical_Employees;
};


Organization::Organization(vector<Employee> Es = {}, vector<Tactical_Employee> TEs = {})
{
    Employees = Es;
    Tatical_Employees = TEs;
}

void Organization::add_Employee(Employee E)
{
    Employees.push_back(E);
}

void Organization::add_TacEmployee(Tactical_Employee TE)
{
    Tatical_Employees.push_back(TE);
}


