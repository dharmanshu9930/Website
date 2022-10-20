#include<stdio.h>
void main()
{
int i,s=0; 
for(i=0;i<=4;i++)
{printf("enter number for undex X[%d]:",i);
scanf("%d",&x[i]);
}
for(i=0;i<=4;i++)
{printf("%d,",x[i]);
s=s+x[i];
}
printf("sum:%d",s);
}