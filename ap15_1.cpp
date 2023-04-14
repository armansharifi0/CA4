#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10

class invalid_operation_ex {};
template<typename T>
class stack {
public:
    stack(int size);
    ~stack();
    stack(const stack&);
    void push(T x);
    void pop();
    T top() const;
    int elem_count() const { return count; }
    stack& operator=(const stack&);
private:
    T *elements;
    int size;
    int count;
};

template<typename T>
stack<T>::stack(int s = DEFAULT_SIZE) {
    cout << "--constructor called\n";
    size = s;
    elements = new int[size];
    count = 0;
}

template<typename T>
stack<T>::~stack() {
    cout << "--destructor called\n";
    delete[] elements;
}

template<typename T>
stack<T>::stack(const stack& s) {
    cout << "-- copy constructor called\n";
    size = s.size;
    count = s.count;
    elements = new int[size];
    for (int i = 0; i < count; i++)
        elements[i] = s.elements[i];
}

template<typename T>
void stack<T>::push(T x) {
    if (count >= size)
        throw invalid_operation_ex();

    elements[count] = x;
    count++;
}

template<typename T>
void stack<T>::pop() {
    if (count > 0)
        count--;
    else
        throw invalid_operation_ex();
}

template<typename T>
T stack<T>::top() const {
    if (count > 0)
        return elements[count-1];
    else
        throw invalid_operation_ex();
}

template<typename T>
stack<T>& stack<T>::operator=(const stack& s)
{
    if (this == &s)
        return *this;
        
    count = s.count;
    size = s.size;
    delete[] elements;
    elements = new int[size];
    for (int i = 0; i < count; i++)
        elements[i] = s.elements[i];
        
    return *this;
}

int main() {
    stack<int> s;
    s.push(4);
    cout << s.top() << endl;
}