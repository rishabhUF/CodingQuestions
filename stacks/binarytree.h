#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
template <typename T>
class node
{
    T data;
    node<T>*left;
    node<T>*right;
    node<T>*parent;
public:
    node():left(0),right(0),parent(0){}
    node(const T &el):data(el),left(0),right(0),parent(0){}
   T&getdata()
   {
       return data;
   }
    template <typename V>
    friend class bt_tree;
};
template<typename T>
class bt_tree
{
    node<T>*root;
    static void createtreehelp(queue<node<T>*>&);
   static void preorder(node<T>*);
   static void inorder(node<T>*);
   static void postorder(node<T>*);
   static void levelprinthelp(queue<node<T>*>&);
   const T&largestnode(node<T>*,T&);
  static bool bsearch(node<T>*,T&);
  static  void insertnode(queue<node<T>*>&,T&);
  static const int& tree_size(node<T>*);
  static void reverseprint(stack<node<T>*>&,node<T>*);
  static void clear(node<T>*);
  static const int&height(node<T>*);
  static const int&diameter(node<T>*,int&);
  static  void deletion(node<T>*,T&,T&);
  static  void print(vector<T>);
 static void leafpaths(node<T>*,vector<T>&);
 static void zigzag(stack<node<T>*>&,stack<node<T>*>&);
static const bool structurallyidentical(node<T>*,node<T>*);
static const bool childrensum(node<T>*);
static void iterativepreorder(stack<node<T>*>&);
public:
    bt_tree():root(0){}
    void createtree();
    void preorder();
    void inorder();
    void postorder();
    void levelprint();
    const T&largestnode();
    bool bsearch();
    void insertnode(T&);
    const int&tree_size();
    void reverseprint();
    void clear();
    const int&height();
    node<T>*deepestnode();
    void deletion();
    const int&diameter();
    void leafpaths();
    void zigzag() const;
    bool childrensum();
    void iterativepreorder();
    bool structurallyidentical(const bt_tree<T>&);
    bool operator==(const bt_tree<T>&BT)
    {
        return structurallyidentical(BT);
    }
};
template<typename T>
void bt_tree<T>::createtree()
{
    if(root)
    {
        throw "error tree exists";
    }
    T el;
    cout<<"enter element for root";
    cin>>el;
    queue<node<T>*>Q;
    root=new node<T>(el);
    Q.push(root);
    createtreehelp(Q);
    Q.push(root);
}
template<typename T>
void bt_tree<T>::createtreehelp(queue<node<T>*>&Q)
{
    if(Q.empty())
    {
        return;
    }
    node<T>*orig=Q.front();
    Q.pop();
    T el;
    char side;
    cout<<"enter the side where child is to be added for "<<orig->data;
    cin>>side;
    if(side=='L')
    {
        cout<<"enter data for left child of  "<<orig->data;
        cin>>el;
        node<T>*leftchild=new node<T>(el);
        orig->left=leftchild;
        leftchild ->parent=orig;
        Q.push(leftchild);
    }
   else  if(side=='R')
    {
        cout<<"enter data for right child of "<<orig->data;
        cin>>el;
        node<T>*rightchild=new node<T>(el);
        orig->right=rightchild;
       rightchild ->parent=orig;
        Q.push(rightchild);
    }
    else if(side=='B')
    {
        cout<<"enter data for left child of "<<orig->data;
        cin>>el;
        node<T>*leftchild=new node<T>(el);
        orig->left=leftchild;
        leftchild->parent=orig;
        Q.push(leftchild);
        cout<<"enter data for rightchild of "<<orig->data;
        cin>>el;
        node<T>*rightchild=new node<T>(el);
        orig->right=rightchild;
        rightchild ->parent=orig;
        Q.push(rightchild);
    }
    else
    {
    }
    createtreehelp(Q);
}
template<typename T>
void bt_tree<T>::preorder()
{
    if(!root)
    {
        cout<< "empty tree";
        return;
    }
    preorder(root);
}
template<typename T>
void bt_tree<T>::preorder(node<T>*root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}
template<typename T>
void bt_tree<T>::inorder()
{
    if(!root)
    {
        throw "empty tree";
    }
    inorder(root);
}
template<typename T>
void bt_tree<T>::inorder(node<T>*root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}
template<typename T>
void bt_tree<T>::postorder()
{
    if(!root)
    {
        throw "empty tree";
    }
    postorder(root);
}
template<typename T>
void bt_tree<T>::postorder(node<T>*root)
{
    if(!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";
}
template<typename T>
void bt_tree<T>::levelprinthelp(queue<node<T>*>& Q)
{
    if(Q.empty())
    {
        return;
    }
    Q.push(0);
    while(Q.front()!=0)
    {
      node<T>*it=Q.front();
      Q.pop();
      cout<<it->data<<"  ";
      if(it->left)
    {
      Q.push(it->left);
    }
    if(it->right)
    {
      Q.push(it->right);
    }
    }
    cout<<'\n';
    Q.pop();
    levelprinthelp(Q);
}
template<typename T>
void bt_tree<T>::levelprint()
{
    if(!root)
    {
        throw "empty tree";
    }
    queue<node<T>*>Q;
    Q.push(root);
    levelprinthelp(Q);
    return;
}
template<typename T>
const T& bt_tree<T>::largestnode()
{
    if(!root)
    {
        throw "empty tree";
    }
    T&ans=root->data;
    ans=largestnode(root,ans);
    return ans;
}
template<typename T>
const T&bt_tree<T>::largestnode(node<T>*root,T&ans)
{
    if(!root)
    {
        return ans;
    }
    if(root->data>ans)
    {
        ans=root->data;
    }
   ans= largestnode(root->left,ans);
   ans= largestnode(root->right,ans);
}
template<typename T>
bool bt_tree<T>::bsearch()
{
    if(!root)
    {
        throw "empty tree";
    }
    T key;
    cout<<"enter key to be searched";
    cin>>key;
   return bsearch(root,key);
}
template<typename T>
bool bt_tree<T>::bsearch(node<T>*root,T&key)
{
    if(!root)
    {
        return false;
    }
    else
{
    if(root->data==key)
    {
        return true;
    }
   else
   {
      bool temp=bsearch(root->left,key);
      if(temp!=0)
       {
         return temp;
        }
     else
       {
         return bsearch(root->right,key);
       }
   }
   return false;
}
}
template<typename T>
void bt_tree<T>::insertnode(queue<node<T>*>&Q,T&el)
{
    while(!Q.empty())
    {
        node<T>*it=Q.front();
        Q.pop();
        if(!it->left)
        {
            node<T>*temp=new node<T>(el);
            it->left=temp;
            temp->parent=it;
            return;
        }
        else
        {
            Q.push(it->left);
        }
         if(!it->right)
        {
            node<T>*temp=new node<T>(el);
            it->right=temp;
            temp->parent=it;
            return;
        }
        else
        {
            Q.push(it->right);
        }
    }

}
template<typename T>
void bt_tree<T>::insertnode(T&el)
{
    if(!root)
    {
        root=new node<T>(el);
        return;
    }
    queue<node<T>*>Q;
    Q.push(root);
    insertnode(Q,el);
}
template<typename T>
const int&bt_tree<T>::tree_size()
{
    if(!root)
    {
        return 0;
    }
    return tree_size(root);
}
template<typename T>
const int&bt_tree<T>::tree_size(node<T>*root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        return tree_size(root->left)+tree_size(root->right)+1;
    }
}
template<typename T>
void bt_tree<T>::reverseprint()
{
    if(!root)
    {
        throw "empty tree";
    }
    stack<node<T>*>S;
    reverseprint(S,root);
    while(!S.empty())
    {
       node<T>*temp= S.top();
       S.pop();
       cout<<temp->data<<"  ";
    }
    return;
}
template<typename T>
void bt_tree<T>::reverseprint(stack<node<T>*>&S,node<T>*root)
{
    if(!root)
    {
        return;
    }
    S.push(root);
    S.push(root->right);
    S.push(root->left);
    reverseprint(S,root->left);
    reverseprint(S,root->right);
}
template<typename T>
void bt_tree<T>::clear(node<T>*root)
{
    if(!root)
    {
        return;
    }
if(root->left){
    clear(root->left);
   }
   if(root->right)
   {
    clear(root->right);
   }
    delete root;
}
template<typename T>
void bt_tree<T>::clear()
{
    if(!root)
    {
        return;
    }
    clear(root);
    delete root;
}
template<typename T>
const int&bt_tree<T>::height()
{
    if(!root)
    {
        cout<< "empty tree";
        return 0;
    }
    return height(root);
}
template<typename T>
const int&bt_tree<T>::height(node<T>*root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
       int  leftheight=height(root->left);
       int  rightheight=height(root->right);
        if(leftheight>rightheight)
        {
            return leftheight+1;
        }
        else
        {
            return rightheight+1;
        }
    }
}
template<typename T>
void bt_tree<T>::deletion(node<T>*root,T&el,T&el1)
{
    if(!root)
    {
        return;
    }
    deletion(root->left,el,el1);
    deletion(root->right,el,el1);
    if(root->data==el)
    {
        cout<<root->data<<"found";
        root->data=el1;
    }
    return;
}
template<typename T>
void bt_tree<T>::deletion()
{
    if(!root)
    {
        throw "empty tree";
    }
    T el;
    cout<<"enter element to be deleted";
    cin>>el;
    node<T>*temp=deepestnode();
    T&el1=temp->data;
    cout<<el1;
   deletion(root,el,el1);
//   node<T>*temp=deepestnode();
   temp=NULL;
   delete temp;
   return;
}
template<typename T>
node<T>*bt_tree<T>::deepestnode()
{
  if(!root)
  {
      throw "empty tree";
  }
  queue <node<T>*>Q;
  node<T>*temp;
  Q.push(root);
  while(!Q.empty())
  {
      temp=Q.front();
      Q.pop();
      if(temp->left)
      {
          Q.push(temp->left);
      }
      if(temp->right)
      {
          Q.push(temp->right);
      }
  }
//  delete Q;
  return temp;
}
template<typename T>
const bool bt_tree<T>:: structurallyidentical(node<T>*root,node<T>*root1)
{
    if(!root1&&!root)
    {
        return 1;
    }
    if(!root1||!root)
    {
        return 0;
    }
    cout<<root->data<<" "<<root1->data<<'\n';
return ((root->data==root1->data)&&structurallyidentical(root->left,root1->left)&&structurallyidentical(root->right,root1->right));
}
template<typename T>
bool bt_tree<T>:: structurallyidentical(const bt_tree<T>&BT)
{
    if(!BT.root&&root)
    {
        return 0;
    }
    if(BT.root&&!root)
    {
        return 0;
    }
    cout<<BT.root->data;
    cout<<BT.root->left->data;
    cout<<BT.root->right->data;
    return structurallyidentical(root,BT.root);
}
template<typename T>
const int&bt_tree<T>::diameter(node<T>*root,int&ans)
{
    if(!root)
    {
        return 0;
    }
    int lefth=diameter(root->left,ans);
    int righth=diameter(root->right,ans);
    if(lefth+righth>ans)
    {
        ans=lefth+righth;
    }
    if(lefth>righth)
    {
        return lefth+1;
    }
    else
    {
        return righth+1;
    }
}
template<typename T>
const int&bt_tree<T>::diameter()
{
    if(!root)
    {
        throw "empty tree";
    }
    int ans=0;
    ans=diameter(root,ans);
    return ans;
}
template<typename T>
void bt_tree<T>::zigzag(stack<node<T>*>&S1,stack<node<T>*>&S2)
{
    if(S1.empty()&&S2.empty())
    {
        return;
    }
    while(!S1.empty())
    {
        node<T>*temp=S1.top();
        S1.pop();
       if(temp->right)
       {
        S2.push(temp->right);
       }
       if(temp->left)
       {
        S2.push(temp->left);
       }
        cout<<temp->data;
    }
    cout<<'\n';
     while(!S2.empty())
    {
        node<T>*temp=S2.top();
        S2.pop();
        if(temp->left)
        {
        S1.push(temp->left);
        }
        if(temp->right)
        {
        S1.push(temp->right);
        }
        cout<<temp->data;
    }
    cout<<'\n';
    zigzag(S1,S2);
}

