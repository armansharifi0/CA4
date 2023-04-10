#include <iostream>
#include <vector>
using namespace std;

class UndefinedOperation {};

class Employee
{
public:
    virtual int earning(int hour);
};


int Employee::earning(int hour)
{
    try
    {
        throw UndefinedOperation();
    }
    catch(UndefinedOperation ex)
    {
        cerr << "The chosen operation isn't defined for this class" << endl;
    }
    return 0;
}


class Stable_Wage_Employee : public Employee
{
public:
    Stable_Wage_Employee(int w)
        : wage(w) {}
    virtual int earning(int hour);
private:
    int wage;
};

int Stable_Wage_Employee::earning(int hour)
{
    return wage * hour;
}


class Variable_Wage_Employee : public Employee
{
public:
    Variable_Wage_Employee(int s)
        : salary(s) {}
    virtual int earning(int hour);
private:
    int salary;
};

int Variable_Wage_Employee::earning(int hour)
{
    int wage = salary / hour;
    if (hour > 140)
    {
        int extra_hour = 180 - hour;
        return ((140 * wage) + (extra_hour * 1.5 * (wage)));
    }else
    {
        return wage * hour;
    }
    
}



class Organization
{
public:
    void add_Employee(Employee *E);
    int total_earnings(int avg_hrs);
private:
    vector<Employee*> Employees;
};


void Organization::add_Employee(Employee *E)
{
    Employees.push_back(E);
}

int Organization::total_earnings(int avg_hrs)
{
    int total = 0;
    for (int i = 0; i < Employees.size(); i++)
    {
        total += Employees[i]->earning(avg_hrs);
    }
    return total;
}


int main()
{
    Stable_Wage_Employee e1(15);
    Variable_Wage_Employee e2(2000);
    Organization o1;
    o1.add_Employee(&e1);
    o1.add_Employee(&e2);

    cout << o1.total_earnings(180) << endl;
    
}

