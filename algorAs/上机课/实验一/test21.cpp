
#include<iostream>

 

using namespace std;

 

int main()

{

	int n,i,j,m,k;

	int a[100][100]={0};

	cout<<"please input n:";

	cin>>n;

	k=0;    //标记

	i=0,j=0;

	m=1;

	a[0][0]=m;

	while(m<n*n)

	{

		switch(k)

		{

		case 0:       //向右或向下

			if(i+j<n-1)

			{

				j++;

				m++;

				a[i][j]=m;

				k=(k+1)%4;

			}

			else

			{

				i++;

				m++;

				a[i][j]=m;

				k=(k+1)%4;

			}

			break;

		case 1:           //向左下

			while(i+1<n&&j-1>=0)

			{

				i++,j--;

				m++;

				a[i][j]=m;

			}

			k=(k+1)%4;

			break;

		case 2:       //向下或向右

			if(i+j<n-1)

			{

				i++;

				m++;

				a[i][j]=m;

				k=(k+1)%4;

			}

			else

			{

				j++;

				m++;

				a[i][j]=m;

				k=(k+1)%4;

			}

			break;

		case 3:        //向右上

			while(i-1>=0&&j+1<n)

			{

				i--,j++;

				m++;

				a[i][j]=m;

			}

			k=(k+1)%4;

			break;

		}

	}

	for(i=0;i<n;i++)

	{

		for(j=0;j<n;j++)

		{

			printf("%5d",a[i][j]);

		}

		cout<<endl;
 
	}
	return 0;
}