template<typename T>
void bt_tree<T>::zigzag() const
{
    if(!root)
    {
        throw "empty tree";
    }
    stack<node<T>*>S1;
    stack<node<T>*>S2;
    S2.push(root);
    zigzag(S1,S2);
    return;
}
template<typename T>
void bt_tree<T>::leafpaths()
{
    if(!root)
    {
        throw "empty tree";
    }
    vector<T>V;
    paths(root,V);
}
template<typename T>
void bt_tree<T>::leafpaths(node<T>*root,vector<T>&V)
{
    if(!root)
    {
        return;
    }
    V.push_back(root->data);
    if(!root->left&&!root->right)
    {
        print(V);
        V.pop_back();
        return;
    }
    else
    {
        paths(root->left,V);
        paths(root->right,V);
              V.pop_back();
    }
}
template<typename T>
void bt_tree<T>::print(vector<T>V)
{
for(int it=0;it<V.size();it++)
{
    cout<<V.at(it)<<"  ";
}
cout<<'\n';
}
template<typename T>
bool bt_tree<T>::childrensum()
{
    if(!root)
    {
        throw "empty tree";
    }
    return childrensum(root);
}
template<typename T>
const bool bt_tree<T>::childrensum(node<T>*root)
{
    if(!root->left&&!root->right)
    {
        return 1;
    }
    if(!root->left)
    {
        root->left=new node<T>(0);;
    }
    if(!root->right)
    {
        root->right=new node<T>(0);
    }
    return ((root->data==root->left->data+root->right->data)&&(childrensum(root->left))&&(childrensum(root->right)));
}
template<typename T>
void bt_tree<T>::iterativepreorder()
{
    if(!root)
    {
        throw "empty tree";
    }
    stack<node<T>*>S;
    S.push(root);
    iterativepreorder(S);
    return;
}
template<typename T>
void bt_tree<T>::iterativepreorder(stack<node<T>*>&S)
{
    while(!S.empty())
    {
      node<T>*temp=S.top();
      cout<<temp->data;
      S.pop();
      if(temp->right)
    {
      S.push(temp->right);
    }
    if(temp->left)
    {
      S.push(temp->left);
    }
    }
    return;
}

#endif // BINARYTREE_H_INCLUDED
