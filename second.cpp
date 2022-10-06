#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int a,b,c;
  cout<<"enter first number";
  cin>>a;
  cout<<"enter second number";
  cin>>b;
  cout<<"enter third number";
  cin>>c;
  if (a>b){
    if (a>c){
      cout<<a<<"is greatest number";
    }
  }
  if(b>c){
    if(b>a){
      cout<<b<<"is greatest number";
    }
  }
  else{
    cout<<c<<"is greatest number."<<endl;
  }
  return (0);
}
