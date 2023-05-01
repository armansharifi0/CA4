#include <iostream>
#include <vector>
using namespace std;



template <typename T>
class List {
private:

    class Node {
    public:
        Node(T d, Node *n = NULL, Node *p = NULL) 
            : data(d), next(n), prev(p) {}

        T data;
        Node *next;
        Node *prev;
    };

public:
    class Iterator {
    public:
        T next_element() {
            T to_be_returned = current->data;
            current = current->next;
            return to_be_returned;
        }
        bool has_more_elements() {
            return current != NULL;
        }
    private:
        Node *current;
        Iterator(Node* n) { current = n; }
        friend class List;
    };

public:
    List();
    ~List();
    List(const List<T>& l);
    void print();
    void push_front(T x);
    void push_back(T x);
    void clear();
    Iterator get_iterator() {
        return Iterator(_head);
    }
private:
    Node* _head;
    Node* _last;
};

template <typename T>
List<T>::List() {
    _head = NULL;
    _last = NULL;
}

template <typename T>
List<T>::List(const List<T>& l)
{
    Node* q = new Node(l._head->data, l._head->next);
    _head = q;
    Node* temp_ptr = l._head->next;

    while (temp_ptr != l._last)
    {
        q = new Node(temp_ptr->data, temp_ptr->next, temp_ptr->prev);
        temp_ptr = temp_ptr->next;
    }

    q = new Node(temp_ptr->data, NULL, temp_ptr->prev);
    _last = q;

}

template <typename T>
void List<T>::print() {
    for (Node* p = _head; p != NULL; p = p->next)
        cout << p->data << ' ';
}

template <typename T>
void List<T>::push_front(T x) {
    Node *new_node = new Node(x);
    new_node->next = _head;
    if (_head != NULL)
        _head->prev = new_node;
    _head = new_node;
    if (_last == NULL)
        _last = new_node;
}

template <typename T>
void List<T>::push_back(T x) {
    if (_head == NULL)
        push_front(x);
    else {
        Node *new_node = new Node(x);
        new_node->prev = _last;
        _last->next = new_node;
        _last = new_node;
    }
}

template <typename T>
List<T>::~List() {
    cout << "--destructor called\n";
    clear();
}

template <typename T>
void List<T>::clear() {
    Node *p = _head;
    while (p != NULL) {
        Node *q = p;
        p = p->next;
        delete q;
    }
    _head = NULL;
    _last = NULL;
}


class Element
{
public:
    virtual int sumation() = 0;
};



class NumberElement : public Element
{
public:
    NumberElement(int n): number(n) {}
    virtual int sumation();
private:
    int number;
};


int NumberElement::sumation()
{
    return number;
}

class ListElement : public Element
{
public:
    ListElement(List<Element*> l) : list(l) {}
    ListElement() {}
    void add_element(Element* e);
    virtual int sumation();
    List<Element*> get_list() { return list; }
// private:
    List<Element*> list;

};

void ListElement::add_element(Element* e)
{
    list.push_back(e);
}

int ListElement::sumation()
{
    int sum = 0;
    List<Element*>::Iterator it = list.get_iterator();
    while (it.has_more_elements())
        sum += it.next_element()->sumation();
    return sum;
}


class GeneralList
{
public: 
    void add_element(Element* e);
private:
    vector<Element*> Elements;
};


void GeneralList::add_element(Element* e)
{
    Elements.push_back(e);
}


int main() {

    NumberElement n1(10);
    NumberElement n2(20);
    ListElement e1;
    e1.add_element(&n1);
    e1.add_element(&n2);

    NumberElement n3(30);
    NumberElement n4(40);
    ListElement e2;
    e2.add_element(&n3);
    e2.add_element(&n4);
    e2.add_element(&e1);

    List<Element*>::Iterator it = e2.get_list().get_iterator();
    while (it.has_more_elements())
        cout << it.next_element() << endl;
    

    // List<int> l;
    
    // l.push_back(86);
    // l.push_front(43);
    // l.push_front(12);
    
    // l.print();
    // cout << endl;

    // int sum = 0;
    
    // List<int>::Iterator it = l.get_iterator();
    // while (it.has_more_elements())
    //     sum += it.next_element();
        
    // cout << sum << endl;
}