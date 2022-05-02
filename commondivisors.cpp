#include<bits/stdc++.h>
using namespace std;
long long int divisor(int m,int n)
{
   if(m==0)
   {
       return n;
   }
   return divisor(n% m,m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,x,gcd,max=0;
    cin>>n;
    vector<long long int >v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {    
            long long int m=v[i],n=v[j];
              gcd=divisor(m,n);
              if(gcd>max)
              {
                  max=gcd;
              }
        }
    }
        
   cout<<max<<"\n";
 
    return 0;
}