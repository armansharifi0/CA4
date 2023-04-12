#include <iostream>
using namespace std;

class Node {
public:
    Node(int d, Node *n = NULL, Node *p = NULL) 
        : data(d), next(n), prev(p) {}

    int data;
    Node *next;
    Node *prev;
};

class List {
public:
    List();
    ~List();
    void print();
    void push_front(int x);
    void push_back(int x);
    Node* head() { return _head; }
    Node* last() { return _last; }
    void clear();
    bool key_check(int key);
    bool rec_key_check(Node *&p, int &key);
    void push_back(List *list);
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

void List::push_front(int x) {
    Node *new_node = new Node(x);
    new_node->next = _head;
    if (_head != NULL)
        _head->prev = new_node;
    _head = new_node;
    if (_last == NULL)
        _last = new_node;
}

void List::push_back(int x) {
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


bool List::key_check(int key)
{
    for (Node* p = _head; p != NULL; p = p->next)
    {
        if (p->data == key)
            return true;
        else
            return false;
    }
    return false;
}

bool List::rec_key_check(Node *&p, int &key)
{
    if (p == NULL)
        return false;
    if (p->data == key)
        return true;
    return rec_key_check(p->next, key);
}

void List::push_back(List *list)
{
    Node* new_node = new Node(list->head()->data, list->head()->next, _last);
    _last->next = new_node;
    _last = list->last();
}

int main() {
    List l;
    
    l.push_back(86);
    l.push_front(43);
    l.push_front(12);
    
    l.print();
    cout << endl;

    int sum = 0;
    for (Node* p = l.head(); p != NULL; p = p->next)
        sum += p->data;        
    cout << sum << endl;


    List l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
}