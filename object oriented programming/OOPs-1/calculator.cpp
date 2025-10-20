#include<iostream>
using namespace std;
class calculator{
    public:
    int a;
    int b;
    void add(){
        cout<<a+b;
    }
    void subtract(){
        cout<<a-b;
    }
};

int main(){
    calculator calci;
    calci.a=90;
    calci.b=10;
    calci.add();
    cout<<endl;
    calci.subtract();
} 