#include<stdio.h>
#include<algorithm>
using namespace std;
#define min(x,y)(x<y?x:y)
#define max 21
//�����ʾ
int n=7;
struct NodeType{
    int v;  //���
    int c;  //����
    bool operator<(const NodeType &s){
        return s.v<v;       //�����ݼ�����
    }
};
NodeType A[]={{1,20},{2,20},{5,20},{50,20},{10,20},{200,10},{110,20}};
int W;

//�����ʾ
int ans=0;
void solve(){   //�һ�Ӳ��
    sort(A,A+n);    //�����ݼ�����
    for(int i=0;i<n;i++){
        int t=min(W/A[i].v,A[i].c); //ʹ��Ӳ��i������
        if(t!=0)
            printf("%dԪӲ�ң�%dö\n",A[i].v,t);
            W-=t*A[i].v;    //ʣ������
            ans+=t;
            if(W==0) break;
    }
}
int main(){
    W=520;  //֧���Ľ��
    printf("���֧��%dԪ��\n",W);
    solve();
    printf("���ٵ�Ӳ��������%d\n",ans);
    return 0; 
}
