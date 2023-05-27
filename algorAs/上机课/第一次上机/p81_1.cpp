#include<iostream>
using namespace std;

const int maxn = 50;
int n;
int a[maxn][maxn];

//len表示矩阵的边长，也属于一个问题参量 , k表示当前是第几个矩阵 
void f(int s, int e, int len, int k)			//将i---j的螺旋矩阵装到二维数组中 
{
	//递归边界 
	if(len == 1)
	{
		a[k][k] = s;
		return ;
	}
	else if(len == 2)
	{
		a[k][k] = s++;
		a[k][k + 1] = s++;
		a[k + 1][k + 1] = s;
		a[k + 1][k] = e;
		return ;
	}
	
	//矩阵上边框 
	int col = n + 1 - k;			//表示右边框的列号和下边框的行号 
	int x = s;
	for(int j = k;j <= col;j++)		//这里循环条件之前手误写成j <= len了，导致错误 
	{
		a[k][j] = x;
		x++;
	} 
	//矩阵右边框
	for(int i = k + 1;i <= col;i++)
	{
		a[i][col] = x;
		x++;
	} 
	//矩阵下边框
	for(int j = col - 1;j >= k;j--) 
	{
		a[col][j] = x;
		x++;
	}
	//矩阵左边框
	for(int i = col - 1;i >= k + 1;i--)
	{
		a[i][k] = x;
		x++;
	}
	f(x, n * n, len - 2, k + 1);		//递归，填充小螺旋矩阵
}

int main()
{
	cin >> n;
	f(1, n * n, n, 1);			//从k = 1开始，第一个矩阵 
	//print a
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			printf("%5d", a[i][j]);			//输出右对齐
		}
		cout << endl;
	}
	return 0;
}
