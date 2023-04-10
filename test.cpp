#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A_test_exception {};

class beche;

class Human
{
public:
    Human(string n, int h, int w) : name(n), height(h), weight(w) {}
    void akbar(int asghar);
    void add_beche(beche *b);
    void print();

protected:
    string name;
    int height;
    int weight;
    vector<beche*> becha;
};


void Human::akbar(int asghar)
{
    
    try 
    {
        
        throw A_test_exception();

    }catch(A_test_exception ex)
    {
        cerr << "wrong asghar" << endl;
    }
}

void Human::add_beche(beche *b)
{
    becha.push_back(b);
}

// void Human::print()
// {
//     becha[0]->farhad();
// }


class beche 
{
public:
    beche(string nick) : nick_name(nick) {};
    void farhad(int farshad);
    void specs();
private:
    string nick_name;
};


void beche::farhad(int farshad)
{
    cout << "Va Ama Farshad: " << farshad << endl;
}

void beche::specs()
{
    cout << nick_name << endl;
}


int main()
{
    beche Arman("Armi");
    Arman.farhad(80);
    Human beratali("barati", 170, 70);
    beratali.add_beche(&Arman);

}