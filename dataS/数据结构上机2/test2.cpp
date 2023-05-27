#include<stdio.h>
#include<malloc.h>

#define MAX 100
typedef struct    //����x��ĳ��ʽ
{
	double coef;
	int exp;
}PolyArray;

typedef struct pnode  //��������ʽ
{	double coef;	//ϵ�� 
	int exp;		//ָ�� 
	struct pnode *next;	//ָ����һ���ָ�� 
}PolyNode;

void DispPoly(PolyNode *L)  //��ʾ����ʽ
	{
		bool first=true;
		PolyNode *p=L->next;
		while(p!=NULL)
		{
			if(first)
				first=false;
				else if(p->coef>0)
					printf("+");
				if(p->exp==0)		//ָ��Ϊ0���ϵ�� 
					printf("%g",p->coef);
				else if(p->exp==1)		//ָ��Ϊ1�����ϵ��x(�磺3.5x) 
					printf("%gx",p->coef);
				else					//ָ������1,���ϵ��xָ�����磺3.5x^2�� 
					printf("%gx^%d",p->coef,p->exp);
				p=p->next;
		}
			printf("\n");
	}

void DestroyPoly(PolyNode *&L)  //ɾ������ʽ
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
	
void CreatePolyR(PolyNode *&L,PolyArray a[],int n)	//������ʽת��������
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
	
void Sort(PolyNode *&L)  //����ʽ����
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
	
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc) //����ʽ���
	{
		PolyNode *pa=ha->next,*pb=hb->next,*s,*r;
		double c;
		hc=(PolyNode *)malloc(sizeof(PolyNode));
		r=hc;
		while(pa!=NULL&&pb!=NULL)		//��������ʽ
		{
			if(pa->exp>pb->exp)		//ha��ĳ�������hb�и�ʱ 
			{
				s=(PolyNode *)malloc(sizeof(PolyNode));
				s->exp=pa->exp;
				s->coef=pa->coef;
				r->next=s;
				r=s;
				pa=pa->next;
			}
			else if(pa->exp<pb->coef)		//ha��ĳ�������hb�е�ʱ 
			{
				s=(PolyNode *)malloc(sizeof(PolyNode));
				s->exp=pb->exp;
				s->coef=pb->coef;
				r->next=s;
				r=s;
				pb=pb->next;
			}
			else		//ha��ĳ�������hb�����
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
		if(pb!=NULL) pa=pb;	 //���ab������ͬ 
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
		printf("ԭ����ʽA:  ");DispPoly(ha);
		printf("ԭ����ʽB:  ");DispPoly(hb);
		Sort(ha);
		Sort(hb);
		printf("�������ʽA:  ");DispPoly(ha);
		printf("�������ʽB:  ");DispPoly(hb);
		Add(ha,hb,hc);
		printf("����ʽ���:  ");DispPoly(hc);
		DestroyPoly(ha);
		DestroyPoly(hb);
		DestroyPoly(hc);
		return 0;
	}
 
