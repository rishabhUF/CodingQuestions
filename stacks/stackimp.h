#ifndef STACKIMP_H_INCLUDED
#define STACKIMP_H_INCLUDED
#include<iostream>
using namespace  std;
template<typename T>
class stacks
{
    T arr[100];
    int top;
    void postfixhelper(const T&);
public:
    stacks():top(-1){}
    void push(const T&);
    void pop();
    const T&topdata()
    {
       // cout<<top;
        return arr[top];
    }
    const T&size()
    {
        return (sizeof(arr)/sizeof(arr[0]));
    }
    bool ifempty();
    bool iffull();
};
template<typename T>
void stacks<T>::push(const T &el)
{
    top++;
    arr[top]=el;
}
template<typename T>
void stacks<T>::pop()
{
    arr[top]=NULL;
    top--;
}
template<typename T>
bool stacks<T>::ifempty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<typename T>
bool stacks<T>::iffull()
{
    if(top==size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif // STACKIMP_H_INCLUDED
