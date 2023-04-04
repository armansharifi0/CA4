#include <iostream>



using namespace std;


void shayan()
{
    static int arman = 0;
    arman = 0;
    cout << ++arman << endl;
}



class mahan
{
public:
    
    mahan();
    static void print_hooshang(){ cout << "hooshang" << endl; }
    int id;
    
    
};



mahan::mahan()
{
     static int hooshang = 4;
        id = hooshang++; 
}

int main()
{


    mahan M;
    mahan K;
    mahan A;
    

    cout << M.id << endl;
    cout << K.id << endl;
    cout << A.id << endl;
    shayan();
    shayan();

    cout << "Hello World!" << endl;
    return 0;
}