#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//???????????（调试ok） 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MaxSize 1000

typedef struct linknode{
	int data[MaxSize];
	int top;
	struct linknode *next;
}SqStack;

void InitStack(SqStack *&s){		//初始化栈
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;

}

void DestoryStack(SqStack *&s){		//销毁栈
	free(s);
}

bool StackEmpty(SqStack *s){		//判断栈是否为空
	return(	s->top==-1);

}

bool Push(SqStack *&s,char e){		//进栈
	if(s->top==MaxSize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;

}

bool Pop(SqStack *&s,char &e){	//出栈
	if(s->top==-1)
		return(false);
	e=s->data[s->top];
	s->top--;
	return(true);

}

bool GetTop(SqStack *s,char &e){	//取栈顶元素
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
				Push(Optr,'(');	//左括号进栈
				exp++;	//继续扫描其他字符
				break;

			case')':	
				Pop(Optr,e);
				while(e!='('){
					postexp[i++]=e;	//将e存放到postexp中
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
				Push(Optr,*exp);	//将+-出栈
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
				while(*exp>='0' && *exp<='9')	//判定为数字字符
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


double compvalue(char *postexp){	//计算后缀表达式的值
	char d,a,b,c,e;
	SqStack *Opnd;		//定义操作数栈
	InitStack(Opnd);	//初始化操作数栈 
	while(*postexp!='\0'){		// 扫描postexp字符串直到结束 
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
				printf("\n\t除零错误！\n");
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
	printf("中缀表达式：%s\n",exp);
	printf("后缀表达式：%s\n",postexp);
	printf("表达式的值：%g\n",compvalue(postexp));
	return 1;
}

