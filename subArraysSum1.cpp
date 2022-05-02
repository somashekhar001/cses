#include<bits/stdc++.h>
#include<vector>
 
 
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x,sum,s=0,l=0;
    long long int n;
    
    cin>>n ;
    cin>>sum;
    long long int count=0;
    vector<long long int>arr;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    x=0;
    for(int i=0;i<n;i++)
    {
        s=s+arr[i];
        while(s>sum && l<i)
        {
            s=s-arr[l];
            l++;
        }
        if(sum==s)
        {
           count++; 
        }
    }
    cout<<count<<endl;
    return 0;
}