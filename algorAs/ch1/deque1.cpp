#include<stdio.h>
#include<deque>
using namespace std;
void disp(deque<int>&dq){   //���dq����Ԫ��
    deque<int>::iterator iter;  //���������iter
    for(iter=dq.begin();iter!=dq.end();iter++)
        printf("%d",*iter);
}
int main(){
    deque<int>dq;   //����һ��˫�˶���
    dq.push_front(1);   //��ͷ����1
    dq.push_back(2);   //��β����1
    dq.push_front(3);   //��ͷ����1
    dq.push_back(4);   //��β����1
    printf("dq: ");
    disp(dq);
    dq.pop_front();
    dq.pop_back();
    printf("dq: ");
    disp(dq);
}