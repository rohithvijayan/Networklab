//leaky
#include<stdio.h>
int main()
{
int in,out,n,bsize,bucket=0;
printf("enter bucket size:");
scanf("%d",&bsize);
printf("enter num of inputs:");
scanf("%d",&n);
printf("enter outflow rate:");
scanf("%d",&out);
while(n!=0)
{
	 printf("enter incoming packet size:");
	 scanf("%d",&in);
	 printf("packet size:%d",in);
	if(in<=(bsize-bucket))
	{
	 bucket+=in;
	 printf("bucket status:%d out of %d",bucket,bsize);
	}
	else
	{
	 printf("Dropped packets:%d",in-(bsize-bucket));
	 printf("bucket status:%d out of %d",bucket,bsize);
	 bucket=bsize;
	}
	
	bucket=bucket-out;
	printf("After Outflow bucket status:%d out of %d",bucket,bsize);
	n--;
}
return 0;
}
