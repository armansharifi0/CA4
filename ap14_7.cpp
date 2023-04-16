#include <iostream>
#include <vector>
using namespace std;

class List {
private:
    class Node {
    public:
        Node(int d, Node *n = NULL, Node *p = NULL) 
            : data(d), next(n), prev(p) {}

        int data;
        Node *next;
        Node *prev;
    };

public:
    class Iterator {
    public:
        int next_element() {
            int to_be_returned = current->data;
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
    void print();
    void push_front(int x);
    void push_back(int x);
    void clear();
    Iterator get_iterator() {
        return Iterator(_head);
    }
private:
    Node* _head;
    Node* _last;
};


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
    ListElement(List* l) : List(l) {}
    virtual int sumation();
private:
    List* List;

};


int ListElement::sumation()
{
    int sum;
    List::Iterator it = List->get_iterator();
    while (it.has_more_elements())
        sum += it.next_element();
    return sum;
}


class GeneralList
{
public:
    ~GeneralList();
    void add_element();
private:
    vector<Element*> Elements;
};





int main() {
    List l;
    
    l.push_back(86);
    l.push_front(43);
    l.push_front(12);
    
    l.print();
    cout << endl;

    int sum = 0;
    
    List::Iterator it = l.get_iterator();
    while (it.has_more_elements())
        sum += it.next_element();
        
    cout << sum << endl;
}