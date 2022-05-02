#include <bits/stdc++.h>
using namespace std;

class movie
{
    public:
    long long int start, end,interval;
    void insert(long long int start,long long int end)
    {
        this->start=start;
        this->end=end;
        this->interval=this->end-this->start;
    }
};
bool cmp(class movie a, class movie b)
{
    return a.interval>b.interval;
    
}

int main()
{
    movie M[300000];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int  x,y;
    long long int n;
    cin>>n ;
    for(int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        M[i].insert(x,y);
    }
    sort(M,M+n,cmp);
   
   
    long long int count=1;
    for(int i=0;i<n-1;i++)
    {
        if(M[i].start<M[i+1].end && M[i].end>M[i+1].start)
        {
            if(M[i+1].end>M[i].end) 
            {
               M[i+1].end=M[i].end;
            }  
            if(M[i+1].start<M[i].start) 
            {
               M[i+1].start=M[i].start;
            }  
            count++;
          
        }
        else
        {
            M[i+1]=M[i];
        }
    }
    cout<<count<<endl;
    
    return 0;
}