#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    float a,b,c,p,q,r,x,y;
    cout<<"Enter cofficients of two lines to find point of intersection ";
    cin>>a>>b>>c>>p>>q>>r;
    x=((b*r)-(q*c))/((a*q)-(p*b));
    y=((c*p)-(a*r))/((a*q)-(p*b));
    cout<<"Point of Intersection = "<<"("<<(x)<<","<<(y)<<")\n";
    return 0;
}