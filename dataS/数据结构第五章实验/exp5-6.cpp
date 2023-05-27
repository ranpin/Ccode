#include<stdio.h>
#include<malloc.h>

#define maxsize 1000

typedef struct{
	int data[maxsize];
	int length;
}SqList;

void InitList(SqList *&L){		//��ʼ��˳���
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;

}

void DestoryList(SqList *L){	//����˳���
	free(L);

}

bool ListEmpty(SqList *L){		//�ж��Ƿ�Ϊ�ձ�
	return (L->length == 0);
	
}

int ListLength(SqList *L){		//�����Ա���
	return (L->length);

}

void DispList(SqList *L){		//������Ա�
	for(int i=0;i<L->length;i++)
		printf("%d ",L->data);
	printf("\n");

}

bool GetElem(SqList *L,int i,int &e){	//�����ĳ����Ԫ��ֵ
	if(i<1 || i>L->length)
		return false;
	e=L->data[i-1];
	return true;
}

bool ListDelete(SqList *&L,int i,int &e){	//ɾ������Ԫ��
	int j;
	if(i<1 || i>L->length)
		return false;
	i--;
	e=L->data[i];
	for(j=i;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return true;

}

void main(){
	SqList *L;
	int i,m,n,p,k,e;
	InitList(L);

	printf("�������������\n");
	scanf("%d",&n);
	L->length = n;

	for(i=0;i<n;i++)
		L->data[i] = i+1;

	printf("������������\n");
	scanf("%d",&m);
	k = 0;
	while(L->length!= 0){
		p=0;
		while(p<m){
			k = (k+1)%L->length;
			p++;
		
		}
		ListDelete(L,k,e);
		printf("%d\t",e);
	
	}
}
