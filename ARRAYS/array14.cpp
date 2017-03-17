//submatrix without zero
#include<iostream>
#define R 6
#define C 5
using namespace std;
int compare(int x,int y,int z)
{
    if(y>x&&z>x)
    {
        return x;
    }
    if(x>y&&z>y)
    {
        return y;
    }
    if(x>z&&y>z)
    {
        return z;
    }
}
void submatrix(int A[R][C],int S[R][C],int i,int j,int N,int M)
{
    if(i==N)
    {
        return;
    }
    if(i==0||j==0)
    {
        S[i][j]=A[i][j];
    }
    if(A[i][j]&&(i!=0||j!=0))
    {
       S[i][j]=compare(S[i][j-1],S[i-1][j-1],S[i-1][j])+1;
    }
    else
    {
        S[i][j]=0;
    }
    int newi=i,newj=j+1;
    if(j==M-1)
    {
        newj=0;
        newi=i+1;
    }
    submatrix(A,S,newi,newj,N,M);
}
void bigsub(int A[R][C],int S[R][C],int i,int j,int M,int N)
{
    submatrix(A,S,0,0,M,N);
    int m=0,mi=0,mj=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(m<S[i][j])
            {
                m=S[i][j];
                mi=i;
                mj=j;
            }
        }
    }
    for(int i=mi-m+1;i<=mi;i++)
    {
        for(int j=mj-m+1;j<=mj;j++)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<'\n';
    }
}
int main()
{
    int A[R][C]={0,1,1,0,1,
                 1,1,1,1,1,
                 0,1,1,1,1,
                 1,1,1,1,1,
                 1,1,1,1,1,
                 0,1,0,0,0,
                 };
    int S[R][C];
    bigsub(A,S,0,0,R,C);
     for(int i=0;i<R;i++)
    {
        for(int j=0;j<=C;j++)
        {
            cout<<S[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
