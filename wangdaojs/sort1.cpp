// 1)先把你要排的数输入到数组里
// 2)进行n-1次冒泡排序,从左往右两两比较
// 3)如果这个数比前面的小,那么就交换
// 4)依次输出数组

//关于数组全部有序以及部分有序的处理优化：判断某一轮是否交换元素，若未交换说明数组已经有序，直接结束算法即可

#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int number[],int n) //冒泡排序
{
	int i,j,temp;
	for(i=0;i<n-1;i++)	//n个数排序n-1次
	{
		bool swaped = false;	//判断每轮比较是否产生交换
		for(j=1;j<n-i;j++)
		{
			if(number[j]<number[j-1])	//小的放前面，大的放后面
			{
				temp=number[j];
				number[j]=number[j-1];
				number[j-1]=temp;
				swaped = true;	
			}
		}
		if(swaped == false){
			printf("%s","本轮未产生交换，算法提前结束"); 
			break;
		}
			 
	} 
 }
 int main()
 {  int n,i,j;
 	int number[n];
 	printf("%s","请输入个数n"); 
 	scanf("%d",&n);
 	printf("%s","请输入具体数字");
 	for(i=0;i<n;i++)
 	{
	 scanf("%d",&number[i]);
	}
 	BubbleSort(number, n);
 	for(j=0;j<n;j++)
 	{
 		printf("%d ",number[j]);
	}
	system("pause");
	return 0;
  } 