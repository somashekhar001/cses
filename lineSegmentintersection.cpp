#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t;
     cin>>t;
     while(t--)
     {
        vector<long long int>p ;
        long long x,x1,x2,x3,y1,y2,y3,s1,s2,t1,t2,ans1,ans2,x4,y4,s3,s4,t3,t4;
        for(int i=0;i<8;i++)
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
        x4=p[6];
        y4=p[7];
        m={x2-x1,y2-y1};
        
        s1=x3-x1;
        s2=x3-x2;
        s3=x4-x1;
        s4=x4-x2;
        
        t1=y3-y1;
        t2=y3-y2;
        t3=y4-y1;
        t4=y4-y2;
        
        ans1=s1*t2-s2*t1;
        ans2=s3*t4-s4*t3;
        if(ans1<0 && ans2>0 )
        {
          cout<<"YES"<<"\n";
        }
        else if(ans1>0 && ans2<0)
        {
           cout<<"YES"<<"\n";
        }
        else if(ans1>0 && ans2==0 )
        {
             cout<<"YES"<<"\n";
        }
        else if(ans1<0 && ans2==0 )
        {
             cout<<"YES"<<"\n";
        }
        else if(ans1==0 && ans2>0 )
        {
             cout<<"YES"<<"\n";
        }
        else if(ans1==0 && ans2<0 )
        {
             cout<<"YES"<<"\n";
        }
        else
        {
            cout<<"NO"<<"\n";
        }
        
     }
    return 0;
}