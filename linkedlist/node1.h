#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include<iostream>
using namespace std;
template <typename T>
class node
{
    <T>  data;
    node*next;
public:
    node<T>(T d):next(0),data(d){}
    template <typename Q>
    friend class linklist<Q>;
};
template<typename V>
class linklist
{
  node<V>*head;
  public:
      linkedlist<V>:head(0){}
      node<V>*createlist1()
      {
          node<V>*pre=0;
          cin>>x;
          while(x!=-1)
          {
              node<V>*temp=new node<V>;
              temp->data=x;
              temp->next=0;
              if(!head)
              {
                 head=temp;
                 pre=head;
              }
              pre->next=temp;
              pre=temp;
              cin>>x;
          }
          return head;
      }
     void printList() const//WONT MODify the data
      {
        Node * it = head;
        while (it != NULL) {
            cout << it->getData() <<"-->";
            it = it->getNext();
        }
        cout << "NULL" << endl;
        }
};


#endif // NODE_H_INCLUDED
