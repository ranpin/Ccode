#include<stdio.h>
#include<map>
using namespace std;
void disp(map<char,int>&mymap){ //���ӳ������������Ԫ��
    map<char,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){ 
        printf("%c:%d",it->first,it->second);
        printf("\n");
    }
}
int main(){
    map<char,int>mymap;
    mymap.insert(pair<char,int>('a',1));    //���뷽ʽ1
    mymap.insert(map<char,int>::value_type('b',2));    //���뷽ʽ2
    mymap['c'] = 3; //���뷽ʽ3
    disp(mymap); 
}
