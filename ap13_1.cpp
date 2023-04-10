#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInt
{
public:
    BigInt(int _number);
    BigInt (string _number);
    vector<int> get_numbers() { return numbers; }
    BigInt operator+(BigInt _number);
    BigInt operator+(int i_number);
    void operator+=(BigInt _number);
    void operator+=(int i_number);
    bool operator==(BigInt _number);
private:
    vector<int> numbers;
};


    


vector<int> itov(int _number)
{
    vector<int> temp;
    while (_number != 0)
    {
        temp.push_back(_number % 10);
        _number = _number / 10;
    }
    return temp;
}

vector<int> digits_sum(vector<int> number1, vector<int> number2)
{
    vector<int> temp;
    for (int i = 0; i < number1.size(); i++)
        {
            if (i < number2.size())
            {
                temp.push_back((number1[i] + number2[i]) % 10);
                number1[i+1] = number1[i+1] + ((number1[i] + number2[i]) / 10);
            }else
            {
                temp.push_back(number1[i] % 10);
                number1[i+1] +=  (number1[i] / 10);
            }
        }
        return temp;
}

BigInt::BigInt(int _number)
{
    vector<int> temp;
    while (_number != 0)
    {
        numbers.push_back(_number % 10);
        _number = _number / 10;
    }

}


BigInt::BigInt(string _number)
{
    for (int i = _number.size() - 1; i >= 0; i--)
    {
        numbers.push_back(_number[i] - '0');
    }
}

BigInt BigInt::operator+(BigInt _number)
{
    vector<int> temp;
    if (numbers.size() >= _number.get_numbers().size())
    {

        temp = digits_sum(numbers, _number.get_numbers());

    }else
    {
        temp = digits_sum(_number.get_numbers(), numbers);
    }
    string temp2;
    for(int i = temp.size() - 1; i >= 0; i--)
    {
        temp2.push_back(int(temp[i] + '0'));
    }
    return BigInt(temp2);

}

BigInt BigInt::operator+(int i_number)
{
    vector<int> temp;
    vector<int> _number = itov(i_number);
    if (numbers.size() >= _number.size())
    {

        temp = digits_sum(numbers, _number);

    }else
    {
        temp = digits_sum(_number, numbers);
    }
    string temp2;
    for(int i = temp.size() - 1; i >= 0; i--)
    {
        temp2.push_back(int(temp[i] + '0'));
    }
    return BigInt(temp2);

}


BigInt operator+(int number,BigInt _number)
{
    vector<int> temp;
    vector<int> numbers = itov(number);
    if (numbers.size() >= _number.get_numbers().size())
    {

        temp = digits_sum(numbers, _number.get_numbers());

    }else
    {
        temp = digits_sum(_number.get_numbers(), numbers);
    }

    string temp2;
    for(int i = temp.size() - 1; i >= 0; i--)
    {
        temp2.push_back(int(temp[i] + '0'));
    }
    return BigInt(temp2);
}


void BigInt::operator+=(BigInt _number)
{
    vector<int> temp;
    if (numbers.size() >= _number.get_numbers().size())
    {

        temp = digits_sum(numbers, _number.get_numbers());

    }else
    {
        temp = digits_sum(_number.get_numbers(), numbers);
    }
    numbers = temp;

}

void BigInt::operator+=(int i_number)
{
    vector<int> temp;
    vector<int> _number = itov(i_number);
    if (numbers.size() >= _number.size())
    {

        temp = digits_sum(numbers, _number);

    }else
    {
        temp = digits_sum(_number, numbers);
    }
    numbers = temp;

}

bool BigInt::operator==(BigInt _number)
{
    bool result = true;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != _number.get_numbers()[i])
            result = false;
    }
    return result;
}

ostream& operator<<(ostream& out, BigInt& c) 
{

    for (int i = c.get_numbers().size() - 1; i >= 0; i--)
    {
        out << c.get_numbers()[i];
    }
    
    return out;
}


int main()
{
    BigInt a(211);
    BigInt b(211);
    bool c = a == b;
    cout << c << endl;
}