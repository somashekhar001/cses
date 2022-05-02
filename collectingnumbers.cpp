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

/*void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}*/
void solve()
{
  ll n,count=0;;cin>>n;
  vi a;
  for(ll i=0; i<n; i++){
      ll x;
      cin>>x;
      a.PB(x);
  }
  ll k=0,temp;
  for(int i=0;i<n-1;i++) {

      if(a[i+1]<a[i])
      {
          count++;
      }
      else if(k==0)
      {
          temp=a[i];
          k++;
      }
  }
  if( k!=0 && temp<a[n-1])
  {
    count++;
  }
  if(k==0)
  {
      count++;
  }
 
  cout<<count;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //readInputFile();
  solve();
 
 return 0;
}