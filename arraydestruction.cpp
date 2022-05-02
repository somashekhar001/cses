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

                           
class unionfind{
 private : vi setsize,rank,p,sumset;
           int numsets;
 public : 
        unionfind(int n){
             p.assign(n,0);
            
             setsize.assign(n,1);//size of all singleton set is 1
            
             rank.assign(n,0);// size of all trees is zero
            
             sumset.assign(n,0);// size of all
             numsets=0;     // number of sets is n
        }
        void makeset(int x,int y){
            p[x]=x;
            setsize[x]=1;
            rank[x]=0;
            sumset[x]=y;
            numsets++;
        }
        int findsets(int i){
            if(p[i]==i){
                return i;
            }
                // otherwise find leader element and do path compression 
               // by pointing the current element to leader element
            else{
                return p[i]=findsets(p[i]);  
            }
        }
        void unionset(int i,int j){
              if(issameset(i,j)){
                  return ;
              }
              int x=findsets(i);
              int y=findsets(j);
              if(rank[x]>rank[y]){
                  swap(x,y);
              }
              p[x]=y;
              if(rank[x]==rank[y]){
                  rank[y]++;
              }
              setsize[y] += setsize[x];
                  sumset[y] += sumset[x];
              numsets--;
        }
        bool issameset(int i,int j){
            return findsets(i)==findsets(j);
        }
        ll sumofset(int x){
          return sumset[findsets(x)];
        }
      
};
void solve(){

 
  int n;cin>>n;

  vi arr(n+1,0);// elements of the array
  
  vi state(n+1,0);//currently there are no element in constructed array so 0

  vi sequence(n); //elemnts containing permutation till n

  for(int i=1; i<=n;i++){
    cin>>arr[i];
  } 
  for(int i=0;i<n;i++){
      cin>>sequence[i];
  }
  unionfind uf(n+1);
   

   reverse(sequence.begin(),sequence.end());

   vi answers;

   answers.PB(0);

   ll currentans=0;

   for(auto x:sequence){
       state[x]=1;
       uf.makeset(x,arr[x]);
       if(x-1 > 0 && state[x-1]){
           uf.unionset(x-1,x);
       }
       if(x+1 <= n && state[x+1]){
           uf.unionset(x,x+1);
       }
       ll z=uf.sumofset(x);
       currentans = max(z,currentans);
       answers.PB(currentans);
   }
   answers.pop_back();

   reverse(begin(answers),end(answers));
   int ssssum=0;
   for(auto x:answers){
       cout<<x<<endl;
       ssssum +=x;
   }
   cout<<ssssum<<endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solve();
 
 return 0;
}