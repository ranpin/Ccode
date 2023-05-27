#include <stdio.h>
#include <malloc.h>
#define INF 32767
#define MAXV 100
typedef char InfoType;
typedef struct 
{
	int no;
	InfoType info;
}VertexType;
typedef struct
{
	int edges[MAXV][MAXV];
	int n,e;
	VertexType vexs[MAXV];
}MatGraph;
typedef struct ANode
{
	int adjvex;
	struct ANode *nextarc;
	int weight;
}ArcNode;
typedef struct Vnode
{
	int count;
	ArcNode *firstarc;
}VNode;
typedef struct
{
	VNode adjlist[MAXV];
	int n,e;
}AdjGraph;
void CreateAdj(AdjGraph *&G,int A[MAXV][MAXV],int n,int e)
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for(i=0;i<n;i++)
		G->adjlist[i].firstarc =NULL;
	for(i=0;i<n;i++)
		for(j=n-1;j>=0;j--)
			if(A[i][j]!=0&&A[i][j]!=INF)
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc ;
				G->adjlist[i].firstarc =p;
			}
	G->n=e;G->e=n;
}
void DispAdj(AdjGraph *G)
{
	ArcNode *p;
	for(int i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc ;
		printf("%3d:",i);
		while(p!=NULL)
		{
			printf("%3d[%d]",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void DestroyAdj(AdjGraph *&G)
{
	ArcNode *pre,*p;
	for(int i=0;i<G->n;i++){
		pre=G->adjlist[i].firstarc;
		if(pre!=NULL){
			p=pre->nextarc;
			while(p!=NULL)
			{
				free(pre);
				pre=p;p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}
void TopSort(AdjGraph *G){
	int i,j;
	int St[MAXV],top=-1;
	ArcNode *p;
	for(i=0;i<G->n;i++)
		G->adjlist[i].count=0;
	for(i=0;i<G->n;i++){
		p=G->adjlist[i].firstarc;
		while(p!=NULL){
			G->adjlist[p->adjvex].count++;
		    p=p->nextarc;
		}
	}
	for(i=0;i<G->n;i++)
		if(G->adjlist[i].count==0)
		{	top++;
		    St[top]=i;
		}
	while(top>-1)
	{
		i=St[top];top--;
		printf("%d",i);
		p=G->adjlist[i].firstarc;
		while(p!=NULL)
		{
			j=p->adjvex;
			G->adjlist[j].count--;
			if(G->adjlist[j].count==0)
			{
				top++;
				St[top]=j;
			}
			p=p->nextarc;
		}
	}
}
int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={	
	{0,5,INF,7,INF,INF},{INF,0,4,INF,INF,INF},
	{8,INF,0,INF,INF,9},{INF,INF,5,0,INF,6},
	{INF,INF,INF,5,0,INF},{3,INF,INF,INF,INF,0}};	
	int n=6,e=6;
	CreateAdj(G,A,n,e);
	printf("原序列为：\n");DispAdj(G);
	printf("拓扑排序为\n");TopSort(G);
	DestroyAdj(G);
	return 1;
}   

