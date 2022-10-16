#include<stdio.h>
int main()
//basic knowledge
{

   int a,i;
    float b=2.6;




    printf("%-18.6f this\n",b);
    printf("%18.6f this\n",b);
     printf("enter the number you want multiplication of:\a");    // \a is used for beep \t is used for between spaces

    scanf("%d",&a);
    printf("table of a=%d\n",a);



         for(i=1;i<=10;i++)
         {

         printf("%d*%d=%d\n",a,i,a*i);
         }

    return 0;
}
