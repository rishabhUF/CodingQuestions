#ifndef MYSTACKSLIST_H_INCLUDED
#define MYSTACKSLIST_H_INCLUDED
//template<typename T>
#include<iostream>
using namespace std;
class node
{
    int  data;
    node*next;
public:
    node(const int&el):next(0),data(el){}
    //template<typename V>
    friend class stacklist;
};
//template<typename S>
class stacklist
{
    node*front;
public:
    stacklist():front(0){};
    void push(const int&);
    void pop();
   const  int&top();
    bool isempty();
};
void stacklist::push(const int&el)
{
        node*ptr=new node(el);
        ptr->next=front;
        front=ptr;
}
void stacklist::pop()
{
   if (isempty())
   {
       cout<<"empty list";
       return;
   }
   node*temp=front;
   front=front->next;
   delete temp;
}
const int& stacklist::top()
 {
     return front->data;
 }
bool stacklist::isempty()
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
#endif // MYSTACKSLIST_H_INCLUDED
