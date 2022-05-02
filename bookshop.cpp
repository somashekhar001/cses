#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long s,n,sum,x,mp=0,su=0;
    
    cin>>n>>sum;
    vector<long long>m;
    vector<long long>p;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        m.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        p.push_back(x);
    }
    
    for(int i=0;i<n;i++)
    {
        s=m[i];
        su=0;
        if(sum>=s) {
            su=p[i];
        mp=max(mp,p[i]);
        }
        for(int j=0;j<n;j++)
        {
            if(i!=j && sum>=s+m[j])
            {
                su=su+p[j];
                s=s+m[j];
                mp=max(mp,su);
            }
        }
    }
    
    
    cout<<mp<<endl;
    
    return 0;
}