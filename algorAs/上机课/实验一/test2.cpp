#include<stdio.h>
#define max 8
void fun(int n,int a[][max]);

int r=1;
int main(){
    int n;
    int i=0,j=0;
    int a[max][max]={r};
    scanf("%d",&n);
    fun(n,a);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
        	if(j%7==0)
            	printf("\n");
        	printf("%d",a[i][j]);
		}
    return 0; 
}

void fun(int n,int a[][max]){
    int i=0,j=0;
    int m=i+j;
    m++;
    j++;
    for(;m<2*n;m++){
        if(i==0){
            a[i][j++]=++r;
            for(int k=0;k<m;k++)
                a[i++][j--]=++r;
        }

        if(j==0){
            a[i++][j]=++r;
            for(int k=0;k<m;k++)
                a[i--][j++]=++r; 
        }       
    }
}
