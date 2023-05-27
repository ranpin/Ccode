#include<stdio.h>
#include<string>
using namespace std;
int main(){
    string s1="They are students.";
    string s2="aeiou";
    for(int i=0;i<s2.length();i++){       //拆解s2中的元素，并依次在s1中遍历删除此元素
        for(int j=0;j<s1.length();j++){
            int k=s1.find(s2[i],j);   //在s1中寻找s2中的当前元素
            if(k!=-1)
            	s1.replace(k,1,"");     //将第k个位置所在的元素删除
        }
    }
    printf("%s",s1.c_str());
    return 0;
}
