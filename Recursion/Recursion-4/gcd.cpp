#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int gcd(int a,int b)
{
    if(a==0) return b;
    else return gcd(b%a,a);
}
 
int main()
{
  int n=24;
  int m=60;
  cout<<gcd(n,m);

}