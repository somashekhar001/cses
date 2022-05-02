#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t;
     cin>>t;
     while(t--)
     {
        vector<long long int>p ;
        long long x,x1,x2,x3,y1,y2,y3,s1,s2,t1,t2,ans;
        for(int i=0;i<6;i++)
        {
            cin>>x;
            p.push_back(x);
        }
        x1=p[0];
        x2=p[2];
        x3=p[4];
        y1=p[1];
        y2=p[3];
        y3=p[5];
        
        s1=x3-x1;
        s2=x3-x2;
        
        t1=y3-y1;
        t2=y3-y2;
        
        ans=s1*t2-s2*t1;
        if(ans==0)
        {
            cout<<"TOUCH"<<"\n";
        }
        else if(ans<0)
        {
            cout<<"RIGHT"<<"\n";
        }
        else
        {
            cout<<"LEFT"<<"\n";
        }
        
     }
    return 0;
}