#include<iostream>
using namespace std;
int add(int a , int b){
    return (a+b);
    }
void sub(int a, int b){
    cout<<(a-b)<<endl;
}
int mult(int a, int b){
    return (a*b);
}
int divide(int a, int b){
    return (a/b);
}
int rem(int a, int b){
    return (a%b);
}
int main(){

    int a,b,c;
    cin>>a>>b;
    c=add(a,b);
     cout<<c<<endl;
    sub(a,b);
    c=mult(a,b);
    cout<<c<<endl;
    c=divide(a,b);
    cout<<c<<endl;
    c=rem(a,b);
    cout<<c<<endl;
   return 0;
}
