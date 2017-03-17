//permutation of string
#include<iostream>
#include<string.h>
using namespace std;
void swap(char*x,char*y)
{
    char temp=*x;
    *x=*y;
    *y=temp;
    return;
}
void permute(char*a,int i,int n)
{
    int j;
    if(i==n)
    {
        cout<<a<<'\n';
        return;
    }
    for(j=i;j<=n;j++)
    {
        swap(a+i,a+j);
        permute(a,i+1,n);
        swap(a+i,a+j);//backtrack step which mentains original string
    }
}
int main()
{
    char A[]="rahul";
    int N=strlen(A);
    permute(A,0,N-1);
    return 0;
}
