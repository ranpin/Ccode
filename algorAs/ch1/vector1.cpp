#include<stdio.h>
#include<vector>
using namespace std;
int main(){
    vector<int>myv; //定义vector容器
    vector<int>::iterator it; //定义myv的正向迭代器
    myv.push_back(1);   //在容器末尾添加元素1
    it = myv.begin();   //迭代器指向开头元素1
    myv.insert(it,2);   //在it指向的元素之前添加元素2
    myv.push_back(3);   //在容器末尾添加元素3    
    myv.push_back(4);   //在容器末尾添加元素4    
    it = myv.end(); //it迭代器指向尾元素后面
    it--;   //指向尾元素
    myv.erase(it);  //删除当前容器中的迭代器it指定的元素4
    for ( it = myv.begin(); it != myv.end(); ++it)
    {
        printf("%d  ",*it);
    }
    printf("\n");
}
