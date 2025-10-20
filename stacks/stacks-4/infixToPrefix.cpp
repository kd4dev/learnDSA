#include <iostream>
#include <stack>
using namespace std;
int prio(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2; //( * ),( / )
}
string solve(string val1, string val2, char ch)
{ // we ave to store prefix in answer
    string s = "";
    s.push_back(ch);
    s += val1;
    s += val2;
    return s;
}
int main()
{
    string s = "(7+9)*4/8-3";
    // we need 2 stacks
    stack<string> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        // check if digit or not
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(to_string(s[i] - 48));
        }
        else
        { // not a digit
            if (op.size() == 0)
                op.push(s[i]);
            else if (s[i] == '(')
                op.push(s[i]);
            else if (op.top() == '(')
                op.push(s[i]);
            else if (s[i] == ')')
            {
                while (op.top() != '(')
                { // work
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop(); // openin bracket ud gaya
            }
            else if (prio(s[i]) > prio(op.top()))
            {
                op.push(s[i]);
            }
            else
            {
                while (op.size() > 0 && prio(s[i]) <= prio(op.top()))
                {
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // stack can still have values
    // so make it empty
    while (op.size() > 0)
    {
        char ch = op.top();
        op.pop();
        string val2= val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1, val2, ch);
        val.push(ans);
    }
    cout << val.top() << endl;
}
