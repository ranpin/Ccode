#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;	
int n; 				  //�ʺ���� 
bool place(int k, int i, int *x);
void nQueens(int k, int n, int *x);

int main()
{
	cout << "������n-�ʺ���n��ֵ:";
	while(cin >> n)
	{
	   int *x = new int [n + 1];
	   cout << "������н�:" <<endl; 
	   if(n == 2 || n==3)
	   cout << "0" <<endl;
	   nQueens(0, n, x); 
	   cout << "������n-�ʺ���n��ֵ:";
    }
	return 0;
}
 
bool place(int k, int i, int *x)
{  //�ж������ʺ��Ƿ���ͬһ�л�����ͬһб���� 
   for(int j = 0; j < k; j++)
      if((x[j] == i) || abs(x[j] - i) == abs(j - k))  return false;
    return true;
}
 
void nQueens(int k, int n, int *x)
{
	for(int i = 0; i < n; i++)
	{
		if(place(k, i, x))
		{
		   x[k] = i;
		   if(k == n - 1)
		   {
		   	  for(i = 0; i < n; i++)  cout << x[i] << " ";
		   	  cout << endl;
		   }	
		   else
		      nQueens(k+1, n, x);
		} 
	} 
}
