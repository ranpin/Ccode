#include<stdio.h>
int n,a[20];
long count=0;
void fun(int k); //fun(k)��ʾ��������ȷ��ĳ�����е��еĵ�k���� 

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    fun(0);
    printf("total:%d\n",count);
    return 0;
}

void fun(int k)//fun(k)��ʾ��������ȷ��ĳ�����е��еĵ�k���� 
{
    int j,t;
    if(k==n)
    {
        count++;
        for(j=0;j<n;j++) printf("%d ",a[j]);
        printf("\n");
        return ;
    }
    else
    {
        for(j=k;j<n;j++)//ע�⣺��������ԭʼ�����ڽ�������ʵ�����У�����j��k��ʼ 
        {
            t=a[k];a[k]=a[j];a[j]=t;
            fun(k+1);
            t=a[k];a[k]=a[j];a[j]=t;
        }
    }
}
