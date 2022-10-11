#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int x=1;
    while(t--)
    {
       int r,c;
       cin>>r>>c;
       char arr[r][c];
       for(int i=0;i<r;i++)
       {
         for(int j=0;j<c;j++)
         {
            cin>>arr[i][j];
         }
       } 
       int count=0;
       for(int i=0;i<r;i++)
       {
         for(int j=0;j<c;j++)
         {
            if(arr[i][j]=='^')
            count++;
         }
       } 
        
       if(r==1 && count>0 || c==1 && count>0)
       cout<<"Case #"<<x<<": Impossible"<<endl;
       else if(count==0){
        cout<<"Case #"<<x<<": Possible"<<endl;
        for(int i=0;i<r;i++)
       {
         for(int j=0;j<c;j++)
         {
            cout<<arr[i][j];
         }
         cout<<endl;
       } 
       }
       else
       {
       for(int i=0;i<r;i++)
       {
         for(int j=0;j<c;j++)
         {
            arr[i][j]='^'; 
         }
       }
         cout<<"Case #"<<x<<": Possible"<<endl;
        for(int i=0;i<r;i++)
       {
         for(int j=0;j<c;j++)
         {
            cout<<arr[i][j];
         }
         cout<<endl;
       } 
       }
    
     x++;

    }
    return 0;
}