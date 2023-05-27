bool symmetry(ElemType str[])	//判断str是否为对称串
{
	int i;ElemType e;	
	SqStack *st;		//定义顺序栈指针
	InitStack(st);		//初始化栈
	for(i=0;str[i]!='\0';i++)		//将str的所有元素进栈
		Push(st,str[i]);
	for(i=0;str[i]!='\0';i++)		//处理str的所有字符
	{
		Pop(st,e);					//将元素e退栈
		if(str[i]!=e)			//若e与当前串字符不同，则表示不是对称串
		{
			DestoryStack(st);	//销毁栈
			return false;	//返回假
		}
	
	}
	DestoryStack(st);	//销毁栈
	return true;	//返回真
}