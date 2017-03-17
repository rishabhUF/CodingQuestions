//merging two array into1
#include<iostream>
using namespace std;
void shiftarray2(int B[],int i,int j);
void merge1(int B[],int A[],int M,int N)
{
    shiftarray2(B,M,M);
    int i=M-N,j=0,k=0;
    while(k<=M)
{
        if(j<=N)
        {
            if(B[i]<A[j])
            {
             int temp=B[i];
             B[i]=B[k];
             B[k]=temp;
             k++;
             i++;
            }
            else
            {
                B[k]=A[j];
                k++;
                j++;
            }
        }
        else
        {
             int temp=B[i];
             B[i]=B[k];
             B[k]=temp;
             k++;
             i++;
        }
}
return;
}
void shiftarray2(int B[],int i,int j)
{

    while(i>=0)
{
    if(B[i]==0)
    {
        i--;
    }
    if(B[j]!=0)
    {
        j--;
    }
    if(B[i]!=0&&B[j]==0)
    {
        int temp=B[i];
        B[i]=B[j];
        B[j]=temp;
        j--;
        i--;
    }
    //cout<<B[i]<<' '<<B[j];
}
return;
}
int main()
{
 int B[]={1,0,3,0,5,0};
 int A[]={2,6,8};
 int N=sizeof(B)/sizeof(B[0]);
 int M=sizeof(A)/sizeof(A[0]);
 merge1(B,A,N-1,M-1);
 for(int i=0;i<N;i++)
 {
     cout<<B[i];
 }
 return 0;
}
