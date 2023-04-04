#include <iostream>
#include "account.hpp"
#include "transaction.hpp"


account::account(int unique_id, vector<customer*> _customers, double _balance)
{
    id = unique_id;
    customers = _customers;
    balance = _balance;
    
}

void account::set_transaction(transaction* _transaction)
{
    transactions.push_back(_transaction);
}




void account::set_balance(double change)
{
    balance += change;
}


void account::print_details()
{
    cout << "Balance : " << balance << endl;

    cout << "Owners : ";
    if (customers.size() > 1)
    {   
        for (int i = 0; i < customers.size() - 1; i++)
            cout << customers[i]->get_name() << " , ";
        cout << customers[customers.size() - 1]->get_name() << endl;
    }else
    {

        cout << customers[0]->get_name() << endl;

    }

    

    cout << "Transactions:" << endl;
    for (int i = 0; i < transactions.size(); i++ )
    {
        string printed_status;
        if (transactions[i]->get_status() == ACCEPTED)
            printed_status = "accepted";
        else if (transactions[i]->get_status() == REJECTED)
            printed_status = "rejected";
        else
            printed_status = "pending";

        cout << "[" << i + 1 << "] " << transactions[i]->get_amount() 
            << " to " << transactions[i]->get_dest_account()->get_account_id()
            <<  " -> " << printed_status << endl;

    }
}
