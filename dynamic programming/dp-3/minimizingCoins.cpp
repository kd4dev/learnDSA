#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int>dp(1000006,-2);
vector<int>coins;
int ftd(int x){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];
    int result=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i]<0)continue;
        result=min(result,ftd(x-coins[i]));
    }
    if(result==INT_MAX) return dp[x]=INT_MAX;
    return dp[x]=1+result;
}
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }
    int ans=ftd(x);
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans;
}