//19.4.25 

//声明线性表
#define MaxSize 50
typedef struct{
	int data[MaxSize];	//数组，用于存放线性表中的元素 
	int length;		//长度 
}SqList; 	//顺序表类型

//建立一个完整的线性表
/*

*/
void CreatList(SqList *&L,int a[],int n){	//形参分别为线性表， 
	int i=0,k=0;
	L=(SqList*)malloc(sizeof(SqList));	//分配内存空间
	while(i<n){				
		L->data[k]=a[i];	//将数组的值依次存放到线性表中 
		i++;
		k++;
	} 
	L->length=k;	//设置线性表长度为k 
}
 
//初始化线性表 
void InitList() 
