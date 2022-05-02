#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,x;
    cin>>n>>m;
    vector<long long>t;
    bool b[n];
    vector<long long>h;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        b[i]=false;
        h.push_back(x);
    }
     for(int i=0;i<m;i++)
    {
        cin>>x;
        t.push_back(x);
    }
    sort(h.begin(),h.end());
   
    for(int i=0;i<m;i++)
    {
        int k=0;
        for(int j=n-1;j>=0;j--)
        {
           if(!b[j] && !b[j-1]){
            if(h[j]<=t[i] ){
                b[j]=true;
                cout<<h[j]<<endl;
                k++;
                break;
            }
         
           }
        }
        if(k==0){
            cout<<-1<<endl;
        }
     
    }
    
    return 0;
}