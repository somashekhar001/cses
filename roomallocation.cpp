#include<bits/stdc++.h>
using namespace std;

class room
{
    public:
        long long int a,b,r=0;
       void insert(long long int a,long long int b)
        {
            this->a=a;
            this->b=b;
        }
        void allotedroom(long long int x)
        {
           r=x;
        }
};
bool cmp(class room a, class room b)
{
    return a.a<b.a;
    
}
int main()
{   
    freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
    room R[200000];
    room M[200000];
    long long int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        R[i].insert(a,b); 
        M[i].insert(a,b);
    }
      sort(R,R+n,cmp);
       int i=1,k=0,count=1,b1=0;
        
        R[k].allotedroom(1);
    
   while(i<=n)
   {
       b1=0;
    for(int j=0;j<=n;j++)
    {
        if(R[j].a > R[k].b && R[j].r==0)
        {
            R[j].allotedroom(i);
            count++;
            k=j;
        }
        else if(R[j].r==0 && b1==0)
        {
          b1=j;
        }
    }
    i++;
    if(b1!=0)
    {
        R[b1].allotedroom(i);
        k=b1;
    }
   }
   int max=0;
   for(int l=0;l<n;l++)
   {
     if(max<R[l].r)
     {
         max=R[l].r;
     }
   }
     cout<<max<<"\n";



     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(R[i].a==M[j].a && R[i].b==M[j].b )
             {
                 M[j].r= R[i].r;
             }
         }
     }
    for(int l=0;l<n;l++)
    { 
      cout<<M[l].r<<" ";
    }
    cout<<endl;




    return 0;
}