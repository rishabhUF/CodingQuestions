#ifndef MYQUEUELIST_H_INCLUDED
#define MYQUEUELIST_H_INCLUDED
//template<typename N>
#include<iostream>
using namespace std;
class node
{
    int  data;
    node* next;
public:
    node(const int&el):data(el),next(0){}
   // template <typename T>
     friend class queue;
};
class queue
{
    node*front;
    node*rear;
public:
    queue():front(0),rear(0){}
    void enqueue(const int& );
    void dequeue();
    const int&top();
    bool isempty();

};
void queue::enqueue(const int&el)
{
     node*ptr=new node(el);
    if(front==0)
    {
        front=ptr;
        rear=ptr;
        return;
    }
    else
    {
     rear->next=ptr;
     rear=ptr;
     return;
    }
}
void queue::dequeue()
{
    if(isempty())
    {
        cout<<"que empty";
        return;
    }
    node*temp=front;
    front=front->next;
    delete temp;
    return;
}
const int& queue::top()
{
    return front->data;
}
bool queue::isempty()
{
    if(!front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif // MYQUEUELIST_H_INCLUDED
