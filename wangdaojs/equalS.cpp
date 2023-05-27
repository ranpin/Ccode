//具体思路见注释，很详细了

#include<iostream>
#include<map>
#include<limits.h>
using namespace std;
int n;

void equals(int m[],int s){
    map<int,int>intM;
    int muxl = INT_MAX; //乘积初始值设为无穷大
    int k=-1;   //k用于记录其中一个数的位置

    for(int i=0;i<n;i++){   //将数组转化成map存储
        intM[m[i]] = i;
    }
    for(int i=0;i<n;i++){   //
        map<int, int>::iterator iter = intM.find(s - m[i]) ;
        if( iter != intM.end() ){
            if( (m[i]*(s - m[i])) <= muxl){
                k=i;    //进行记录
                muxl = m[i] *(s - m[i]);     //更新muxl
            }
        }
    }
    if(k!=-1){  //如果遍历完k更新了，说明找到了符合要求的数
        cout<<"两个数为"<<m[k]<<"和"<<(s - m[k])<<"\n";
    }
    else{   //否则没找到，返回
        cout<<"数组m[]中不存在这样的两个数相加为"<<s<<"\n";
    }
}

int main(){
    int m[n],s;
    cout<<"请输入数量n：\n"; 
 	cin>>n;
 	cout<<"请输入具体数字:\n";
 	for(int i=0;i<n;i++)
 	{
	 cin>>m[i];
	}
    cout<<"请输入s：\n"; 
 	cin>>s;
    equals(m,s);
    system("pause");
    return 0;
}
