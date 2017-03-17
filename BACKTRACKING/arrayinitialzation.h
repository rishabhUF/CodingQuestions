#define R
#define C
int arrayin(int R,int C,int A[][C],int value)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            A[i][j]=value;
        }
    }
}
int print(int R,int C,int A[R][C])
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
