#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DEFAULT_SIZE 10
class BigInt
{
public:
    BigInt(int _number);
    BigInt(string _number);
    BigInt(const BigInt& b);
    ~BigInt();
    int* get_numbers() { return numbers; }
    int get_size() { return size; }
    BigInt operator+(BigInt _number);
    BigInt operator+(int i_number);
    void operator+=(BigInt _number);
    void operator+=(int i_number);
    bool operator==(BigInt _number);
    BigInt& operator=(const BigInt& b);
private:
    int *numbers;
    int size;
};

vector<int> array_to_vector(int array[], int size)
{
    vector<int> temp;
    for (int i = 0; i < size; i++)
    {
        temp.push_back(array[i]);
    }
    return temp;
}

    


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
    size = 0;
    int _number_2 = _number;
    while (_number_2 != 0)
    {
        _number_2 /= 10;
        size++;
    }
    numbers = new int[size];
    for (int i = 0; i < size; i++)
    {
        numbers[i] = _number % 10;
        _number /= 10;
    }

}


BigInt::BigInt(string _number)
{
    size = _number.size();
    numbers = new int[size];

    for (int i = 0; i < size ; i++)
    {
        numbers[i] = _number[size - i - 1] - '0';
    }
}


BigInt::~BigInt()
{
    delete[] numbers;
}


BigInt::BigInt(const BigInt& b)
{
    size = b.size;
    numbers = new int[size];
    for (int i = 0; i < size; i++)
        numbers[i] = b.numbers[i];
}


BigInt BigInt::operator+(BigInt _number)
{
    vector<int> temp;
    if (size >= _number.get_size())
    {

        temp = digits_sum(array_to_vector(numbers, size), array_to_vector(_number.get_numbers(), _number.get_size()));

    }else
    {
        temp = digits_sum(array_to_vector(_number.get_numbers(), _number.get_size()), array_to_vector(numbers, size));
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
    if (size >= _number.size())
    {

        temp = digits_sum(array_to_vector(numbers, size), _number);

    }else
    {
        temp = digits_sum(_number, array_to_vector(numbers, size));
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
    if (numbers.size() >= _number.get_size())
    {

        temp = digits_sum(numbers, array_to_vector(_number.get_numbers(), _number.get_size()));

    }else
    {
        temp = digits_sum(array_to_vector(_number.get_numbers(), _number.get_size()), numbers);
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
    if (size >= _number.get_size())
    {

        temp = digits_sum(array_to_vector(numbers, size), array_to_vector(_number.get_numbers(), _number.get_size()));

    }else
    {
        temp = digits_sum(array_to_vector(_number.get_numbers(), _number.get_size()), array_to_vector(numbers, size));
    }

    delete[] numbers;
    size = temp.size();
    numbers = new int[size];
    for (int i = 0; i < size; i++)
    {
        numbers[i] = temp[i];
    }

}

void BigInt::operator+=(int i_number)
{
    vector<int> temp;
    vector<int> _number = itov(i_number);
    if (size >= _number.size())
    {

        temp = digits_sum(array_to_vector(numbers, size), _number);

    }else
    {
        temp = digits_sum(_number, array_to_vector(numbers, size));
    }

    delete[] numbers;
    size = temp.size();
    numbers = new int[size];
    for (int i = 0; i < size; i++)
    {
        numbers[i] = temp[i];
    }

}

bool BigInt::operator==(BigInt _number)
{
    bool result = true;
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] != _number.get_numbers()[i])
            result = false;
    }
    return result;
}

ostream& operator<<(ostream& out, BigInt& c) 
{

    for (int i = c.get_size() - 1; i >= 0; i--)
    {
        out << c.get_numbers()[i];
    }
    
    return out;
}

BigInt& BigInt::operator=(const BigInt& b)
{
    cout << "akbar" << endl;
    if (this == &b)
        return *this;
    
    size = b.size;
    delete[] numbers;
    numbers = new int[size];
    for (int i = 0; i < size; i++)
        numbers[i] = b.numbers[i];
    
    return *this;
}


int main()
{
    BigInt a(211);
    BigInt b(211);
    bool c = a == b ;
    cout << c << endl;

    return 0;
    
}