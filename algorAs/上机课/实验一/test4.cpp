
#include<iostream>

#include<math.h>

using namespace std;

 

void Print(int a,int b,int n)    //��ӡ������a��b

{

	while(a<b){

		cout<<a<<"+";

		a++;

	}

	cout<<b<<"="<<n<<endl;

}

 

 

int main()

{

	int a,n;

	double b;

	cout<<"please input n:";

	cin>>n;

	for(a=1;a<=n/2;a++)

	{

		b=(-1.0+sqrt(1.0-4.0*(a-a*a-2.0*n)))/2.0; 

		if(b==int(b))     //�ж�b�Ƿ�Ϊ����

			Print(a,b,n);
	}
    renturn 0;
}
