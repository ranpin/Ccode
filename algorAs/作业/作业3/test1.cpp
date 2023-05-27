#include <stdio.h>
#include<string.h>
#define N 20  
int lcslength(char *a,char * b, int c[][N]) 
{
	int m=strlen(a),n=strlen(b);
    int i,j;
    for (i=0;i<=m;i++)
		c[i][0]=0;
	for (i=0;i<=n;i++)
		c[0][i]=0;
	for (i= 1;i<=m;i++)
		for (j=1;j<=n;j++)
		{
			if (a[i-1]==b[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else  
			{ 
				if (c[i-1][j]>=c[1][j-1])
					c[i][j] =c[i-1][j];
				else
					c[i][j]=c[i][j-1];
			}
		}
		return c[m][n];
}
char * buildlcs(char *a,char * b)
{ 
	int k, i= strlen(a),j= strlen(b);
	int c[N][N];
	k= lcslength(a,b,c);
	static char s[N];
	s[k]= '\0';
	while (k>0)
		if (c[i][j]==c[i-1][j]) i--;
		else 
			if (c[i][j]==c[i][j-1]) j--;
			else
			{ 
				s[--k]=a[i-1];
				i-- ; j--;
			}
return s;
}
int main()
{
	char X[]="abcbacbbdb";
	char Y[]="acbbaacbbdbbbdc";
	printf("X:%s\n",X);
	printf("Y:%s\n",Y);
	printf("最长公共子序列%s\n",buildlcs(X,Y));
	return 0;
}
