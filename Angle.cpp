#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    float a,b,c,num,den,value,rad;
    cout<<" Input a,b,c as sides of triangle to print angle A ";
    cin>>a>>b>>c;
    num=pow(b,2)+pow(c,2)-pow(a,2);
    den=2*b*c;
    rad=acos(num/den);
    int deg = rad*57.296;
    cout<<"angle A is = "<<deg<<" Degree";
    return 0;

    

}