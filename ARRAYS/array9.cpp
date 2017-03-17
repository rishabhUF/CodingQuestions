//reversal algorithm
#include<iostream>
using namespace std;
void reverse(int A[],int s,int e)
{
    if(s>e)
    {
        return;
    }
    int temp=A[s];
    A[s]=A[e];
    A[e]=temp;
    reverse(A,s+1,e-1);
}
void rotate(int A[],int N,int d)
{
    reverse(A,0,d-1);
    reverse(A,d,N);
    reverse(A,0,N);
}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int N=sizeof(A)/sizeof(A[0]);
     rotate(A,N-1,1);
    for(int i=0;i<N;i++)
    {
      cout<<A[i]<<' ';
    }
    return 0;
}
