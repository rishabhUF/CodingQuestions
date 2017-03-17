//no adjacent elements included in sum
#include<iostream>
using namespace std;
int maxnad(int A[],int N)
{
    int incl=0,exdl=0;
    for(int i=0;i<=N;i++)
    {
        int k=exdl;
        if(incl>exdl);
        {
            exdl=incl;
        }
        incl=k+A[i];
    }
    return incl;
}
int main()
{
    int A[]={5,5,10,40,50,35};
    int N=sizeof(A)/sizeof(A[0]);
    cout<<maxnad(A,N-1);
    return 0;
}
