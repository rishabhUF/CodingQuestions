#ifndef MYSTACKSARR_H_INCLUDED
#define MYSTACKSARR_H_INCLUDED
#include<iostream>
using namespace std;
//template<typename S>
class stackasarray
{
    int  arr[100];
    int  index;
    int size()
    {
      int k=sizeof(arr)/sizeof(arr[0]);
      return k;
    }
public:
    stackasarray():index(0){}
    void push(const int&);
    void pop();
    const int&  top();
    bool isempty();
};
void stackasarray::push(const int&el)
{
    if(index>=size())
    {
        cout<<"stack is empty";
        return;
    }
    arr[index]=el;
    index++;
}
void stackasarray:: pop()
{
    if(isempty())
    {
        cout<<"stack is empty";
        return;
    }
    else
    {
        arr[index-1]=NULL;
        index--;
        return;
    }
}
const int& stackasarray::top()
{
    return arr[index-1];
}
bool stackasarray::isempty()
{
    if(index==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif // MYSTACKS_H_INCLUDED
