//juggling algorithm
#include<iostream>
using namespace std;
int gcd(int N,int d)
{
    int r=N%d;
    if(r==0)
    {
        return d;
    }
    return gcd(d,r);
}
void jugglingtheoremm(int A[],int N,int d)
{
    int k=gcd(N,d);
    int j=0;
    int temp=0;
    while(d>0)
    {
        int i=j;
        while(i<N)
        {
            int temp=A[i];
                A[i]=A[i+k];
                A[i+k]=temp;
                //cout<<A[i]<<' '<<A[i+k];
                i=i+k;
        }
        d--;
    }
    return;
}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int N=sizeof(A)/sizeof(A[0]);
   // cout<<N;
    jugglingtheoremm(A,N-1,1);
    for(int i=0;i<N;i++)
    {
      cout<<A[i]<<' ';
    }
    return 0;
}

