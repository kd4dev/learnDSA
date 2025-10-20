#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m;
    cout << "enter rows of 1st matrix:";
    cin >> m;
    int n;
    cout << "enter columns of 1st matrix:";
    cin >> n;

    int p;
    cout << "enter rows of 2nd matrix:";
    cin >> p;
    int q;
    cout << "enter columns of 2nd matrix:";
    cin >> q;
    if (n == p)
    {
        int a[m][n];
        cout << "enter elements of first matrix:";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int b[p][q];
        cout << "enter elements of second matrix:";
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> b[i][j];
            }
        }
        // resultant matrix
        int res[m][q];
        // fillin
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j< q; j++)
            {
                // res[i][j]=summation 'r' varies from r=0 to r=(n-1) a[i][r]*b[r][j]
                res[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    res[i][j] += (a[i][k]) * (b[k][j]);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << res[i][j] << " ";

            }
            cout << endl;
        }
    }
    else
    {
        cout << "matrices cant be multiplied:";
    }
}
