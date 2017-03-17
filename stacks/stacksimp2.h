#ifndef STACKSIMP2_H_INCLUDED
#define STACKSIMP2_H_INCLUDED
class node
{
    int data;
    node*next;
public:
    node(const int&el):data(el),next(0){}
    friend class stacksll;
};
class stacksll
{
    node*top;
public:
    stackasll():head(0){}
    void push(const int&el);
    void pop();
    const int&topdata()const
    {
        return top->data;
    }
bool ifempty();
};
void stacksll::push(const int&el)
{
    node*temp=new node(el)
    if(head==0)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
    return;
}
void stacksll::pop()
{
    node*temp=head;
    head=head->next;
    delete temp;
    return;
}
bool stacksll::ifempty()
{
    if(head==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif // STACKSIMP2_H_INCLUDED
