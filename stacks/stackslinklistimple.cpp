#include<iostream>
#include"stackimp.h"
using namespace std;
bool balancedbrackets(char *str,stacks<char> S)
{
    int i=0;
    while(str[i])
{
    if(str[i]=='['||str[i]=='{'||str[i]=='(')
   {
    S.push(str[i]);
   }
   if(S.topdata()=='['&&str[i]==']')
   {
       S.pop();
   }
  if(S.topdata()=='{'&&str[i]=='}')
    {
       S.pop();
   }
   if(S.topdata()=='('&&str[i]==')')
    {
       S.pop();
    }
    i++;
}
if(S.ifempty())
{
    cout<<"balanced";
    return true;
}
else
{
    cout<<"not balanced";
    return false;
}
}
void getmin(stacks<int>minstack,stacks<int>S)
{
    int x;
     cin>>x;
    while(x!=-1)
    {
        S.push(x);
        if(minstack.ifempty())
        {
            minstack.push(x);
        }
        else
        {
            if(minstack.topdata()>=S.topdata())
            {
                minstack.push(x);
            }
        }
        cin>>x;
    }
    while(!S.ifempty())
    {
        cout<<S.topdata()<<" ";
        S.pop();
    }
    cout<<'\n';
    while(!minstack.ifempty())
    {
        cout<<minstack.topdata()<<" ";
        minstack.pop();
    }
return;
}
bool checkpalindrome(stacks<char>S,char*str,int i)
{
    if(S.ifempty())
    {
        return true;
    }
   if(str[i]=='\0'&&!S.ifempty())
    {
        cout<<S.topdata();
        return false;
    }
    if(str[i]!=S.topdata())
    {
        cout<<S.topdata();
        return false;
    }
    cout<<S.topdata();
    S.pop();
    i++;
    return checkpalindrome (S,str,i);
}
/*void postfix(stacks<char> S,char el)
{
    if(el==')')
    {
        while(S.topdata()!='(')
       {
           cout<<S.topdata();
           S.pop();
       }
        cout<<S.topdata();
           S.pop();
           return;
    }
    /*else  if(el=='}')
    {
        while(S.topdata()!='{')
       {
           cout<<S.topdata();
           S.pop();
       }
        cout<<S.topdata();
           S.pop();
           return;
    }
    else  if(el==']')
    {
        while(S.topdata()!='[')
       {
           cout<<S.topdata();
           S.pop();
       }
        cout<<S.topdata();
           S.pop();
           return;
    }
    else if(el=='/'||el=='*')
    {
      while(S.topdata()=='('||!S.ifempty())
      {
          cout<<S.topdata();
          S.pop();
      }
      S.push(el);
      return;
    }
 else if(el=='+'||el=='-')
    {
      while(S.topdata()=='('||!S.ifempty()||S.topdata()!='/'||S.topdata()!='*')
      {
          cout<<S.topdata();
          S.pop();
      }
      S.push(el);
      return;
   }
else
  {
   S.push(el);
   return;
   }
}
*/
void remove_dup(stacks<char>&S,char*str)
{
    if(*str=='\0')
    {
        return;
    }
    if(S.ifempty())
    {
        S.push(*str);
    }
        //cout<<str[i]<<'\n';
        if(*str=S.topdata())
        {
       //     cout<<str[i]<<"  "<<S.topdata()<<'\n';
            S.push(*str);
        }
        else
        {
           // cout<<str[i]<<"  "<<S.topdata()<<'\n';
            S.pop();
        }
        remove_dup(S,str+1);

    //cout<<S.topdata();

}
int main()
{
    int i=0,j=1,x,k=0;
    int A[10];
    stacks<int> S;
    cin>>x;
    while(x!=-1)
    {
        cin>>x;
        A[k]=x;
        k++;
    }

    while()
    {
         if(A[i]<A[j])
        {
            int k=S.topdata()+1;
          //  S.pop();
            S.push(k);
        }
        else
        {
            S.push(1);
        }
        i++;
        j++;
    }
   /* while(str[i])
    {
        S.push(str[i]);
        i++;
    }
    remove_dup(S,str);
   // cout<<S.ifempty();
   */ while(!S.ifempty())
    {
        cout<<S.topdata()<<'\n';
        S.pop();
    }
  /* i++;
    cout<<i;
    cout<<checkpalindrome(S,str,i);
//cout<<balancedbrackets(str,S);
// S.reverse();*/
}
