#include <stdio.h> 
#include <string.h> 
#include <algorithm> 
using namespace std;
#define max 51 
//问题表示
struct Action{     //活动类型
	int b;       //起始时间
    int e;       //结束时间
    	bool operator<(const Action &s) const{ 	//重载<关系函数
            if (e==s.e)     //结束时间相同按开始时间递增排序
              	return b<=s.b;
            else       //否则按结束时间递增排序
                return e<=s.e;
            } 
};
int n=8;
Action A[]={{0},{1,9},{2,4},{3,6},{5,8},{4,7}}; 
//求解结果表示
int ans;        //最少会场个数 
void solve(){       //求解最大兼容活动子集 
   bool flag[max];     //活动标志  
    memset(flag,0,sizeof(flag));  
    sort(A+1,A+n+1);     //A[1..n]按指定方式排序  
    ans=0;         
    for (int j=1;j<=n;j++){ 
        if (!flag[j])
		{ 
            flag[j]=true;    
            int pre=j;    //前一个兼容活动的下标    
            for (int i=pre+1;i<=n;i++){ 
                if (A[i].b>=A[pre].e && !flag[i]){ 
                    pre=i;      
                    flag[i]=true;     
                    }    
            }    
            ans++;     //增加一个最大兼容活动子集   
        }  
    } 
}
int main(){ 
    solve();  
    printf("求解结果\n"); 
	printf("活动个数:%d\n",n);
    printf("最少会场个数: %d\n",ans);  
    return 0;
}
