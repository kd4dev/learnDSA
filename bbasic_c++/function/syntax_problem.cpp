#include <iostream>
using namespace std;
int main()
{
    int x = 12, y = 10;
    int *p = &x, q = y;
    cout << p << endl
         << q;
}