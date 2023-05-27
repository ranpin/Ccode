#include<stdio.h>
#include<algorithm>
using namespace std;
#define min(x,y)(x<y?x:y)
#define max 21
//问题表示
int n=7;
struct NodeType{
    int v;  //面额
    int c;  //数量
    bool operator<(const NodeType &s){
        return s.v<v;       //按面额递减排序
    }
};
NodeType A[]={{1,20},{2,20},{5,20},{50,20},{10,20},{200,10},{110,20}};
int W;

//结果表示
int ans=0;
void solve(){   //兑换硬币
    sort(A,A+n);    //按面额递减排序
    for(int i=0;i<n;i++){
        int t=min(W/A[i].v,A[i].c); //使用硬币i的数量
        if(t!=0)
            printf("%d元硬币：%d枚\n",A[i].v,t);
            W-=t*A[i].v;    //剩余的面额
            ans+=t;
            if(W==0) break;
    }
}
int main(){
    W=520;  //支付的金额
    printf("如果支付%d元：\n",W);
    solve();
    printf("最少的硬币总数：%d\n",ans);
    return 0; 
}
