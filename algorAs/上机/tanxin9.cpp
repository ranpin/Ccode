#include<stdio.h>
#include<string.h>
#define max 20
//�����ʾ
int n;

//�������ʾ
int a[max]; //��ű��ֽ����
int k=0;
void solve(){
    int i;
    int sum=1;
    if(n<4)     //���������ŷ���
        return;
    else{
        int m=n;     //m��ʾʣ�µ���
        a[0]=2;
        m-=a[0];
        k=0;
        while(m>a[k]){
            k++;
            a[k]=a[k-1]+1;
            m-=a[k];
        }
        if(m<a[k]){
            for(i=0;i<m;i++)
                a[k-i]+=1;
        }
        if(m==a[k]){
            a[k]+=2;
            for(i=0;i<k;i++)
                a[i]+=1;
        }
    }
}
int main(){
    n=75;
    memset(a,0,sizeof(a));
    solve();
    printf("%d�����ŷֽⷽ��\n",n);
    int mul=1;
    printf("�ֽ������");
    for(int i=0;i<k;i++)
        if(a[i]!=0){
            printf("%d ",a[i]);
            mul*=a[i];
        }
    printf("\n �˻����ֵ��%d\n",mul);
    return 0;
}
