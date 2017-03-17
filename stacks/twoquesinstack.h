#ifndef TWOQUESINSTACK_H_INCLUDED
#define TWOQUESINSTACK_H_INCLUDED
#include"myqueuearr.h"
//template<typename S>
class stackasarray
{
queue Q1;
queue Q2;
public:
    stackasarray():Q1(),Q2(){}
    void push(const int&);
    void pop();
    const int&  head();
    bool ifempty();
};
void stackasarray:: push(const int & el)
{
    Q1.enqueue(el);
    return;
}
void stackasarray::pop()
{
    while(Q1.getfront()!=Q1.getrear()-1)
    {
        Q2.enqueue(Q1.top());
        Q1.dequeue();
    }
    while(!(Q2.isempty()))
    {
        Q1.enqueue(Q2.top());
        Q2.dequeue();
    }
    return;
}
const int&stackasarray::head()
{
    while(Q1.getfront()!=Q1.getrear()-1)
    {
        Q2.enqueue(Q1.top());
        Q1.dequeue();
    }
    cout<<
  const  int &k=Q1.top();
    while(!(Q2.isempty()))
    {
        Q1.enqueue(Q2.top());
        Q2.dequeue();
    }
    return k;
}
bool stackasarray::ifempty()
{
    return Q1.isempty();
}

#endif // TWOQUESINSTACK_H_INCLUDED
