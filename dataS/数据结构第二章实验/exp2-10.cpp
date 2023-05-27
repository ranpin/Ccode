#include<stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node{
	int coe;	//系数
	int exp;	//指数
	PtrToNode next;
};
typedef PtrToNode List;


List read(){

	int n;
	List s;
	s=(List)malloc(sizeof(struct Node));
	s->next=NULL;
	scanf("%d",&n);
	if(n){
			List m=s;

			int i;

			for(i=0;i<n;i++){

				List p=(List)malloc(sizeof(struct Node));
				scanf("%d%d",&(p->coe),&(p->exp));

				m->next=p;

				m=p;

			}

			m->next=NULL;

		}

	return s;
}


void Print(List L)

{

	List r=L->next;

	if(r){

		List p=(List)malloc(sizeof(struct Node));

		p=L;

		if(p->next){

			p=p->next;

			//格式需要
			printf("%d %d",p->coe,p->exp);

			while(p->next){

				p=p->next;

				printf(" %d %d",p->coe,p->exp);

		}

		}

	}
	else

		printf("0 0");

	printf("\n");

}


List add(List L1,List L2){

	List pa,pb,pc,L;

    L = (List)malloc(sizeof(struct Node));

	L->next=NULL;

    pa=L1->next;

    pb=L2->next;
	 pc = L;

    while(pa && pb)

    {
        if(pa->exp<pb->exp){

			List temp=(List)malloc(sizeof(struct Node));
			temp->next=NULL;

			temp->coe=pb->coe;

			temp->exp=pb->exp;

			pc->next=temp;

			pc=temp;

			pb=pb->next;

		}
		else if(pa->exp==pb->exp){

			int a=pa->coe+pb->coe;

			if(a!=0){

				List temp=(List)malloc(sizeof(struct Node));

				temp->next=NULL;
				temp->exp=pa->exp;

				temp->coe=a;

				pc->next=temp;

				pc=temp;

			}

			pb=pb->next;

			pa=pa->next;
			}
		else{

			List temp=(List)malloc(sizeof(struct Node));

			temp->next=NULL;

			temp->coe=pa->coe;

			temp->exp=pa->exp;

			pc->next=temp;
			pc=temp;

			pa=pa->next;

		}

	}
	if(pa){

		while(pa){

		List temp=(List)malloc(sizeof(struct Node));

		temp->next=NULL;

		temp->coe=pa->coe;

		temp->exp=pa->exp;

		pc->next=temp;

		pc=temp;

		pa=pa->next;

		}

	}
	else{

		while(pb){

				List temp=(List)malloc(sizeof(struct Node));

				temp->coe=pb->coe;

				temp->exp=pb->exp;
				pc->next=temp;

				pc=temp;

				pb=pb->next;

		}

	}
	pc->next=NULL;

	return L;

}



List mul(List L1,List L2){

	

	List p1,p2,p3,L,Lm;

	L=(List)malloc(sizeof(struct Node));

	p1=L1->next;

	p2=L2->next;

	L->next=NULL;

	if(p1&&p2){
		for(p1=L1->next;p1;p1=p1->next){

			Lm=(List)malloc(sizeof(struct Node));

			Lm->next=NULL;

			p3=Lm;

			for(p2=L2->next;p2;p2=p2->next){
				List p4=(List)malloc(sizeof(struct Node));//尾插法

				p4->coe=p1->coe*p2->coe;

				p4->exp=p1->exp+p2->exp;

				p3->next=p4;

				p3=p4;

			}
			p3->next=NULL;//若不写，则内存出错

			L=add(L,Lm);

			free(Lm);

		}

	}	

	return L;	
	}


int main(){

	List L1,L2,LA,LM;

	L1=read();

	L2=read();

//	LA=add(L1,L2);

	LM=mul(L1,L2);

	Print(LM);

	Print(LA);

	int a=0;
	return 0;
}