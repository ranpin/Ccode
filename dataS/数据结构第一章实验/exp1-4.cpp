#include<stdio.h>
int fun1(int n){
	if(n==1)
		return 1;
	else return(n*fun1(n-1));
}

int main(){
	int n,i;
	int sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		sum=sum+fun1(i);
	printf("%d\n",sum);
	return 0;
}