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
void solve(){
  ll n,m;cin>>n>>m;

  vector<ll>A[n+1];
  vector<ll>p;
  p.assign(n+1,0);
  vector<ll>B(n+1,0);

  for(int i=0;i<m;i++){
      ll u,v;
      cin>>u>>v; 
      A[u].PB(v);
      A[v].PB(u);
  }
    ll count=0;
    bool c=true,flas=true;

    ll layers=1;
   vector<int>dist(n+1,1e9+7);
  for(int i=1; i<=n; i++){
    
   
    queue<ll> q;
    
    if(dist[i]==1e9+7){
        q.push(i);
         if(c){
        if(B[i]==2){
            flas=false;
        }
          B[i]=1;
          c=false;
         }
         else
         {
               if(B[i]==1){
              flas=false;
           }
             B[i]=2;
             c=true;
         }
       
         
       dist[i]=1;
       count++;
    }

    while(!q.empty()){
        ll t=q.front();
         q.pop();
         if(layers!=dist[t]){
             if(c){
                 c=0;
             }
             else
             {
                 c=1;
             }
         }
         layers=dist[t];
 

        for(auto x:A[t]){
            if(dist[x]==1e9+7){
                 q.push(x);
                 p[x]=t;
                 dist[x]=dist[t]+1;
                 if(c){
                     if(B[i]==2){
                     flas=false;
                    }
                     B[x]=1;
                 }
                 else
                 {
                       if(B[i]==1){
                       flas=false;
                     }
                     B[x]=2;
                 }
            }
        }

    }
    
  }
  ll z=0;
  vector<bool>vis(n+1,false);
   for(int i=1; i<=n; i++){ 
    queue<ll> q;   
    if(!vis[i]){
        q.push(i);    
    }
    while(!q.empty()){
        ll t=q.front();
         q.pop();
        for(auto x:A[t]){
            if(B[x]==B[t]){
               cout<<"IMPOSSIBLE"<<endl;
               return ;
            }
            if(!vis[x]){
                vis[x]=true;
                q.push(x);
            }
        }
       

    }
    
  }

 
      for(int i=1;i<=n;i++){ 
          cout<<B[i]<<" ";
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