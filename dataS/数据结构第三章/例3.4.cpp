bool symmetry(ElemType str[])	//�ж�str�Ƿ�Ϊ�Գƴ�
{
	int i;ElemType e;	
	SqStack *st;		//����˳��ջָ��
	InitStack(st);		//��ʼ��ջ
	for(i=0;str[i]!='\0';i++)		//��str������Ԫ�ؽ�ջ
		Push(st,str[i]);
	for(i=0;str[i]!='\0';i++)		//����str�������ַ�
	{
		Pop(st,e);					//��Ԫ��e��ջ
		if(str[i]!=e)			//��e�뵱ǰ���ַ���ͬ�����ʾ���ǶԳƴ�
		{
			DestoryStack(st);	//����ջ
			return false;	//���ؼ�
		}
	
	}
	DestoryStack(st);	//����ջ
	return true;	//������
}