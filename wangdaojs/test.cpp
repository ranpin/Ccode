//1239：统计数字
#include<iostream>
using namespace std;
int a[2000],tmp[2000],i,j,n;
void msort(int l,int r) //归并排序 
{
	int mid;
	if(l==r) return;
	mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
			tmp[k++]=a[i++];
		else
		{
			tmp[k++]=a[j++];
		}
	}
	while(i<=mid)
		tmp[k++]=a[i++];
	while(j<=r)
		tmp[k++]=a[j++];
	for(i=l;i<=r;i++)
		a[i]=tmp[i];
	return;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	msort(1,n);
	int k=-1,count=0;//k表示前面出现的自然数，count统计自然数出现的次数 
	for(i=1;i<=n;i++)
	{
		if(a[i]!=k)//遇到新的自然数
		{
			if(i>1)//遇到的不是第一次出现的自然数，输出前面的自然数 
			{
				cout<<"("<<k<<","<<count<<")"<<",";
			}
			k=a[i];//k记录新出现的自然数的值 
			count=1; //count记录新出现的自然数出现的次数，初始化为1

		}
		else//即a[i]=k的情况 
		{
			count++;
		} 
	}
	cout<<"("<<k<<","<<count<<")"<<endl;//输出最后一个自然数出现的次数 
    system ("pause");
    return 0;
}


