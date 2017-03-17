//segregate even and odd
#include<iostream>
using namespace std;
void seg(int A[],int N)
{
    int i=1;
    int j=0;
    int k=1;
    while(j<=N)
    {
        if(!(k&A[i])&&(k&A[j]))
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            j++;
            i++;
        }

    }
}
int main()
{

}
