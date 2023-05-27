#include<stdio.h>
int fun(int ct,int tt){
    int time;
    if(ct>tt)
        time=tt+(24-ct);
    else
        time=tt-ct;
    return time;
}
int main(){
    int ct,tt,time;
    scanf("%d %d",&ct,&tt);
    printf("%d",fun(ct,tt));
    return 0;
}
