#include<stdio.h>
#include<set>
using namespace std;
void disp(set<int>&s){  //�������������Ԫ��
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
        printf("%d ",*it);
}
void disp(multiset<int>&sm){ //������ؼ���������Ԫ��
    set<int>::iterator it;
    for(it=sm.begin();it!=sm.end();it++)
        printf("%d ",*it);
}
int main(){
    set<int>s;  //���弯������
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    disp(s);
    multiset<int>sm;  //������ؼ�������
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(2);
    disp(sm);   
}