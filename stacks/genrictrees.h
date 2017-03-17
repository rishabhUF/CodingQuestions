#ifndef GENRICTREES_H_INCLUDED
#define GENRICTREES_H_INCLUDED
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
template<typename T>
class gen_node
{
    T data;
    vector<gen_node<T>*>children;
    gen_node*parent;
public:
    gen_node():parent(NULL){}
    gen_node(const T&el):data(el),parent(NULL){}
    const T&getdata()const
    {
        return data;
    }
    template<typename V>
    friend class gen_tree;
};
template<typename T>
class gen_tree
{
    gen_node<T>*root;
   static  void createtreehelper1(queue <gen_node<T>*>&);
   static  void createtreehelper2(queue <gen_node<T>*>&,int);
    void copyas();
   static  void clearhelp(gen_node<T>*);
   static  void postorderhelp(gen_node<T>*);
    void clear();
   static bool findpath(gen_node<T>*,stack<T>&,const T&);
   static pair<gen_node<T>*,gen_node<T>*>findsecondlargest(gen_node<T>*);
static void zigzag(queue<gen_node<T>*>&,stack<gen_node<T>*>&);
static void printlevarr2Q(queue<gen_node<T>*>&,queue<gen_node<T>*>&);
static void  greaterthanroot(gen_node<T>*,T,int&);
static void  leafnodes(gen_node<T>*,int&);
public:
    gen_tree():root(NULL){}
    void createtree();
    void postorder();
    void printiterative()const;
    static T&larger_than_k(gen_node<T>*,T& );
    vector<T> findpath(T&val);
   const gen_node<T>* findsecondlargest();
   void printlevappmar()const;
   void printlevapppair()const;
   void zigzag()const;
    void printlevarr2Q()const;
   int nodesgreaterthanroot();
   int leafnodes();

