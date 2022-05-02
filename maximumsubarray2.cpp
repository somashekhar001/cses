#include <bits/stdc++.h>
using namespace std;


 
int main()
{
    long long n,x,c,mx=0,sum=0;
    cin>>n>>x;
    vector<long long >v ;
    int dp[n];
    for(int i=0;i<n;i++)
    {
        cin>>c;
        v.push_back(c);
    }
    
    for(int i=0;i<n;i++)
    {
        sum=max(v[i],sum+v[i]);
        
        mx=max(sum,mx);
       
    }
    cout<<mx<<endl;

    return 0;
}