#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>qu;
    qu.push(3);
    qu.push(1);
    qu.push(2);
    printf("��ͷԪ�أ�%d\n",qu.top());
    printf("����˳��");
    while(!qu.empty()){
        printf("%d",qu.top());
        qu.pop();
    }
    printf("\n");
}