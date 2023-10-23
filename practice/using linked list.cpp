// linked list emplimetion of queues
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
class Queues
{
    node *head;
    node *tail;
    int size;

public:
    Queues()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void enqueue(int data)
    {
        node *new_node = new node(data);

        if (this->head == NULL)
        {
            this->head = new_node;
            this->tail = new_node;
        }
        this->tail->next = new_node;
        this->tail = new_node;
        this->size++;
    }
    void dequeue()
    {
        if (this->head == NULL)
        {
            return;
        }
        node *temp;
        node *temp2;
        temp = this->head;
        temp2 = this->head->next;
        this->head = temp2;
        if (this->head == NULL)
        {
            this->tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        this->size--;
    }
    int getsize()
    {
        return this->size;
    }
    bool isempty()
    {
        return this->head == NULL;
    }
    int fornt()
    {
        return this->head->data;
    }
};
int main()
{
    Queues qe;
    qe.enqueue(10);
    qe.enqueue(20);
    qe.enqueue(30);
    qe.enqueue(40);
    while (not qe.isempty())
    {
        cout << qe.fornt() << " ";
        qe.dequeue();
    }

    return 0;
}