    ~gen_tree()
    {
        clear();
    }
};
template<typename T>
void gen_tree<T>::createtree()
{
    if(root)
    {
        throw "tree is already full";
    }
    T el;
    cout<<"enter data  of root";
    cin>>el;
    root=new gen_node<T>(el);
    queue<gen_node<T>*>Q;
    Q.push(root);
    createtreehelper1(Q);
    Q.push(root);
}
template<typename T>
 void gen_tree<T>::createtreehelper1(queue<gen_node<T>*>&Q)
{
    if(Q.empty())
    {
        return;
    }
 int count;
gen_node<T> * temp = Q.front();
cout << "Enter child count for node with data " << temp->data <<" ";
cin >> count;
createtreehelper2(Q,count);
 Q.pop();
createtreehelper1(Q);
}
template<typename T>
 void gen_tree<T>::createtreehelper2(queue<gen_node<T>*>&Q,int count)
{
    if(count==0)
    {
        return;
    }
   gen_node<T> * temp = Q.front();
    T el;
    cout<<"enter data for child"<<count<<"  ";
    cin>>el;
    gen_node<T> * child = new gen_node<T>(el);
    child->parent = temp;
    temp->children.push_back(child);
    Q.push(child);
    createtreehelper2(Q,count-1);
}
template<typename T>
void gen_tree<T>::clearhelp(gen_node<T>*root)
{
    if(root->children.size()==0)
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
template<typename T>
void gen_tree<T>::clear()
{
    if(!root)
    {
        return;
    }
    clearhelp(root);
}
template<typename T>
void gen_tree<T>::postorder()
{
    if (root == NULL) {
    return;
    }
    postorderhelp(root);
    return;
}
template<typename T>
void gen_tree<T>::postorderhelp(gen_node<T>*root)
{
//<<"   "<<root->children.size();
    for(int i=0;i<root->children.size();i++)
    {
        postorderhelp(root->children[i]);
    }
    cout<<root->data;
}
template<typename T>
void gen_tree<T>:: printiterative()const
  {
      queue<gen_node<T>*>Q;
      Q.push(root);
    while(!Q.empty())
    {
        gen_node<T>*temp=Q.front();
       for(int i=0;i<temp->children.size();i++)
       {
           Q.push(temp->children[i]);
       }
      cout<< temp->data<<"---> ";
       Q.pop();
    }
  }
template<typename T>
void gen_tree<T>::printlevappmar()const
{
    if(root==NULL)
    {
        return;
    }
    queue<gen_node<T>*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {
        gen_node<T>*temp=Q.front();
        Q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!Q.empty())
            {
                Q.push(NULL);
            }
       continue;
        }
        cout<<temp->data<<" ";
            for(int i=0;i<temp->children.size();i++)
            {
              Q.push(temp->children[i]);
            }
    }
}
template<typename T>
void gen_tree<T>::printlevapppair()const
{
    if(root==NULL)
    {
        return;
    }
    queue<pair<gen_node<T>*,int>>Q;
    pair<gen_node<T>*,int>P(root,0);
    Q.push(P);
    while(!Q.empty())
    {
       pair< gen_node<T>*,int>temp=Q.front();
        Q.pop();
        int currentlevel=0;
        if(temp.second !=currentlevel)
        {
            cout<<endl;
            currentlevel++;
        }
        cout<<temp.first->data<<" ";
            for(int i=0;i<temp->children.size();i++)
            {
            pair<gen_node<T>*,int>childpair(temp.first->children[i],temp.second+1);
              Q.push(childpair);
            }
    }
}
template<typename T>
 pair<gen_node<T>*,gen_node<T>*>gen_tree<T>::findsecondlargest(gen_node<T>*root)
{
    pair<gen_node<T>*,gen_node<T>*>ans(root,NULL);
    if(root->children.size()==0)
    {
        return ans;
    }
    for(int i=0;i<root->children.size();i++)
    {
        pair<gen_node<T>*,gen_node<T>*>childans=findsecondlargest(root->children[i]);
        if(childans.first->data>ans.first->data)
        {
            ans.second=ans.first;
            ans.first=childans.second;
            if(childans.second&&childans.second->data>ans.second->data)
        {
            ans.second=childans.first;
            ans.first=childans.second;
        }
        }
        else if(!ans.second||childans.first->data>ans.second->data)
        {
            ans.second=childans.first;
        }

    }
}
template<typename T>
const gen_node<T>* gen_tree<T>::findsecondlargest()
{
    if(root==NULL||root->children.size()==0)
    {
        return NULL;
    }
    pair<gen_node<T>*,gen_node<T>*>ans=findsecondlargest(root);
    return ans.second;
}
template<typename T>
 T&gen_tree<T>::larger_than_k(gen_node<T>*root,T& k)
{
    T&ans=NULL;
    if(root->children.size()==0)
    {
        return ans;
    }
    for(int i=0;i<root->children.size();i++)
    {
        return larger_than_k(root->children[i],k);
        if(ans==NULL&&root->children[i]->data>k)
        {
            ans=root->children[i]->data;
        }
       else  if(root->children[i]->data>k&&root->children[i]->data<ans)
        {
            ans=root->children[i]->data;
        }
        else
        {
            ans=NULL;
        }
    }
}
template<typename T>
vector<T> gen_tree<T>::findpath(T&val)
{
    vector<T>V;
    if(!root)
    {
        throw "empty tree";
    }
    stack<T>path;
   int ans=findpath(root,path,val);
   if(!ans)
   {
       return path;
   }
   else
   {
       while(!path.empty())
       {
           V.push_back(path.top());
           path.pop();
       }
   }
   return path;
}
template<typename T>
bool gen_tree<T>::findpath(gen_node<T>*root,stack<T>&S,const T&el)
{
    if(root->data==el)
    {
        S.push(root->data);
        return 1;
    }
    for(int i=0;i<root->children.size();i++)
    {
        if(findpath(root->children[i],S,el))
        {
            S.push(root->data);
            return 1;
        }
    }
    return 0;
}
template<typename T>
void gen_tree<T>::zigzag()const
{
    if(!root)
    {
        throw "empty tree";
    }
    queue<gen_node<T>*>Q;
    stack<gen_node<T>*>S;
    Q.push(root);
    zigzag(Q,S);
    return;
}
template<typename T>
void gen_tree<T>::zigzag(queue<gen_node<T>*>&Q,stack<gen_node<T>*>&S)
{
    if(Q.empty()&&S.empty())
    {
        return;
    }
    while(!Q.empty())
    {
        gen_node<T>*temp=Q.front();
       Q.pop();
        for(int i=0;i<temp->children.size();i++)
        {
           // cout<<temp->children[i]->data;
            S.push(temp->children[i]);
        }
        cout<<temp->data;
    }
    cout<<'\n';
    while(!S.empty())
    {
        Q.push(S.top());
        S.pop();
    }
    zigzag(Q,S);
}
template<typename T>
void gen_tree<T>::printlevarr2Q()const
{
    if(!root)
    {
        return;
    }
    queue<gen_node<T>*>Q1;
    queue<gen_node<T>*>Q2;
   Q1. push(root);
    printlevarr2Q(Q1,Q2);
    return;
}
template<typename T>
void gen_tree<T>::printlevarr2Q(queue<gen_node<T>*>&Q1,queue<gen_node<T>*>&Q2)
{
    if(Q1.empty()&&Q2.empty())
    {
        return;
    }
    while(!Q1.empty())
    {
        gen_node<T>*temp=Q1.front();
        cout<<temp->data;
        Q1.pop();
        for(int i=0;i<temp->children.size();i++)
        {
            Q2.push(temp->children[i]);
        }
    }
    cout<<'\n';
    printlevarr2Q(Q2,Q1);
}
template<typename T>
int gen_tree<T>::nodesgreaterthanroot()
{
    if(!root)
    {
        throw "empty tree";
    }
    T&D=root->data;
    int count=0;
    greaterthanroot(root,D,count);
    return count;
}
template<typename T>
void  gen_tree<T>::greaterthanroot(gen_node<T>*root,T D,int&count)
{
    if(root->children.size()==0)
    {
     return ;
    }
    for(int i=0;i<root->children.size();i++)
    {
        if(root->children[i]->data>D)
        {
            count++;
            greaterthanroot(root->children[i],D,count);
        }
        else
        {
            greaterthanroot(root->children[i],D,count);
        }
    }
}
template<typename T>
int gen_tree<T>::leafnodes()
{
    if(!root)
    {
        throw "empty tree";
    }
    int count=0;
    leafnodes(root,count);
    return count;
}
template<typename T>
void gen_tree<T>:: leafnodes(gen_node<T>*root,int&count)
{
    if(root->children.size()==0)
    {
        count++;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        leafnodes(root->children[i],count);
    }
}
#endif // GENRICTREES_H_INCLUDED
