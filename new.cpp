#include <iostream>
using namespace std;
string s = "abc";
int n = s.size();
void all(string s, int a,string ans)
{
    if(a==n){
         cout<<ans<<endl;
         return;
    }
    all(s, a + 1,ans+s[a]);
    all(s,a+1,ans);
}

bool checkSubSequence(string s,string t) {
        int a=s.size();
        int b=t.size();
        if(b>a) {
            cout<<"pehla return"<<endl;
            return false;
        }
        int i=0;
        int j=0;
        while(i<a || j!=b){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(j==b) {
            cout<<"pehla2 return"<<endl;            
            return true;
        }
            cout<<"pehla3 return"<<endl;
        return false;
    }
int main()
{
    //all(s, 0,"");
    cout<<checkSubSequence("kedar","kd");
}