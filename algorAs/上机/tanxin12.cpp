#include <stdio.h> 
#include <string.h> 
#include <algorithm> 
using namespace std;
#define max 51 
//�����ʾ
struct Action{     //�����
	int b;       //��ʼʱ��
    int e;       //����ʱ��
    	bool operator<(const Action &s) const{ 	//����<��ϵ����
            if (e==s.e)     //����ʱ����ͬ����ʼʱ���������
              	return b<=s.b;
            else       //���򰴽���ʱ���������
                return e<=s.e;
            } 
};
int n=8;
Action A[]={{0},{1,9},{2,4},{3,6},{5,8},{4,7}}; 
//�������ʾ
int ans;        //���ٻ᳡���� 
void solve(){       //��������ݻ�Ӽ� 
   bool flag[max];     //���־  
    memset(flag,0,sizeof(flag));  
    sort(A+1,A+n+1);     //A[1..n]��ָ����ʽ����  
    ans=0;         
    for (int j=1;j<=n;j++){ 
        if (!flag[j])
		{ 
            flag[j]=true;    
            int pre=j;    //ǰһ�����ݻ���±�    
            for (int i=pre+1;i<=n;i++){ 
                if (A[i].b>=A[pre].e && !flag[i]){ 
                    pre=i;      
                    flag[i]=true;     
                    }    
            }    
            ans++;     //����һ�������ݻ�Ӽ�   
        }  
    } 
}
int main(){ 
    solve();  
    printf("�����\n"); 
	printf("�����:%d\n",n);
    printf("���ٻ᳡����: %d\n",ans);  
    return 0;
}
