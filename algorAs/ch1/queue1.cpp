#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    queue<int>qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    printf("��ͷԪ�أ�%d\n",qu.front());
    printf("��βԪ�أ�%d\n",qu.back());
    printf("����˳��");
    while(!qu.empty()){
        printf("%d",qu.front());
        qu.pop();
    }
    printf("\n");
}