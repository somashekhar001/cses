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
ll n;
vi ans;
vector<bool>vis(n+1,false);
void dfs(int s,int n,vector<pi>A[],vi dist){
   vis[s]=true;
   for(auto x:A[s]){
       if(x.first==n){
           dist[n]=dist[s]+x.second;
           ans.PB(dist[n]);
           return;
       }
             dfs(x.first,n,A,dist);       
   }
   return ;
}

void solve(){
  ll m,k;
  vector<pi>A[100001];
  cin>>n>>m>>k;
  for(int i=0;i<m;i++){
      ll u,v,w;
      cin>>u>>v>>w; 
      A[u].PB({v,w});
  }
  vi dist(n+1,1e9+7);
  queue<ll>q;
  q.push(1);
  dist[1]=0;
  while(!q.empty()){
      ll s=q.front();
      q.pop();
      for(auto x:A[s]){
          if(dist[x.first]>dist[s]+x.second){
              dist[x.first]=dist[s]+x.second;
              q.push(x.first);
          }
      }
  }

  for(int i=0;i<k;i++){
        dist[1]=0;
       dfs(1,n,A,dist);
  }
  for(auto a:ans){
      cout<<a<<" ";
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