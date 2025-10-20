#include <iostream>
using namespace std;

class Bike
{
public:
    int tyreSize;
    int engineSize;

    Bike(int ts, int es) : tyreSize(ts), engineSize(es) {}
    Bike(int ts) : tyreSize(ts), engineSize(100) {}
    Bike(): tyreSize(10),engineSize(123) {}
};
void add(int a, int b)
{
    cout << a + b << endl;
}
void add(int c)
{
    cout << 10 + c << endl;
}
int main()
{
    add(12, 123);
    add(23);
    Bike tvs(14,123);
    Bike bajaj;
    cout<<bajaj.tyreSize<<endl;
    cout<<tvs.tyreSize<<" "<<tvs.engineSize<<endl;
}