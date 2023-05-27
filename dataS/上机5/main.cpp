#include "stdio.h"
#define N  4
#define MaxSize 100
typedef struct
{
	int r;
	int c;
	int d;
}TupNode;
typedef struct 
{
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;
void CreatMat(TSMatrix &t,int A[N][N])
{
	int i,j;
	t.rows=N;t.cols=N;t.nums=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			if(A[i][j]!=0)
			{
				t.data[t.nums].r=i;t.data[t.nums].c=j;
				t.data[t.nums].d=A[i][j];t.nums++;
			}
	}
}
void DispMat(TSMatrix t)
{
	int i;
	if(t.nums<=0)
		return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("\t--------------------\n");
	for(i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
}
void TranMat(TSMatrix t,TSMatrix &tb)
{
	int p,q=0,v;
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if(t.nums!=0)
	{
		for(v=0;v<t.cols;v++)
			for(p=0;p<t.nums;p++)
				if(t.data[p].c==v)
				{
					tb.data[q].r=t.data[p].c;
					tb.data[q].c=t.data[p].r;
					tb.data[q].d=t.data[p].d;
					q++;
				}
	}
}
bool MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c)
{
	int i=0,j=0,k=0;
	int v;
	if(a.rows!=b.rows||a.cols!=b.cols)
		return false;
	c.rows=a.rows;c.cols=a.cols;
	while(i<a.nums&&j<b.nums)
	{
		if(a.data[i].r==b.data[j].r)
		{
			if(a.data[i].c<b.data[j].c)
			{
				c.data[k].r=b.data[j].r;
				c.data[k].c=b.data[j].c;
				c.data[k].d=b.data[j].d;
				k++;j++;
			}
			else if(a.data[i].c>b.data[j].c)
			{
		
				c.data[k].r=b.data[j].r;
				c.data[k].c=b.data[j].c;
				c.data[k].d=b.data[j].d;
				k++;j++;
			}
			else
			{
				v=a.data[i].d+b.data[j].d;
			   if(v!=0)
			   {
				  c.data[k].r=a.data[i].r;
				  c.data[k].c=a.data[i].c;
				  c.data[k].d=v;
				  k++;
			   }
			   i++;j++;
			}
		}
		else if(a.data[i].r<b.data[j].r)
		{
		   c.data[k].r=b.data[i].r;
		   c.data[k].c=b.data[i].c;
		   c.data[k].d=b.data[i].d;
		   k++;i++;
		}
     	else 
		{
		   c.data[k].r=b.data[j].r;
	       c.data[k].c=b.data[j].c;
		   c.data[k].d=b.data[j].d;
		   k++;j++;
		}
	    c.nums=k;
	}
    return true;
}
int getvalue(TSMatrix t,int i,int j)
{
	int k=0;
	while(k<t.nums&&(t.data[k].r!=i||t.data[k].c!=j))
		k++;
	if(k<t.nums)
		return (t.data[k].d);
	else 
	    return(0);
}
bool MatMul(TSMatrix a,TSMatrix b,TSMatrix &c)
{
	int i,j,k,p=0;
	int s;
	if(a.cols!=b.rows)
		return false;
	for(i=0;i<a.rows;i++)
		for(j=0;j<b.cols;j++)
		{
			s=0;
			for(k=0;k<a.cols;k++)
				s=s+getvalue(a,i,k)*getvalue(b,k,j);
			if(s!=0)
			{
				c.data[p].r=i;
				c.data[p].c=j;
				c.data[p].d=s;
				p++;
			}
		}
		c.rows=a.rows;c.cols=b.cols;c.nums=p;
		return true;
}
int main()
{
	int a1[N][N]={{1,0,3,0},{0,1,0,0},{0,0,1,0},{0,0,1,1}};
	int b1[N][N]={{3,0,0,0},{0,4,0,0},{0,0,1,0},{0,0,0,2}};
	TSMatrix a,b,c;
	CreatMat(a,a1);CreatMat(b,b1);
	printf("a的三元组:\n");DispMat(a);
	printf("b的三元组:\n");DispMat(b);
	printf("a转置为c\n");
	TranMat(a,c);
	printf("c的三元组:\n");DispMat(c);
	printf("c=a+b\n");
	MatAdd(a,b,c);
	printf("c的三元组:\n");DispMat(c);
		printf("c=a*b\n");
	MatMul(a,b,c);
	printf("c的三元组:\n");DispMat(c);
	return 1;
}






