//contangiuos subarray
#include<iostream>
using namespace std;
int kadanealgo(int A[],int N)
{
    int max_sum=0;
    int max_end=0;
    for(int i=0;i<N;i++)
    {
        max_end=max_end+A[i];
        if(max_end<0)
        {
            max_end=0;
        }
        if(max_sum<max_end)
        {
            cout<<max_end<<'\n';
            max_sum=max_end;
        }
   }
return max_sum;
}
int main()
{
    int arr[] = { 1,-1,-3,4,1,1,1,1,1,-2,-2,-2,3,-4,1};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<kadanealgo(arr,N);
    return 0;
}
