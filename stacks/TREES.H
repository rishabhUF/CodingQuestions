#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED
#include<vector>
#include<queue>
template <typename T>
class gtnode
{
T data;
vector<gtnode*>children;
gtnode*parent;
public:
    gtnode():parent(NULL){}
    gtnode(const T&el):data(el),parent(NULL){}
    const T& getdata()const
    {
        return data;
    }
    template<typename V>
    friend class genrictree;
};
template<typename T>
class generictree
{
    gtnode<T>*root;
    static void printprehelp(gtnode<T>*root)
    {
        cout<<root->data<<" ";
        for(int i=0;i<root->children.size():i++)
        {
            printprehelp(root->children[i]);
        }
    }
    static gtnode<T>*findlargest(gtnode<T>*root)
    {
        gtnode<T>*largest=root;
        for(int i=0;i<root->children.size();i++)
        {
            gtnode<T>*temp=findlargest(root->children[i]);
            if(temp->data)
        }
    }
    static void  printhelp_atk(gtnode<T>*root,int k)
    {
        if(k==0)
        {
            cout<<root->data<<"  ";
            return;
        }
        for(int i=0;i<root->children.size(),i++)
        {
            printhelp_atk(root->children[i],k-1);
        }
    }
    static int heightofnode(gtnode<T>*root)
{
    if(root->children.size()==0)
    {
        return 0;
    }
    int max=0;
    for(int i=0;i<root->children.size();i++)
    {
        int temp=heightofnode(root->children[i]);
        if(temp>max)
        {
            max=temp;
        }
    }
    return max+1;
}
void clearhelp(gtnode<T>*root)
{
if(root->children.size[i]==0)
 {
     delete root;
     return;
 }
for(int i=0;i<root->children.size();i++)
{
    clearhelp(root->children[i]);
}
delete root;
}
static int numOfNodesLar(gtnode<T>*root,const T&d)
{
    if(root->children.size()==0)
    {
        return 0;
    }
    for(int i=0;i<root->children.size();i++)
    {
        if(root->data>d)
        {
            return 1+numOfNodesLar(root->children[i]);
        }
        else
        {
            return numOfNodesLar(root->children[i]);
        }
    }
}
public:
    generictree():root(NULL){}
    void createtree()
    {
        if(root!=NULL)
        {
            throw "tree already exists";
        }
        T el;
        cout<<"data for root node";
        root =new gtnode<T>(el);
        queue<gtnode<T>*>Q;
        Q.push(root);
        while(!Q.empty())
        {
            gtnode<T>*temp=Q.front();
            Q.pop();
            cout<<"child count for node with data"<<root->data<<" ";
            cin>>count;
            for(int i=0;i<count;i++)
            {
             cout<<"enter data for child"<<i<<"  ";
             cin>>el;
             gtnode<T>*child=new gtnode<T>(el);
             child->parent=temp;
             temp->children.push_back(child);
             Q.push(child);
            }
        }
        Q.push(root);
    }
    void printpreorder()
    {
        if(root==NULL)
        {
            return;
        }
        printprehelp(root);
    }
    int heightoftree()
    {
        if(root==NULL)
        {

        }
    }
    void clear()
    {
        if(root==0)
        {
            return;
        }
        clearhelp(root);
        root=NULL;
    }
    ~generictree()
    {
        clear();
    }
};
#endif // TREES_H_INCLUDED
