#include<iostream>

using namespace std;

int add(float p,float q)
{
    return p+q;
}
int sub(float p,float q)
{
    return p-q;
}
int prod(float p,float q)
{
    return p*q;
}
int quot(float p,float q)
{
    return p/q;
    
}

int main()
{
    cout<<"CALCULATOR";
    int a;
    float b,c,x,y,z,w;
    cout<<"\n1. addition\n2. Subraction\n3. Multiplication\n4. Divison\nEnter your choice: ";
    cin>>a;
    cout<<"Enter number 1: ";
    cin>>b;
    cout<<"Enter number 2: ";
    cin>>c;
    
    switch(a)
    {
        case 1: a == 1; x = add(b,c);  cout<<x; break;
        case 2: a == 2; y = sub(b,c);  cout<<y; break;
        case 3: a == 3; z = prod(b,c); cout<<z; break;
        case 4: a == 4; w = quot(b,c); cout<<w; break;
        default: cout<<"Enter a valid number";


    }
    return 0;

}    

