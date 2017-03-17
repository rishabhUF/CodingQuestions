//string functions
#include<iostream>
using namespace std;
void abc(char *s)
{
    if(s[0] == '\0'){
        return;
}
    abc(s + 1);
    abc(s + 1);
    cout<<s[0];
}
int main()
{
    char S[100]="hello";
    abc(S);
    return 0;
}
