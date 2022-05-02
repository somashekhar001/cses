#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

#define PB push_back
#define MP make_pair
#define F first
#define S second

const ll MOD=1000000007;

void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // readInputFile();
  ll sum,n;
  cin>>n;
  sum=2*n;
  ll dp[sum+1];
  dp[0]=1;
  ll count=0;
  for(int i=0;i<=sum;i++)
  {
      if(i%2==0)
      {
       dp[i]=1;
      }
      else
      {
       dp[i]=0;
      }
      for(int j=0;j<=n;j++)
      {
          if(i-j>=0)
          {
              dp[i]=dp[i]+dp[i-j];
              dp[i]%=MOD;
          }
      }
  
  }
  

  cout<<dp[sum-1]<<" "<<count;
 return 0;
}