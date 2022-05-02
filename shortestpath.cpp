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
 
const ll MOD=1e9+7;
const ll INF=MOD;
void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve() { 
  
    ll n,m;cin>>n>>m;
    vector<pi>A[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        A[a].PB({b,w});
    }
    vi dist(n+1,1e9+7);
     dist[1]=0;
     queue<pi> q;
     q.push({1,0});
     while(!q.empty()){
       ll t=q.front().first;
      ll d=q.front().second;
      q.pop();
      if(d>dist[t]){
        continue;
      };
       
       for(auto x:A[t]){
         if(dist[x.first]>dist[t]+x.second){
           dist[x.first]=dist[t]+x.second;
           q.push({x.first,dist[x.first]});
         }
       }
     }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
 
 
    
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // readInputFile();
  solve();
 
 return 0;
}