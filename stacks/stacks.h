#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED
template <typename T>
class node
{
    T data;
    node*next;
public:
    node():next(0){}
    node(const T&el):next(0),data(el){}
    template <typename V>
    friend class stackasll;
};
template <typename T>
class stackasll
{
    node<T>*head;
    void copyas(const stackasll &S)
    {
        node<T>*it=S.head;
        node<T>*prev=0;
        while(it)
        {
            node<T>*temp=new node<T>(*it);
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                prev->next=temp;
            }
            it=it->next;
            prev=temp;
        }
    }
   public:
       void clear()
       {
           while(head)
           {
               node<T>*nextnode=head->next;
               delete head;
               head=nextnode;
           }
       }
    stackasll():head(0){}
    stackasll(const stackasll &S):head(0)
    {
        copyas(S);
    }
    ~stackasll()
    {
        clear();
    }
    stackasll operator=(const stackasll&S)
    {
        clear();
        copyas(S);
        return *this;
    }
    void push(const T& el)
    {

        node<T>*temp=new node<T>(el);
        temp->next=head;
        head=temp;
    }
    void pop()
    {
        if(head==NULL)
        {
            return;
        }
        node<T>*temp=head;
        head=head->next;
        delete temp;
    }
    const T& top() const
    {
        return head->data;
    }
    bool isempty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif // STACKS_H_INCLUDED
