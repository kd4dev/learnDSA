#include <iostream>
using namespace std;
int maze(int sr, int sc, int er, int ec)
{
    if (sr > er || sc > ec)
        return 0;
    if (sr == er && ec == sc)
        return 1;
    int rightways = maze(sr, sc + 1, er, ec);
    int downways = maze(sr + 1, sc, er, ec);
    int totalways = rightways + downways;
    return totalways;
}
int maze2(int r, int c)
{
    if (r == 0 || c == 0)
        return 0;
    if (r == 1 && c == 1)
        return 1;
    int rightways2 = maze2(r, c - 1);
    int downways2 = maze2(r - 1, c);
    int totalways2 = rightways2 + downways2;
    return totalways2;
}
void printPath(int sr, int sc, int er, int ec, string s)
{
    if (sr > er || sc > ec)
        return;
    if (sr == er && ec == sc)
    {
        cout << s << endl;
        return;
    }
    printPath(sr, sc + 1, er, ec, s + 'R');
    printPath(sr + 1, sc, er, ec, s + 'D');
}
int main()
{
    printPath(1, 1, 3, 3, "");
    cout << endl;
    cout << maze(1, 1, 5, 5) << endl;
    cout << maze2(5, 5) << endl;
}
