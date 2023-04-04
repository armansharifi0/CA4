#include "transaction.hpp"
#include "customer.hpp"
#include "account.hpp"
#include <cstdlib>
#include <iostream>



transaction::transaction(account* _source, account* _dest, double _amount)
{

    static int transaction_number_gen = 0;
    id = transaction_number_gen++;
    source = _source;
    dest = _dest;
    amount = _amount;
    status = PENDING;
    for ( customer* x : _source->get_customers())
        owners_id.push_back(x->get_customer_id());
    

} 

int transaction::__uid_generator;


void transaction::transaction_process(Status reply, int _owner_id)
{
    for ( int x : owners_id )
        if (x == _owner_id)
        {
            bool checker = true;
            for (int i = 0; i < owners_reply.size(); i ++)
            {
                if (owners_reply[i].id == _owner_id)
                {
                    cout << "Wrong command, the owner has approved already." << endl;
                    checker = false;
                }
            }
            if (checker = true)
            {
                owner_reply y;
                y.id = _owner_id;
                y.st = reply;

                if (reply == ACCEPTED)
                    owners_reply.push_back(y);
                else if (reply == REJECTED)
                    owners_reply.push_back(y);
            }
            
            
        }
    
    if (owners_reply.size() == owners_id.size())
        set_status();


}


    




void transaction::set_status()
{
    status = ACCEPTED;
    for ( owner_reply x : owners_reply )
        if (x.st == REJECTED)
            status = REJECTED;
    
    if (status == ACCEPTED && amount <= source->get_balance())
    {
        source->set_balance(-1*amount);
        dest->set_balance(amount);
    }else
        status = REJECTED;
            

}

