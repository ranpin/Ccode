#include<stdio.h>
int n; 
int mark[100];//记录分解情况
void divide(int now, int k, int pre);
int main()
{
scanf("%d", &n);
divide(0, 0, n - 1);

return 0;
}
//now记录数组当前长度，k记录递归深度， pre记录前一个的值
void divide(int now, int k, int pre)
{
    int i;
	if(now > n) return; 

    if (now == n){
        printf("%d:", n);
        for(i = 0; i < k - 1; i++){
            printf("%d ", mark[i]);
        }
        printf("%d\n", mark[i]);
    } else {
        for(i = pre; i > 0; i--){
            if( i <= pre){
                mark[k] = i;
                now += i;
                divide(now, k + 1, i);
                now -= i;
            }
        }
    }
}

