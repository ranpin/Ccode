#include<stdio.h>
#include<math.h>

void inc(int b[], int n)	//��b��ʾ�Ķ���������1
{  for(int i=0;i<n;i++)	//��������b
   {  if (b[i])		//��Ԫ��1��Ϊ0
	 b[i]=0;
      else			//��Ԫ��0��Ϊ1���˳�forѭ��
      {  b[i]=1;
         break;
      }
   }
}

void PSet(int a[],int b[],int n)	//���ݼ�
{  int i,k;
   int pw=(int)pow(2,n);		//��2^n
   printf("1��%d���ݼ�:\n  ",n);
   for(i=0;i<pw;i++)			//ִ��2^n��
   {	printf("{ ");
	for (k=0;k<n;k++)		//ִ��n��
	   if(b[k])
	      printf("%d ",a[k]);
	printf("}\n");
	inc(b,n);			//b��ʾ�Ķ���������1
   }
   printf("\n");
}

int main(){
    int n=0;
    scanf("%d",&n);
    int a[n];
    int b[n];
    for(int i=1;i<=n;i++){
    a[i-1]=i;
    b[i-1]=0;
    }
    PSet(a,b,n);
    
}
