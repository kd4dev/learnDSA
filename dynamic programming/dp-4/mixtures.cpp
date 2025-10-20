#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long int
using namespace std;

ll dp[105][105];  // Fixed size DP array

ll g(vector<int> &colors, int i, int j) {
    ll result = 0;
    for(int m = i; m <= j; m++) {
        result = (result + colors[m]) % 100;
    }
    return result;
}

ll f(vector<int> &colors, int i, int j) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    ll result = LLONG_MAX;
    for(int k = i; k < j; k++) {
        ll left = g(colors, i, k);
        ll right = g(colors, k+1, j);
        result = min(result, f(colors, i, k) + f(colors, k+1, j) + left * right);
    }
    return dp[i][j] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while(cin >> n) {
        vector<int> colors(n);
        for(int i = 0; i < n; i++) {
            cin >> colors[i];
        }
        
        // Initialize dp array with -1
        memset(dp, -1, sizeof(dp));
        
        cout << f(colors, 0, n-1) << endl;
    }
    return 0;
}