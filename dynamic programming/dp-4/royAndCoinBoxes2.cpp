#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 2, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;
        f[L]++;
        f[R + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = f[i] + f[i - 1];
    }
    vector<int> c(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        int coins = f[i];
        c[coins]++;
    }
    for (int i = n; i >= 1; i--) {
        c[i] = c[i] + c[i + 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        if (num > n) cout << 0 << endl;
        else cout << c[num] << endl;
    }
}