#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int>dp(100000006,-1);
vector<int>get_digit(int n){
    vector<int>result;
    while(n>0){
        if(n%10!=0){
            result.push_back(n%10);
        }
        n /=10;
    }
    return result;
}

int ftb(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    vector<int>d=get_digit(n);
    int result=INT_MAX;
    if(dp[n]!=-1) return dp[n];
    for(int i=0;i<d.size();i++){
        result=min( result , ftb( n-d[i] ) );
    }
    return dp[n]=1+result;
}
int fbu(int num){
    dp.clear();
    dp.resize(1000006);
    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;
    for(int n=10;n<=num;n++){
        vector<int>d=get_digit(n);
        int result=INT_MAX;
        for(int i=0;i<d.size();i++){
            result=min(result,dp[n-d[i]]);
        }
        dp[n]=1+result;
    }
    return dp[num];
}

int main(){
    int n;
    cin>>n;
    cout<<ftb(n)<<" "<<fbu(n)<<endl;

}