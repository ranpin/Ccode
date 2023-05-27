#include<iostream>
using namespace std;

const int maxn = 50;
int n;
int a[maxn][maxn];

//len��ʾ����ı߳���Ҳ����һ��������� , k��ʾ��ǰ�ǵڼ������� 
void f(int s, int e, int len, int k)			//��i---j����������װ����ά������ 
{
	//�ݹ�߽� 
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
	
	//�����ϱ߿� 
	int col = n + 1 - k;			//��ʾ�ұ߿���кź��±߿���к� 
	int x = s;
	for(int j = k;j <= col;j++)		//����ѭ������֮ǰ����д��j <= len�ˣ����´��� 
	{
		a[k][j] = x;
		x++;
	} 
	//�����ұ߿�
	for(int i = k + 1;i <= col;i++)
	{
		a[i][col] = x;
		x++;
	} 
	//�����±߿�
	for(int j = col - 1;j >= k;j--) 
	{
		a[col][j] = x;
		x++;
	}
	//������߿�
	for(int i = col - 1;i >= k + 1;i--)
	{
		a[i][k] = x;
		x++;
	}
	f(x, n * n, len - 2, k + 1);		//�ݹ飬���С��������
}

int main()
{
	cin >> n;
	f(1, n * n, n, 1);			//��k = 1��ʼ����һ������ 
	//print a
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			printf("%5d", a[i][j]);			//����Ҷ���
		}
		cout << endl;
	}
	return 0;
}
