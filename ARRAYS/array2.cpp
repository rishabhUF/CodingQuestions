//majority element
#include<iostream>
using namespace std;
int mooresvoting(int A[],int N)
{
    int max_index=0;
    int count=1;
    //cout<<"steps"<<'\n';
    for(int i=1;i<=N;i++)
    {
        if(A[max_index]==A[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count==0)
        {
            max_index=i;
            count=1;
        }
    }
    //cout<<count<<'\n';
    return max_index;
}
bool majority(int A[],int N)
{
    int index=mooresvoting(A,N);
    int count=1;
    for(int i=0;i<=N;i++)
    {
         cout<<count;
        if(A[index]==A[i])
        {
            count++;
        }
    }
    if(count>=N/2)
    {
        cout<<A[index];
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int arr[] = { 1,1,3,4,1,1,1,1,1,2,2,2,3,4,1};
    int N=(sizeof(arr)/sizeof(arr[0]));
    cout<<N<<'\n';
    //cout<<arr[17]<<'\n';
    cout<<majority(arr,N-1);

   /* for(int i = 0; i <= 13; i++) {
        cout << arr[i] << " ";
    }*/

    return 0;
}
