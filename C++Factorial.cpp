#include<iostream>
#include<Math.h>
using namespace std;
 
int main() {

int n;
cout<<"enter your number : ";
cin>>n;

int factorial = 1;

for(int i=2;i<=n;i++) {
    factorial*=i;
    
}
cout<<factorial;

    return 0;
}
