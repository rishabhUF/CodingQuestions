#include<iostream>
//#include "arrayinitialzation.h"
using namespace std;
#define R 5
#define C 5
void arrayin(int A[][C],int value)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            A[i][j]=value;
        }
    }
}
void print(int A[][C])
{
     for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<'\n';
    }
}

bool isafe(int Q[R][C],int x,int y)
{
    if((x>=0&&x<R)&&(y>=0&&y<C)&&Q[x][y]==1)
    {
        return 1;
    }
    return 0;
}
bool ratmaze(int x,int y,int S[R][C],int Q[R][C],int pre)
{
   if(x==R-1&&y==C-1)
   {
    S[x][y]=1;
    print(S);
    return true;
   }
    if(isafe(Q,x,y))
   {
    {
         S[x][y]=1;
        cout<<S[x][y]<<x<<' '<<y<<'\n';
        if(pre!=0&&ratmaze(x+1,y,S,Q,2))
        {
            //prevx=x;
            return true;
        }
        if(pre!=3&&ratmaze(x,y+1,S,Q,1))
        {
            //prevx=x;
            //prevy=y+1;
            return true;
        }
        if(pre!=1&&ratmaze(x,y-1,S,Q,3))
        {
            //prevx=x;
            //prevy=y-1;
            return true;
        }
        if(pre!=2&&ratmaze(x-1,y,S,Q,0))
        {
            //prevx=x-1;
            //prevy=y;
            return true;
        }
        S[x][y]=0;
        return false;
    }
}
return false;
}
int main()
{
    int A[R][C]={1,0,1,1,1,
                  1,0,1,0,1,
                  1,0,1,1,1,
                  1,1,1,1,0,
                  1,0,0,1,1,};
    int S[R][C];
    arrayin(S,0);
    ratmaze(0,0,S,A,1);
}
