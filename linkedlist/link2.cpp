#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *createlist()//return address of the first address of the list
{
    node*head=0;//first node of the lsit
    node*prev=0;
    int x;
    cin>>x;
    while(x!=-1)
    {
        node *temp=new node;
        temp->data=x;
        temp->next=0;
        if(head==0)
        {
            head=temp;
        }
        else
        {
            prev->next=temp;
        }
        prev=temp;
        cin>>x;
    }
    return head;
}
void printlist(node*head)
{
    while(head)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
}
int main()
{
    node*head= createlist();
    printlist(head);
    return 0;
}
