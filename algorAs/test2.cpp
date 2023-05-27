#include<stdio.h>
int count(int N,int M){
    int num=0;
    for(;N<=M;N++){
        if(N%3==0)
            continue;
        else if(N%5==0)
            num++;
            continue;
        if(N%11==0)
            continue;
        else if(N%5==0)
            num++;
            continue;
    }
    return num;
}
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    printf("%d",count(N,M));
    return 0;
}
