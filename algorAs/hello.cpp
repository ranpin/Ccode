#include<stdio.h>
void BubbleSort(int number[],int n) //冒泡排序?
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(number[j]<number[j-1])
			{
				temp=number[j];
				number[j]=number[j-1];
				number[j-1]=temp;
			}
		 } 
	} 
 }
 int main()
 {  int n,i,j;
 	int number[n];
 	printf("输入个数"); 
 	scanf("%d",&n);
 	printf("输入数字");
 	for(i=0;i<n;i++)
 	{
	 scanf("%d",&number[i]);
	 }
 	BubbleSort(number, n);
 	for(j=0;j<n;j++)
 	{
 		printf("%d ",number[j]);
	 }
	 return 0;
  } 