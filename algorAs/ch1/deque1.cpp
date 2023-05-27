#include<stdio.h>
#include<deque>
using namespace std;
void disp(deque<int>&dq){   //输出dq所有元素
    deque<int>::iterator iter;  //定义迭代器iter
    for(iter=dq.begin();iter!=dq.end();iter++)
        printf("%d",*iter);
}
int main(){
    deque<int>dq;   //建立一个双端队列
    dq.push_front(1);   //队头插入1
    dq.push_back(2);   //队尾插入1
    dq.push_front(3);   //队头插入1
    dq.push_back(4);   //队尾插入1
    printf("dq: ");
    disp(dq);
    dq.pop_front();
    dq.pop_back();
    printf("dq: ");
    disp(dq);
}