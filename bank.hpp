#ifndef __BANK_HPP__
#define __BANK_HPP__




#include <iostream>
#include <vector>
#include "account.hpp"
#include "customer.hpp"
#include "transaction.hpp"
using namespace std;

class bank{
public:
    bank();
    void create_customer(string name);   
    void make_account(vector<int> _customers_id,double balance);
    void add_owner(int account_id, int owner_id);
    void book_transaction(int _source, int _dest, double _amount);
    void inquiry_transaction(Status reply,int transaction_id, int owner_id);
    void show_account(int account_id);
    vector<account*> get_accounts() { return accounts; }
    vector<transaction*> get_transactions() { return transactions; }

private:
    
    int account_number;
    vector<account*> accounts;
    vector<customer*> customers;
    vector<transaction*> transactions;

};


#endif