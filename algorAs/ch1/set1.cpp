#include<stdio.h>
#include<set>
using namespace std;
void disp(set<int>&s){  //输出集合中所有元素
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
        printf("%d ",*it);
}
void disp(multiset<int>&sm){ //输出多重集合中所有元素
    set<int>::iterator it;
    for(it=sm.begin();it!=sm.end();it++)
        printf("%d ",*it);
}
int main(){
    set<int>s;  //定义集合容器
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    disp(s);
    multiset<int>sm;  //定义多重集合容器
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(2);
    disp(sm);   
}