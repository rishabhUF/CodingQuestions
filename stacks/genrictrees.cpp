#include<iostream>
#include"genrictrees.h"
using namespace std;
int main() {
    gen_tree<char> T;
    T.createtree();
    T.printlevarr2Q();
   cout<<T.leafnodes();
   // T.zigzag();
  //  T.printPreOrder();
    return 0;
}

