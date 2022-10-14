#include<stdio.h>
#include<conio.h>
   void main()
   { int i,j,number=1; 
     for ( i=1; i<=5;i++)
     {  for ( j=1; j<=i;j++)
        printf( "%d", number);
          number++;
     }  printf("/n");
   }