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
bool inside(int m,int n,int newi,int newj){
    return newi>=0 && newj>=0 && newi<n && newj<m ;
}
void solve(){
 
  ll n,m;cin>>n>>m;
  vector<string>s;
  string x;
 
  for(int i=0;i<n;i++){
      cin>>x;
      s.PB(x);
  }
 
  vector<vector<vector<pi>>>adj(n,vector<vector<pi>>(m,vector<pi>(m,pi ({0,0}))));
  pi l;
  pi k;
  vector<pi>neigh;
      neigh.PB({0,1});
      neigh.PB({1,0});
      neigh.PB({-1,0});
      neigh.PB({0,-1});
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(s[i][j]=='.' || s[i][j]=='A' || s[i][j]=='B'){ 
            for(auto x:neigh){
                ll newi=i+x.F,newj=j+x.S;
                if(inside(m,n,newi,newj)){
                    if(s[newi][newj]=='.' || s[newi][newj]=='A' || s[newi][newj]=='B'){
                        adj[i][j].PB({newi,newj});
                        adj[newi][newj].PB({i,j});
                    }
                }
            }
            if(s[i][j]=='A'){
                l={i,j};
            }
            if(s[i][j]=='B'){
                k={i,j};
            }
          }
        }
     }
 
   vector<vector<bool>>vis(n,vector<bool>(m,false));
  
   queue<pi>q;
 
   q.push(l);
   vis[l.F][l.S]=true;
 
   while(!q.empty()){
     int x=q.front().F;
     int y=q.front().S;
     vis[x][y]=true;
     q.pop();
     for(auto h:adj[x][y]){
       if(!vis[h.F][h.S]){
          vis[h.F][h.S]=true;
          q.push(h);
       }
      }
    }
 
    if(vis[k.F][k.S]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
 
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