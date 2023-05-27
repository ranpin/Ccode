#include <stdio.h>

#define M 4 //����
#define N 4 //����
#define MAX_SIZE 100 //ջ���Ԫ�ظ���

// mgΪ�Թ���ά����:һ���Թ�,�����ܼ��Ͼ�Ϊ1�ı߿�
int mg[M + 2][N + 2] = {
    {1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1}
};

//����ȫ�ֱ���
//����ջ�ʹ�����·��������
struct
{
    int i; // ������
    int j; // ������
    int di;
}St[MAX_SIZE], Path[MAX_SIZE];

int top = -1; //ջ��ָ��
int cnt = 1; //·��������
int minlen = MAX_SIZE; //���·������

// ���һ��·���������·��
static void disp_path()
{
    int k;

    printf("  %5d: ", cnt++); // �����cnt��·��
    for(k = 0; k <= top; k++)
        printf("(%d,%d)", St[k].i, St[k].j);
    printf("\n");

    if(top + 1 < minlen) //�Ƚ������·��
    {
        for(k = 0; k <= top; k++) //�����·�������path��
            Path[k] = St[k];
        minlen = top + 1; // �����·�����ȴ����minlen��
    }
}

//�����һ�����·��
static void disp_min_path()
{
    int k;

    printf("���·������:\n");
    printf("����: %d\n", minlen);
    printf("·��: ");

    for(k = 0; k < minlen; k++)
        printf("(%d,%d)", Path[k].i, Path[k].j);

    printf("\n");
}

/*
   ����:���Թ�·��
   xi:��ں�����
   yi:���������
   xe:���ں�����
   ye:����������
*/
static void mg_path(int xi, int yi, int xe, int ye)
{
    int i, j, i1, j1, di;
    bool is_find;

    top++; // ��ջ
    St[top].i = xi;
    St[top].j = yi;
    St[top].di = -1; mg[xi][yi] = -1; // ��ʼ�����ջ
    while(top > -1) // ջ����ʱѭ��
    {
        i = St[top].i; j = St[top].j; // ȡջ������(i,j)
        di = St[top].di;
        if(i == xe && j == ye) // �ҵ��˳���
        {
            disp_path(); // ���һ��·��
            mg[i][j] = 0; // �ó��ڱ�Ϊ����·�����߷���
            top--; // ������ջ,������һ������
            i = St[top].i; j = St[top].j;
            di = St[top].di; // ��ջ�������Ϊ��ǰ����
        }
        is_find = false; // ����һ�����߷���(i1,j1);
        while(di < 4 && !is_find)
        {
            di++;
            switch(di)
            {
            case 0:
                i1 = i - 1;
                j1 = j;
                break;
            case 1:
                i1 = i;
                j1 = j + 1;
                break;
            case 2:
                i1 = i + 1;
                j1 = j;
                break;
            case 3:
                i1 = i;
                j1 = j - 1;
                break;
            }
            if(mg[i1][j1] == 0)
                is_find = true;
        }
        if(is_find) // �ҵ�����һ�����߷���(i1,j1)
        {
            St[top].di = di; // �޸�ԭջ��Ԫ�ص�diֵ
            top++; St[top].i = i1, St[top].j = j1;
            St[top].di = -1; // ��һ�����߷���(i1,j1)��ջ
            mg[i1][j1] = -1; // �����ظ��ߵ��÷���
        }
        else // û��·������,��(i,j)������ջ
        {
            mg[i][j] = 0; // �ø�λ�ñ�Ϊ����·�����߷���
            top--;
        }
    }
    disp_min_path(); // ������·��
}

int main(int argc, char *argv[])
{
    printf("�Թ�����·������:\n");
    mg_path(1, 1, M, N);

    return 0;
}
