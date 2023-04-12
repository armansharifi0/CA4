#include <iostream>
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
        void insert_node(Node *p){
            p->next = current;
            p->prev = current->prev;
            current->prev->next = p;
            current->prev = p;
        }
        void pointed_node(){
            current->next->prev = current->prev;
            current->prev->next = current->next;
            Node *q = current;
            current = current->next;
            delete q;
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
    Node* head() { return _head; }
    Node* last() { return _last; }
    Iterator get_iterator() {
        return Iterator(_head);
    }
    void merge(List *list)
    {
        Iterator this_it = Iterator(_head);
        Iterator list_it = Iterator(list->head());
        Iterator last_picked = Iterator(NULL);

        if (this_it.current->data > list_it.current->data)
            {
                last_picked.current = list_it.current;
                _head = list_it.current;
                list_it.current = list_it.current->next;
            }else
            {
                last_picked.current = this_it.current;
                this_it.current = this_it.current->next;
            }
                
        while(last_picked.current != NULL)
        {
            if (this_it.current == NULL)
            {
                _last = list_it.current;
                last_picked.current->next = list_it.current;
                list_it.current->prev = last_picked.current;
                list_it.current = list_it.current->next;
                last_picked.current = last_picked.current->next;
            }else if (list_it.current == NULL)
            {
                last_picked.current->next = this_it.current;
                this_it.current->prev = last_picked.current;
                this_it.current = this_it.current->next;
                last_picked.current = last_picked.current->next;
            }

            if (this_it.current->data > list_it.current->data)
            {
                last_picked.current->next = list_it.current;
                list_it.current->prev = last_picked.current;
                list_it.current = list_it.current->next;
                last_picked.current = last_picked.current->next;

            }else
            {
                last_picked.current->next = this_it.current;
                this_it.current->prev = last_picked.current;
                this_it.current = this_it.current->next;
                last_picked.current = last_picked.current->next;
            }
        }
    }
private:
    Node* _head;
    Node* _last;
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