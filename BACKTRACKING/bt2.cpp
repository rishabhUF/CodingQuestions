//knighttours problem
#include<iostream>
#define N 10
using namespace std;
bool isafe(int S[][N],int x,int y)
{
    if((x>=0&&x<N)&&(y>=0&&y<N)&&S[x][y]==-1)
    {
        return 1;
    }
    return 0;
}
bool solveKTmain(int x,int y,int movei,int S[][N],int xMov[],int yMov[])
{
    int k,newx,newy;
    if(movei==N*N)
    {
        return true;
    }
    for(k=0;k<N;k++)
    {
        newx=x+xMov[k];
        newy=y+yMov[k];
        if(isafe(S,newx,newy))
        {
            S[newx][newy]=movei;
           //cout<<S[x][y]<<' ';
            if(solveKTmain(newx,newy,movei+1,S,xMov,yMov)==true)
            {

                return true;
            }
            else
            {
                S[newx][newy]=-1;
            }
        }
    }
    return false;
}
bool solveKTcontrol(int S[][N])
{
    int yMov[]={1,2,+2,+1,-1,-2,-2,-1};
    int xMov[]={2,1,-1,-2,-2,-1,1,2};
    S[4][2]=0;
    cout<<"step"<<'\n';
    if(solveKTmain(4,2,1,S,xMov,yMov))
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<S[i][j]<<'\t';
            }
            cout<<'\n';
        }
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int S[N][N];
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                S[i][j]=-1;
            }
        }
     cout<<solveKTcontrol(S);
     return 0;
}
