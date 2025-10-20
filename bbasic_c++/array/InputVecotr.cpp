 #include <iostream>
#include <vector>
using namespace std;
int main()
{
    // taking input into vector by default method of array when size is defined

    // vector<int> v(6);            // size is 6
    // cout << "Enter 6 numbers: "; // 6 1 2 3 4 5 6
    // for (int i = 0; i <= 5; i++)
    // {
    //     cin >> v[i];
    // }
    // for (int i = 0; i <= 5; i++)
    // {
    //     cout << v[i] << "  " << endl;
    // }

    // taking input into vector when size is not defined
    vector<int> v;
    for (int i = 0; i <= v.size(); i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i <= v.size(); i++)
    {
        cout << v[i] << " " << endl;
    }
}