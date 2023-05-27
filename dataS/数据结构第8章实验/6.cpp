#include <graph.cpp>
#define MaxSize 100
typedef struct 
{
	int u;
	int v;
	int w;
}Edge;
void InsertSort(Edge E[],int n)
{
	int i,j;
	Edge temp;
	for(i=1;i<n;i++)
	{
		temp=E[i];
		j=i-1;
		while(j>=0&&temp.w<E[j].w)
		{
			E[j+1]=E[j];
			j--;
		}
		E[j+1]=temp;
	}
}
void Kruskal(MatGraph g)
{
	int i,j,u1,v1,sn1,sn2,k;
	int vset[MAXV];
	Edge E[MaxSize];
	k=0;
	for(i=0;i<g.n;i++)
	   for(j=0;j<=i;j++)
	   {
	   	if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
	   	{
	   		E[k].u=i;E[k].v=j;E[k].w=g.edges[i][j];
	   		k++;
		   }
	   }
	   InsertSort(E,g.e);
	   for(i=0;i<g.n;i++)
	       vest[i]=i;
	    k=1;
	    j=0;
	    while(k<g.n)
	    {
	    	u1=E[i].u;v1=E[j].v;
	    	sn1=vest[u1];
	    	sn2=vest[v1];
	    	if(sn1!=sn2)
	    	{
	    		printf("  (%d,%d):%d\n",u1,v1,E[j].w);
	    		k++;
	    		for(i=0;i<g.n;i++)
	    		   if(vest[i]==sn2)
	    		      vest[i]=sn1;
			}
			j++;
		}
}
int main()
{
	int u=3;
	MatGraph g;
	int A[MAXV][MAXV]={
	{0,5,8,7,INF,3},{5,0,4,INF,INF,INF},{8,4,0,5,INF,9},
	{7,INF,5,0,5,6},{INF,INF,INF,5,0,1},{3,INF,9,6,0,1}};
	int n=6,e=10;
	CreateMat(g,A,n,e);
	printf("图G的邻接矩阵：\n");DispMat(g);
	printf("克鲁斯卡尔算法求解结果：\n");
	Kruskal(g);
	rerurn 1;
}

