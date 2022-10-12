#include<iostream>
using namespace std;

int fact(int a){
    int k=1;
    for (int i=a;i>0;i--){
        k=k*i;
        
    }
    return k;
}

int main(){
    int a;
    cin>>a;
    cout<<fact(a);
    return 0;
}