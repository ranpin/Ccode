#include<stdio.h>
#include<list>
using namespace std;
void disp(list<int>&lst){   //����б�����Ԫ��
    list<int>::iterator it; //���������
    for(it=lst.begin(); it!=lst.end(); it++)
        printf("%d ",*it);
        printf("\n");
}
int main(){
    list<int>lst;    
    list<int>::iterator it,start,end;   //���������
    lst.push_back(5);    
    lst.push_back(2);    
    lst.push_back(4);    
    lst.push_back(1);    
    lst.push_back(3);
    printf("��ʼlst: ");
    disp(lst);
    it = lst.begin();   //itָ����Ԫ��5
    start = ++lst.begin();  //startָ��ڶ���Ԫ��
    end = --lst.end();  //endָ�����һ��Ԫ�أ�lst.end()ָ��������һ��Ԫ�صĺ�һ����λ�ã�
    lst.insert(it,start,end);
    printf("�����lst: ");
    disp(lst);
}