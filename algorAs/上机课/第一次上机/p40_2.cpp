#include<stdio.h>
#include<string>
using namespace std;
int main(){
    string s1="They are students.";
    string s2="aeiou";
    for(int i=0;i<s2.length();i++){       //���s2�е�Ԫ�أ���������s1�б���ɾ����Ԫ��
        for(int j=0;j<s1.length();j++){
            int k=s1.find(s2[i],j);   //��s1��Ѱ��s2�еĵ�ǰԪ��
            if(k!=-1)
            	s1.replace(k,1,"");     //����k��λ�����ڵ�Ԫ��ɾ��
        }
    }
    printf("%s",s1.c_str());
    return 0;
}
