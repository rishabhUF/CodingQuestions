//odd occurances bitwaise xor
#include<iostream>
using namespace std;
int oddoccurance(int A[],int N)
{
    int res=A[0];
   // cout<<N;
    for(int i=1;i<N;i++)
    {
        res=res^A[i];

        //cout<<k<<'\n';
    }
    return res;
}
int main()
{
    int arr[] = {1,2};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<N<<'\n';
    cout<<oddoccurance(arr,N);
    return 0;
}
