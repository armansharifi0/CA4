#include "customer.hpp"



customer::customer(string _name)
{
    
    static int customer_number = 0;
    name = _name;
    id = customer_number++;
    
}


