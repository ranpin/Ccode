#include<stdio.h>
#include<vector>
using namespace std;
int main(){
    vector<int>myv; //����vector����
    vector<int>::iterator it; //����myv�����������
    myv.push_back(1);   //������ĩβ���Ԫ��1
    it = myv.begin();   //������ָ��ͷԪ��1
    myv.insert(it,2);   //��itָ���Ԫ��֮ǰ���Ԫ��2
    myv.push_back(3);   //������ĩβ���Ԫ��3    
    myv.push_back(4);   //������ĩβ���Ԫ��4    
    it = myv.end(); //it������ָ��βԪ�غ���
    it--;   //ָ��βԪ��
    myv.erase(it);  //ɾ����ǰ�����еĵ�����itָ����Ԫ��4
    for ( it = myv.begin(); it != myv.end(); ++it)
    {
        printf("%d  ",*it);
    }
    printf("\n");
}
