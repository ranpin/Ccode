#include<stdio.h>
#include<list>
using namespace std;
void disp(list<int>&lst){   //输出列表所有元素
    list<int>::iterator it; //定义迭代器
    for(it=lst.begin(); it!=lst.end(); it++)
        printf("%d ",*it);
        printf("\n");
}
int main(){
    list<int>lst;    
    list<int>::iterator it,start,end;   //定义迭代器
    lst.push_back(5);    
    lst.push_back(2);    
    lst.push_back(4);    
    lst.push_back(1);    
    lst.push_back(3);
    printf("初始lst: ");
    disp(lst);
    it = lst.begin();   //it指向首元素5
    start = ++lst.begin();  //start指向第二个元素
    end = --lst.end();  //end指向最后一个元素（lst.end()指向的是最后一个元素的后一个的位置）
    lst.insert(it,start,end);
    printf("插入后lst: ");
    disp(lst);
}