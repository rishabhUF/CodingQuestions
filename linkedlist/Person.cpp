#include<iostream>
using namespace std;
class Person {
    char name[100];
    int age;
    public:
    static int population;
    Person() {
        population++;
    }
    ~Person() {
        population--;
    }
    static void printNameofClass() {
        cout << " Person";
    }
};
int Person::population = 0;
int main() {
    Person A,B,C;
    cout <<A.population << endl;
    cout << B.population << endl;
    cout << Person::population << endl;


}
