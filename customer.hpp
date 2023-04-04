#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__


#include <string>
using namespace std;

 

class customer{
public:
    customer(){};
    customer(string _name);
    int get_customer_id(){ return id; }
    string get_name(){ return name; }
private:
    string name;
    int id;

};







#endif