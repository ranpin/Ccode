#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//???????????������ok�� 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MaxSize 1000

typedef struct linknode{
	int data[MaxSize];
	int top;
	struct linknode *next;
}SqStack;

void InitStack(SqStack *&s){		//��ʼ��ջ
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;

}

void DestoryStack(SqStack *&s){		//����ջ
	free(s);
}

bool StackEmpty(SqStack *s){		//�ж�ջ�Ƿ�Ϊ��
	return(	s->top==-1);

}

bool Push(SqStack *&s,char e){		//��ջ
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;

}

bool Pop(SqStack *&s,char &e){	//��ջ
	if(s->top==-1)
		return(false);
	e=s->data[s->top];
	s->top--;
	return(true);

}

bool GetTop(SqStack *s,char &e){	//ȡջ��Ԫ��
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;

}

void trans(char *exp,char postexp[]){
	char e;
	SqStack *Optr;
	InitStack(Optr);
	int i=0;
	while(*exp!='\0'){
		switch(*exp){
			case'(':
				Push(Optr,'(');	//�����Ž�ջ
				exp++;	//����ɨ�������ַ�
				break;

			case')':	
				Pop(Optr,e);
				while(e!='('){
					postexp[i++]=e;	//��e��ŵ�postexp��
					Pop(Optr,e);
				}
				exp++;
				break;
			case'+':
			case'-':
				while(!StackEmpty(Optr)){
					GetTop(Optr,e);
					if(e!='('){
						postexp[i++]=e;
						Pop(Optr,e);
					}
					else break;
				
				}
				Push(Optr,*exp);	//��+-��ջ
				exp++;
				break;
			case'*':
			case'/':
				while(!StackEmpty(Optr)){
					GetTop(Optr,e);
					if(e=='*'||e=='/'){
						postexp[i++]=e;
						Pop(Optr,e);
					
					}
					else
						break;
				
				}
				Push(Optr,*exp);
				exp++;
				break;
			default:
				while(*exp>='0' && *exp<='9')	//�ж�Ϊ�����ַ�
				{
					postexp[i++]=*exp;
					exp++;
				}
				postexp[i++]='#';
		}
	
	}
	while(!StackEmpty(Optr)){
		Pop(Optr,e);
		postexp[i++]=e;

	}
	postexp[i]='\0';
	DestoryStack(Optr);

}


double compvalue(char *postexp){	//�����׺���ʽ��ֵ
	char d,a,b,c,e;
	SqStack *Opnd;		//���������ջ
	InitStack(Opnd);	//��ʼ��������ջ 
	while(*postexp!='\0'){		// ɨ��postexp�ַ���ֱ������ 
		switch(*postexp){
		case'+':
			Pop(Opnd,a);
			Pop(Opnd,b);
			c=a+b;
			Push(Opnd,c);
			break;
		case'-':
			Pop(Opnd,a);
			Pop(Opnd,b);
			c=b-a;
			Push(Opnd,c);
			break;
		case'*':
			Pop(Opnd,a);
			Pop(Opnd,b);
			c=a*b;
			Push(Opnd,c);
			break;	
		case'/':
			Pop(Opnd,a);
			Pop(Opnd,b);
			if(a!=0){
				c=b/a;
				Push(Opnd,c);
				break;
			}
			else{
				printf("\n\t�������\n");
			//	exit(0);
			}
			break;
		default:
			d=0;
			while(*postexp>='0' && *postexp<='9'){
				d=10*d+*postexp-'0';
				postexp++;
			}
			Push(Opnd,d);
			break;

		}
		postexp++;
	
	}
	GetTop(Opnd,e);
	DestoryStack(Opnd);
	return(e);
}

int main(){
	char exp[]="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	printf("��׺���ʽ��%s\n",exp);
	printf("��׺���ʽ��%s\n",postexp);
	printf("���ʽ��ֵ��%g\n",compvalue(postexp));
	return 1;
}

