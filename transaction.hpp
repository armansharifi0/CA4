#ifndef __TRANSACTION_HPP__
#define __TRANSACTION_HPP__


#include <string>
#include <vector>
using namespace std;
class account;

enum Status
{
    PENDING = 0,
    ACCEPTED = 1,
    REJECTED = 2,
};

struct owner_reply
{
    int id;
    Status st;
};

class transaction
{
public:
    transaction(account* _source, account* _dest, double _amount);
    void set_status();
    account* get_source_account() { return source; }
    account* get_dest_account() { return dest; }
    vector<owner_reply> get_owners_reply() { return owners_reply; }
    int get_amount() { return amount; }
    Status get_status() { return status; }
    int get_transaction_id() { return id; }
    vector<int> get_owners_id() { return owners_id; }
    void transaction_process(Status reply, int owner_id);
    
private:
    int id;
    account* source;
    account* dest;
    double amount;
    Status status;
    vector<owner_reply> owners_reply;
    static int __uid_generator;
    vector<int> owners_id;
};



#endif