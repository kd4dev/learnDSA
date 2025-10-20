#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
void binary(string s, int n)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    binary(s + '0', n);
    if (s == "" || s[s.length() - 1] == '0')
    {
        binary(s + '1', n);
    }
}

int main()
{
    int n = 4;
    string s = "";
    binary(s, n);
}