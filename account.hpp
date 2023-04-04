#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__


#include <vector>
#include "customer.hpp"
#include "transaction.hpp"
using namespace std;

class account
{
public:
    account(){};
    account(int unique_id, vector<customer*> _customers, double _balance);
    int get_account_id() { return id; }
    vector<customer*> get_customers() { return customers; }
    void set_customer(customer* cu);
    int get_balance() { return balance; }
    void set_transaction(transaction* _transaction);
    void set_balance(double change);
    void print_details();
    vector<transaction*> get_transactions() { return transactions; }
private:
    int id;
    vector<customer*> customers;
    double balance;
    vector<transaction*> transactions;
};



#endif