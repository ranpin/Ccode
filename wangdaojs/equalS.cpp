//����˼·��ע�ͣ�����ϸ��

#include<iostream>
#include<map>
#include<limits.h>
using namespace std;
int n;

void equals(int m[],int s){
    map<int,int>intM;
    int muxl = INT_MAX; //�˻���ʼֵ��Ϊ�����
    int k=-1;   //k���ڼ�¼����һ������λ��

    for(int i=0;i<n;i++){   //������ת����map�洢
        intM[m[i]] = i;
    }
    for(int i=0;i<n;i++){   //
        map<int, int>::iterator iter = intM.find(s - m[i]) ;
        if( iter != intM.end() ){
            if( (m[i]*(s - m[i])) <= muxl){
                k=i;    //���м�¼
                muxl = m[i] *(s - m[i]);     //����muxl
            }
        }
    }
    if(k!=-1){  //���������k�����ˣ�˵���ҵ��˷���Ҫ�����
        cout<<"������Ϊ"<<m[k]<<"��"<<(s - m[k])<<"\n";
    }
    else{   //����û�ҵ�������
        cout<<"����m[]�в��������������������Ϊ"<<s<<"\n";
    }
}

int main(){
    int m[n],s;
    cout<<"����������n��\n"; 
 	cin>>n;
 	cout<<"�������������:\n";
 	for(int i=0;i<n;i++)
 	{
	 cin>>m[i];
	}
    cout<<"������s��\n"; 
 	cin>>s;
    equals(m,s);
    system("pause");
    return 0;
}
