#include<iostream>
using namespace std;

int sum =0;
int func(int n)
{
    if(n==0)
    return 0;
    sum+=n;
    func(n-1);
    return sum;

}
int main()
{
int n;
cin>>n;
cout<<func(n);
return 0;
}