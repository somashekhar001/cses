#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const long long n=1e5+7,c=1e9+7,p=28;
    string s;
    cin>>s;
    vector<long long >hash;
     vector<long long >hash1;
    vector<long long >power(n);
    long long sum = 0;
    power[0]=1;
    for(int i=1;i<n;i++)
    {
        power[i] = (power[i-1]*p) % c;
    }

    for(int i=0;i<s.size()-1;i++)
    {
         sum=0;
        for(int j=0;j<=i;j++)
        {
            sum=sum+(sum+(s[j]-'a'+1)*power[j])%c;
        }
        hash.push_back(sum);
    }  
    for(int i=s.size()-1,k=0;i>0;i--,k++)
    {
          sum=0;
        for(int j=0;j<=k;j++)
        {
            sum=sum+(sum+(s[i+j]-'a'+1)*power[j])%c;
        }
        hash1.push_back(sum);
    }
    for(int i=0;i<hash.size();i++)
    {
        if(hash[i]==hash1[i])
        {
            cout<<i+1<<" ";
        }
    }
    cout<<"\n";
    return 0;
}