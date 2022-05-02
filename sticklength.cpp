#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  vector<long long int>v;
  long double avg;
  long long int x;
   long long int n;
    long long int s;
 
  cin>>n;
  for(int i=0; i<n; i++)
  {
      cin>>x;
      v.push_back(x);
  }
  sort(v.begin(),v.end());
  
  long double sum=0;
  long double min;
   long long int cost=0;
  /*for(int i=0; i<n; i++)
   {
       sum+=v[i];
   }
   min=sum;
   avg=sum/n;
  
   for(int i=0;i<n;i++){
       if(v[i]<avg)
       {
           if(avg-v[i]<min)
           {
               min=avg-v[i];
               s=i;
           }
       }
       else if(v[i]>avg){
           if(v[i]-avg<min)
           {
               min=v[i]-avg;
               s=i;
           }
       }
       else
       {
           s=i;
       }
     
   }
  
 
   for(int i=0;i<n;i++)
   {
       if(v[i]-v[s]>0)
       {
       cost=cost+v[i]-v[s];
       }
       else 
       {
           cost=cost+v[s]-v[i];
       }
   }
 
    cout<<cost<<endl;   
 */
 s=n/2;
 for(int i=0;i<n;i++)
 {
     
       if(v[i]-v[s]>0)
       {
       cost=cost+v[i]-v[s];
       }
       else 
       {
           cost=cost+v[s]-v[i];
       }
 }
 cout<<cost<<endl;  
  return 0;
}