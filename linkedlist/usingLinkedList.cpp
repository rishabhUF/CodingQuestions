#include<iostream>
#include"Node.h"
using namespace std;
LinkedList<int> createList() {
    LinkedList<int> L;
    for (int i = 10; i > 0; i--) {
        L+=(i*i);
    }
    return L;
}
struct temp {
    int blah;
    float blahblah;
};
int main() {
//    Node obj;
/*    Node<int> obj;
    Node<int> abc;
    Node<float> obj1;
    Node<temp> object;*/
     LinkedList<int> L1 = createList();
     cout << L1 << endl;
     L1.insertSort();
     cout << L1 << endl;
     L1.convertAnBn();
     cout << L1 << endl;
     return 0;
}
