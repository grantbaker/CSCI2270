#include <iostream>

using namespace std;

void pointerTest(int * p) {
    *p = 99;
}

int main() {

    int intI = 5;
    cout<<"value: "<<intI<<" address: "<<&intI<<endl;

    int intB = 50;
    int *ptrB = &intB;
    cout<<"ptrB address pointing to: "<<ptrB<<" intB address: "<<&intB<<endl;
    cout<<"*ptrB value: "<<*ptrB<<" intB value: "<<intB<<endl;
    cout<<&ptrB<<endl;

    intB = 60;
    cout<<"*ptrB value: "<<*ptrB<<" intB value: "<<intB<<endl;

    char a = 'a';
    char * b = &a;
    cout<<a<<" | "<<b<<endl;

    pointerTest(ptrB);
    cout<<"function call complete"<<endl;
    cout<<"intB value: "<<intB<<endl;

    int *i = new int;
    cout<<"address: "<<i<<" value: "<<*i<<endl;

    int *intArray = new int[10];

}

