#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE]; // 串中字符
    int length; // 串长
}SqString; // 声明顺序串类型

//将字符串常量赋给串s
static void str_assign(SqString &s, char cstr[])
{
    int i;

    for(i = 0; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

//销毁串
static void destroy_str(SqString &s)
{

}

//输出串s
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

//简单匹配算法BF
static int Brute_Force(SqString s, SqString t)
{
    int i = 0, j = 0;

    while(i <s.length && j <t.length)
    {
        if(s.data[i] == t.data[j])	// 继续匹配下一个字符
        {
            i++;	// 主串和子串依次匹配下一个字符
            j++;
        }
        else	// 主串、子串指针回溯重新开始下一次匹配
        {
            i = i - j + 1;	// 主串从下一个位置开始匹配
            j = 0;	// 子串从头开始匹配
        }
    }

    if(j >= t.length)
        return (i - t.length);	 // 返回匹配的第一个字符的下标
    else
        return -1;	// 模式匹配不成功
}

//由模式串t求出next值
static void get_next(SqString t, int next[])
{
    int j = 0, k = -1;

    next[0] = -1;
    while(j < t.length - 1)
    {
        if(k == -1 || t.data[j] == t.data[k])	 // k为-1或比较的字符相等时
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

//由模式串t求出nextval值
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

//KMP算法
static int KMP_index(SqString s, SqString t)
{
    int i = 0, j = 0, next[MAX_SIZE];

    get_next(t, next);
    while(j < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            // i,j各增1
            i++;
            j++;
        }
        else
            j = next[j];	// i不变,j后退
    }
    if(j >= t.length)
        return (i - t.length);	// 返回匹配模式串中的首字符下标
    else
        return -1;	// 返回不匹配标志
}

//改进的KMP算法
static int KMP_index1(SqString s, SqString t)
{
    int i = 0, j = 0, nextval[MAX_SIZE];

    get_nextval(t, nextval);
    while(i < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            // i,j各增1
            i++;
            j++;
        }
        else
            j = nextval[j];
    }

    if(j >= t.length)
        return (i - t.length);	// 返回匹配模式串中的首字符下标
    else
        return -1;	// 返回不匹配标志
}

int main(int argc, char *argv[])
{
    int j;
    int next[MAX_SIZE];
    int nextval[MAX_SIZE];
    SqString s, t;

    str_assign(s, "abcabcdabcdeabcdefabcdefg");
    str_assign(t, "abcdeabcdefab");
    printf("串s:");
    disp_str(s);
    printf("串t:");
    disp_str(t);

	printf("\n");
    printf("简单匹配算法:\n");
    printf("  t在s中的位置=%d\n", Brute_Force(s, t));
    get_next(t, next);	 // 由模式串t求出next值
    get_nextval(t, nextval);	// 由模式串t求出nextval的值
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
    printf("KMP算法:\n");
    printf("  t在s中的位置=%d\n", KMP_index(s, t));

	printf("\n");
    printf("改进的KMP算法:\n");
    printf("  t在s中的位置=%d\n", KMP_index1(s, t));

    destroy_str(s);
    destroy_str(t);
    return 0;
}
