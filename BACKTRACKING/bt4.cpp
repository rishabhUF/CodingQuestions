//nqueen)
#include<iostream>
#define N 6
using namespace std;
void print(int S[][N],int count)
{
    //int total=0;
        for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<S[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<count<<'\n';
}
bool canplace(int S[][N],int x,int y)
{
    for(int i=0;i<x;i++)
    {
        if(S[i][y]==1)
        {
            return false;
        }
    }
    for(int i=x,j=y;i>=0&&j>=0;i--,j--)
    {
        if(S[i][j]==1)
        {
            return false;
        }
    }
    for(int i=x,j=y;i>=0&&j<N;i--,j++)
    {
        if(S[i][j]==1)
        {
            return false;
        }
    }
return true;
}
bool nqueen(int S[][N],int row,int count)
{
    if(row>=N)
    {
        print(S,count+1);
    }
    for(int i=0;i<N;i++)
    {
        if(canplace(S,row,i))
        {
            S[row][i]=1;
            if(nqueen(S,row+1,count))
            {
                return true;
            }

            S[row][i]=0;
        }
    }
    return false;
}
int main()
{
    int S[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            S[i][j]=0;
        }
    }
    nqueen(S,0,0);
}
