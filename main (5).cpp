#include<iostream>

using namespace std;
int main(){
    int a;
    cout<<"Enter the leap year:";
    cin>>a;
    if(a%4==0){
        cout<<a<<" is the leap year:";
    }
    else{
        cout<<a<<" is not a lep year:";
    }
    return 0;
}