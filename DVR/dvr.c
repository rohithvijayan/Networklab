#include<stdio.h>
struct node{int dist[20],from[20];}route[10];
int main()
{
int dm[20][20],n,i,j,k;
printf("enter num of nodes:");
scanf("%d",&n);
printf("enter distance matrix:");
for(i=0;i<n;i++)
	{
	 for(j=0;j<n;j++)
	  {
	   scanf("%d",&dm[i][j]);
	   if(i==j)
	    {
	     dm[i][j]=0;
	    }
	    route[i].dist[j]=dm[i][j];
	    route[i].from[j]=j;
	  }
	}
int flag;
do{
 flag=0;
 for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     for(k=0;k<n;k++)
      {
       if(route[i].dist[j]>route[i].dist[k]+route[k].dist[j])
       	{
	 route[i].dist[j]=route[i].dist[k]+route[k].dist[j];
	 route[i].from[j]=route[i].from[k];    
	 flag=1; 	 
       	}
      }
    }
  }
}while(flag);
for(i=0;i<n;i++)
 {
  printf("route for router: %s/n",i+65);
  for(j=0;j<n;j++)
   {
    printf("%c\t%c\tc%d\n",j+65,route[i].from[j]+65,route[i].dist[j]);
   }
 }

}
