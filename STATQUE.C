#include<stdio.h>
#include<conio.h>
#define max 4
int cque[max];
int front=-1;
int rear=-1;
void main()
{
	int ch;
	clrscr();
	while(1)
	{
		printf("\n1.Insert Element");
		printf("\n2.Delete Element");
		printf("\n3.Display Element");
		printf("\n4.Quit");
		printf("\nEnter your choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				exit();
			default:
				printf("Wrong choice\n");
		}
	}
}
insert()
{
	int item;
	if((front==0&&rear==max-1)||(front==rear+1))
	{
		printf("\n Queue overflow");
		return;
	}
	printf("\n Enter item to be inserted=");
	scanf("%d",&item);
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(rear==max-1)
			rear=0;
		else
			rear=rear+1;
	cque[rear]=item;
}
del()
{
	if(front==-1)
	{
		printf("Queue underflow\n");
		return;
	}
	printf("\nDeleted element is=%d",cque[front]);
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
		if(front==max-1)
			front=0;
		else
			front=front+1;
}
display()
{
	int fpos=front,rpos=rear,i;
	if(front==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("\nqueue contents are=");
	if(fpos<=rpos)
	{
		for(i=front;i<=rear;i++)
			printf("%d",cque[i]);
	}
	else
	{
		for(i=0;i<=rear;i++)
			printf("%d",cque[i]);
		for(i=front;i<=max-1;i++)
			printf("%d",cque[i]);
	}
}