#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE]; // �����ַ�
    int length; // ����
}SqString; // ����˳������

//���ַ�������������s
static void str_assign(SqString &s, char cstr[])
{
    int i;

    for(i = 0; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

//���ٴ�
static void destroy_str(SqString &s)
{

}

//�����s
static void disp_str(SqString s)
{
    int i;

    if(s.length > 0)
    {
        for(i = 0; i < s.length; i++)
            printf("%c", s.data[i]);
        printf("\n");
    }
}

//��ƥ���㷨BF
static int Brute_Force(SqString s, SqString t)
{
    int i = 0, j = 0;

    while(i <s.length && j <t.length)
    {
        if(s.data[i] == t.data[j])	// ����ƥ����һ���ַ�
        {
            i++;	// �������Ӵ�����ƥ����һ���ַ�
            j++;
        }
        else	// �������Ӵ�ָ��������¿�ʼ��һ��ƥ��
        {
            i = i - j + 1;	// ��������һ��λ�ÿ�ʼƥ��
            j = 0;	// �Ӵ���ͷ��ʼƥ��
        }
    }

    if(j >= t.length)
        return (i - t.length);	 // ����ƥ��ĵ�һ���ַ����±�
    else
        return -1;	// ģʽƥ�䲻�ɹ�
}

//��ģʽ��t���nextֵ
static void get_next(SqString t, int next[])
{
    int j = 0, k = -1;

    next[0] = -1;
    while(j < t.length - 1)
    {
        if(k == -1 || t.data[j] == t.data[k])	 // kΪ-1��Ƚϵ��ַ����ʱ
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

//��ģʽ��t���nextvalֵ
static void get_nextval(SqString t, int nextval[])
{
    int j = 0, k = -1;

    nextval[0] = -1;
    while(j < t.length)
    {
        if((k == -1) || (t.data[j] == t.data[k]))
        {
            j++;
            k++;
            if(t.data[j] != t.data[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}

//KMP�㷨
static int KMP_index(SqString s, SqString t)
{
    int i = 0, j = 0, next[MAX_SIZE];

    get_next(t, next);
    while(j < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            // i,j����1
            i++;
            j++;
        }
        else
            j = next[j];	// i����,j����
    }
    if(j >= t.length)
        return (i - t.length);	// ����ƥ��ģʽ���е����ַ��±�
    else
        return -1;	// ���ز�ƥ���־
}

//�Ľ���KMP�㷨
static int KMP_index1(SqString s, SqString t)
{
    int i = 0, j = 0, nextval[MAX_SIZE];

    get_nextval(t, nextval);
    while(i < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            // i,j����1
            i++;
            j++;
        }
        else
            j = nextval[j];
    }

    if(j >= t.length)
        return (i - t.length);	// ����ƥ��ģʽ���е����ַ��±�
    else
        return -1;	// ���ز�ƥ���־
}

int main(int argc, char *argv[])
{
    int j;
    int next[MAX_SIZE];
    int nextval[MAX_SIZE];
    SqString s, t;

    str_assign(s, "abcabcdabcdeabcdefabcdefg");
    str_assign(t, "abcdeabcdefab");
    printf("��s:");
    disp_str(s);
    printf("��t:");
    disp_str(t);

	printf("\n");
    printf("��ƥ���㷨:\n");
    printf("  t��s�е�λ��=%d\n", Brute_Force(s, t));
    get_next(t, next);	 // ��ģʽ��t���nextֵ
    get_nextval(t, nextval);	// ��ģʽ��t���nextval��ֵ
    printf("   j    ");
    for(j = 0; j < t.length; j++)
        printf("%4d", j);
    printf("\n");
    printf("t[j]    ");
    for(j = 0; j < t.length; j++)
        printf("%4c", t.data[j]);
    printf("\n");
    printf("next    ");
    for(j = 0; j < t.length; j++)
        printf("%4d", next[j]);
    printf("\n");

    printf("nextval ");
    for(j = 0; j < t.length; j++)
        printf("%4d", nextval[j]);
    printf("\n");
	
	printf("\n");
    printf("KMP�㷨:\n");
    printf("  t��s�е�λ��=%d\n", KMP_index(s, t));

	printf("\n");
    printf("�Ľ���KMP�㷨:\n");
    printf("  t��s�е�λ��=%d\n", KMP_index1(s, t));

    destroy_str(s);
    destroy_str(t);
    return 0;
}
