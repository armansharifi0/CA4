#include "bank.hpp"
#include <functional>


bank::bank()
{
    
    account_number = 0;
    
}




void bank::make_account(vector<int> _customers_id,double balance)
{

    vector<customer*> customers_pointers;
    
    for ( int x : _customers_id )
    {

        for ( customer &y : customers )
        {
            
            if (y.get_customer_id() == x)
                customers_pointers.push_back(&y);
        }
    }
    
    accounts.push_back(account(this->account_number++, customers_pointers, balance));
    
}



void bank::create_customer(string name)
{
    
    customers.push_back(customer(name));
    
}


void bank::add_owner(int account_id, int owner_id)
{
    
    customer* intended_customer; 
    
    for ( customer &x : customers )
    {
        
        if (x.get_customer_id() == owner_id)
        {
            
            intended_customer = &x;
            break;
        }
    }
    for ( account &x : accounts )
    {
        
        if (x.get_account_id() == account_id)
        {
            
            
            x.get_customers().push_back(intended_customer);
            
            break;
        }
    }
}


void bank::book_transaction(int _source, int _dest, double _amount)
{   
    account* source_account;
    account* dest_account;

    for ( account &x : accounts )
    {
        if (x.get_account_id() == _source)
            source_account = &x;
        if (x.get_account_id() == _dest)
            dest_account = &x;
    }
    

    
    transaction* temp = new transaction(source_account, dest_account, _amount);
    transactions.push_back(temp);
    source_account->set_transaction(temp);

}


void bank::inquiry_transaction(Status reply,int transaction_id, int owner_id)
{
    for ( transaction* x : transactions )
    {
        if (x->get_transaction_id() == transaction_id)
        {
            x->transaction_process(reply, owner_id);
            break;
        }
    }

}

    



void bank::show_account(int account_id)
{

    account intended_acount;
    for ( account &x : accounts )
    {
        if ( account_id == x.get_account_id())
        {
            x.print_details();
            return;
        }
    }
}

