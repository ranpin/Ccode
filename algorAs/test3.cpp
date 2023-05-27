#include<stdio.h>
int getMax(double num[],int n){
    int max;
    int index;
    max=num[0];
    for(int i=1;i<n;i++){
        if(num[i]>max){
            max=num[i];
            index=i;
        }
    }

    return index;
}
int getMax1(int num[],int n){
    int max;
    int index;
    max=num[0];
    for(int i=1;i<n;i++){
        if(num[i]>max){
            max=num[i];
            index=i;
        }
    }

    return index;
}
int main(){
    double a[1000];
    int b[1000];
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%lf %d",&a[i],&b[i]);
    printf("%d %d",getMax(a,N)+1,getMax1(b,N)+1);
    return 0;
}
