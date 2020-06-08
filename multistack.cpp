#include<stdio.h>
int s[50],min[50],max[50],top[50];
int ns,size,i;
void init()
{
	
	for(i=0;i<50;i++)
	{
		s[i]=min[i]=max[i]=0;
		top[i]=-1;
	}
}

void createstack()
{
	min[0]=-1;
	max[0]=size-1;
	top[0]=-1;
	
	for(i=0;i<ns;i++)
	{
		min[i]=min[i-1]+size;
		top[i]=min[i];
	}
	
	for(i=0;i<ns;i++)
	{
		max[i]=min[i+1];
	}
}

void push(int ele, int k)
{
	if(top[k-1]==max[k-1])
	{
		printf("\noverflow");
	}
	else
	{
		top[k-1]++;
		s[top[k-1]]=ele;
	}
}

void pop(int k)
{
	if(top[k-1]==min[k-1])
	{
		printf("\nUnderflow");
	}
	else
	{
		printf("\nDeleted element is : %d",s[top[k-1]]);
		top[k-1]--;
	}
}

void display(int k)
{
	int j;
	
	if(top[k-1]==min[k-1])
	{
		printf("\nEmpty");
	}
	else
	{
		printf("\nStack %d : ", k);
		for(j=min[k-1]+1;j<=top[k-1];j++)
		{
			printf("\n%d",s[j]);
		}
	}
}

main()
{
	int ele,skn,ch;
	char cho;
	init();
	
	printf("\nEnter the number of stacks to be created : ");
	scanf("%d",&ns);
	size=50/ns;
	createstack();
	do{
	
	printf("\n1.Push \n2.Pop \n3.Display ");
	printf("\nEnter choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : printf("\nEnter stack number  : ");
		         scanf("%d",&skn);
		         printf("\nEnter element : ");
		         scanf("%d",&ele);
		         push(ele,skn);
		         break;
		         
		case 2 : printf("\nEnter stack number : ");
		         scanf("%d",&skn);
		         pop(skn);
		         break;
		         
		case 3 : printf("\nEnter stack number : ");
		         scanf("%d",&skn);
		         display(skn);
		         break;
	}
	
	printf("\nContinue (y/n) :: ");
	fflush(stdin);
	scanf("%d",&cho);
	fflush(stdin);
	

	}while(cho!='n');
}
