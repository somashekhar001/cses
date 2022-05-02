#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n,x,sum,s=0;
    
    cin>>n ;
    cin>>sum;
    vector<long long >a;
    long long dp[1000000];
    
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
  
    for(int i=0;i<=sum;i++)
    {
        dp[i]=10000000;
    }
    dp[0]=0;
    for(int j=1;j<=n;j++)
    {
       x=j;
      for(int i=0;i<=sum;i++)
      {
          if(i- a[x-1] >= 0)
          {
            dp[i]=min(dp[i],dp[i-a[x-1]]+1);
          }
       }
    }
    if(dp[sum]==10000000)
    {
     cout<<-1<<endl;   
    }
    else 
    {
     cout<<dp[sum]<<"\n";
    }
    return 0;
}