#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>qu;
    qu.push(10);
    qu.push(7);
    qu.push(9);
    qu.push(6);
    qu.push(3);
    qu.push(1);
    qu.push(5);
    qu.push(2);
    qu.push(8);
    qu.push(4);
    int k=0; 
    printf("请输入k:");
    scanf("%d",&k);
    for(int i=0;;i++){
        if(i==10-k){
            printf("第%d小的元素是：%d\n",k,qu.top());
            break;
        }
        qu.pop();
    }
    return 0;
}
