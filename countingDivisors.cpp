#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
         int n,temp,count=0,x;
       
        cin>>n;
        x=sqrt(n);
        for(int i=1;i<=x;i++)
        {
            if(n%i==0)
            {
             count++;
            }          
        }
        
     if(x*x== n)
     {
         cout<<2*count-1<<"\n";
     }
     else
     {
         cout<<2*count<<"\n";
     }
        
      
    
    }
 
 
    return 0;
}