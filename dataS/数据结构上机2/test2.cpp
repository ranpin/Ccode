#include<stdio.h>
#include<malloc.h>

#define MAX 100
typedef struct    //声明x的某次式
{
	double coef;
	int exp;
}PolyArray;

typedef struct pnode  //声明多项式
{	double coef;	//系数 
	int exp;		//指数 
	struct pnode *next;	//指向下一项的指针 
}PolyNode;

void DispPoly(PolyNode *L)  //显示多项式
	{
		bool first=true;
		PolyNode *p=L->next;
		while(p!=NULL)
		{
			if(first)
				first=false;
				else if(p->coef>0)
					printf("+");
				if(p->exp==0)		//指数为0输出系数 
					printf("%g",p->coef);
				else if(p->exp==1)		//指数为1，输出系数x(如：3.5x) 
					printf("%gx",p->coef);
				else					//指数大于1,输出系数x指数（如：3.5x^2） 
					printf("%gx^%d",p->coef,p->exp);
				p=p->next;
		}
			printf("\n");
	}

void DestroyPoly(PolyNode *&L)  //删除多项式
	{
		PolyNode *pre=L,*p=pre->next;
		while(p!=NULL)
		{
			free(pre);
			pre=p;
			p=pre->next;
		}
		free(pre);
	}
	
void CreatePolyR(PolyNode *&L,PolyArray a[],int n)	//将多项式转化成链表
	{
		PolyNode *s,*r;
		int i;
		L=(PolyNode *)malloc(sizeof(PolyNode));
		L->next=NULL;
		r=L;
		for(i=0;i<n;i++)
		{
			s=(PolyNode *)malloc(sizeof(PolyNode));
			s->coef=a[i].coef;
			s->exp=a[i].exp;
			r->next=s;
			r=s;
		}
		r->next=NULL;
	}
	
void Sort(PolyNode *&L)  //多项式排序
	{
		PolyNode *p=L->next,*pre,*q;
		if(p!=NULL)
		{
			q=p->next;
			p->next=NULL;
			p=q;
			while(p!=NULL)
			{
				q=p->next;
				pre=L;
				while(pre->next!=NULL&&pre->next->exp>p->exp)
					pre=pre->next;
				p->next=pre->next;
				pre->next=p;
				p=q;
			}
		}
	}
	
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc) //多项式相加
	{
		PolyNode *pa=ha->next,*pb=hb->next,*s,*r;
		double c;
		hc=(PolyNode *)malloc(sizeof(PolyNode));
		r=hc;
		while(pa!=NULL&&pb!=NULL)		//遍历多项式
		{
			if(pa->exp>pb->exp)		//ha中某项次数比hb中高时 
			{
				s=(PolyNode *)malloc(sizeof(PolyNode));
				s->exp=pa->exp;
				s->coef=pa->coef;
				r->next=s;
				r=s;
				pa=pa->next;
			}
			else if(pa->exp<pb->coef)		//ha中某项次数比hb中低时 
			{
				s=(PolyNode *)malloc(sizeof(PolyNode));
				s->exp=pb->exp;
				s->coef=pb->coef;
				r->next=s;
				r=s;
				pb=pb->next;
			}
			else		//ha中某项次数和hb中相等
			{
				c=pa->coef+pb->coef;
				if(c!=0)
				{ 
					s=(PolyNode *)malloc(sizeof(PolyNode));
					s->exp=pa->exp;
					s->coef=c;
					r->next=s;
					r=s;
				}
				pa=pa->next;
				pb=pb->next;
			}
		}
		if(pb!=NULL) pa=pb;	 //如果ab项数不同 
		while(pa!=NULL)
		{
			s=(PolyNode *)malloc(sizeof(PolyNode));
			s->exp=pa->exp;
			s->coef=pa->coef;
			r->next=s;
			r=s;
			pa=pa->next;
		}
		r->next=NULL;
	}
	
int main()
	{
		PolyNode *ha,*hb,*hc;
		PolyArray a[]={{2.5,2},{2.5,1},{2.5,3},{-3.5,5}};
		PolyArray b[]={{-1.5,0},{2.5,1},{3.5,3},{2.5,5},{5.5,6}};
		CreatePolyR(ha,a,4);
		CreatePolyR(hb,b,5);
		printf("原多项式A:  ");DispPoly(ha);
		printf("原多项式B:  ");DispPoly(hb);
		Sort(ha);
		Sort(hb);
		printf("有序多项式A:  ");DispPoly(ha);
		printf("有序多项式B:  ");DispPoly(hb);
		Add(ha,hb,hc);
		printf("多项式相加:  ");DispPoly(hc);
		DestroyPoly(ha);
		DestroyPoly(hb);
		DestroyPoly(hc);
		return 0;
	}
 
