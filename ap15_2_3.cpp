#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node(string d, Node *n = NULL, Node *p = NULL) 
        : data(d), next(n), prev(p) {}

    string data;
    Node *next;
    Node *prev;
};

class List {
public:
    List();
    ~List();
    void print();
    void push_front(string x);
    void push_back(string x);
    Node* head() { return _head; }
    Node* last() { return _last; }
    void clear();
private:
    Node* _head;
    Node* _last;
};

List::List() {
    _head = NULL;
    _last = NULL;
}

void List::print() {
    for (Node* p = _head; p != NULL; p = p->next)
        cout << p->data << ' ';
}

void List::push_front(string x) {
    Node *new_node = new Node(x);
    new_node->next = _head;
    if (_head != NULL)
        _head->prev = new_node;
    _head = new_node;
    if (_last == NULL)
        _last = new_node;
}

void List::push_back(string x) {
    if (_head == NULL)
        push_front(x);
    else {
        Node *new_node = new Node(x);
        new_node->prev = _last;
        _last->next = new_node;
        _last = new_node;
    }
}

List::~List() {
    clear();
}

void List::clear() {
    Node *p = _head;
    while (p != NULL) {
        Node *q = p;
        p = p->next;
        delete q;
    }
    _head = NULL;
    _last = NULL;
}

template<typename MyList>
class ExList: public List
{
public:
    void remove_last();
};

template<typename MyList>
void ExList<MyList>::remove_last()
{
    Node *q = this->last();
    
}


int main() {
    List l;
    
    l.push_back("akbar");
    l.push_front("asghar");
    l.push_front("shayan");
    
    l.print();
    cout << endl;



    List l2;
    l2.push_back("ashkan");
    l2.push_back("farhad");
    l2.push_back("farshad");
}