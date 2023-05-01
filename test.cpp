#include <iostream>
using namespace std;

class shayan
{
public:
    virtual void ashkan() = 0;
};

class mahan : public shayan
{
public:
    virtual void ashkan();
};



int main() 
{
    mahan arshia;
    arshia.ashkan();
}
				