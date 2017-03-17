#ifndef MYQUEUEARR_H_INLCUDED
#define MYQUEUEARR_H_INLCUDED
#include<iostream>
using namespace std;
//template <typename Q>
class queue
{
    int  arr[100];
    int front;
    int rear;
    void reverse_que(int,int);
public:
    queue():front(-1),rear(0){}
    void enqueue(const int&el);
    void dequeue();
    const int &getfront()const
    {
        return front;
    }
    const int &getrear()const
    {
        return rear;
    }
    const  int&top();
    bool isempty();
    bool isfull();
    void reverse();
};
void queue::enqueue(const int&el)
{
    if(isfull())
{
    rear=0;
    cout<<"full queue";
    return;
}
else
{
    //cout<<"step1";
     if(front==-1)
    {;
        front=0;
        arr[front]=el;
        rear++;
        return;
    }
    else
    {
       // cout<<rear<<'\n';
        arr[rear]=el;
        rear++;
    }
}
}
void queue::dequeue()
{
    if(isempty())
    {
        cout<<"queue empty";
        return;
    }
    else
    {
       // cout<<"step 2";
        arr[front]=NULL;
        front++;
        return;
    }
}
const int& queue::top()
{
    return arr[front];
}
bool queue:: isempty()
{
    if(front==-1)
    {
      //  cout<<front<<"one";
        return true;
    }
    else if(front==rear&&arr[front])
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool queue:: isfull()
{
    if(arr[front]!=NULL&&front==rear)
    {
        return true;
    }
        return false;
}
void queue::reverse_que(int temp1,int temp2)
{
    if(temp1>temp2)
    {
        return;
    }
    int temp=arr[temp1];
    arr[temp1]=arr[temp2];
    arr[temp2]=temp;
    reverse_que(temp1+1,temp2-1);
}
void queue::reverse()
{
    reverse_que(front,rear-1);
    return;
}
#endif // MYQUEUEARR_H_INLCUDED
