//19.4.25 

//�������Ա�
#define MaxSize 50
typedef struct{
	int data[MaxSize];	//���飬���ڴ�����Ա��е�Ԫ�� 
	int length;		//���� 
}SqList; 	//˳�������

//����һ�����������Ա�
/*

*/
void CreatList(SqList *&L,int a[],int n){	//�βηֱ�Ϊ���Ա� 
	int i=0,k=0;
	L=(SqList*)malloc(sizeof(SqList));	//�����ڴ�ռ�
	while(i<n){				
		L->data[k]=a[i];	//�������ֵ���δ�ŵ����Ա��� 
		i++;
		k++;
	} 
	L->length=k;	//�������Ա���Ϊk 
}
 
//��ʼ�����Ա� 
void InitList() 
