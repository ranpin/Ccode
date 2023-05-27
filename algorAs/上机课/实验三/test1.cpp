#include<iostream>
#include<queue>
using namespace std;

class Oil
{
public:
	int x;
	int y;
	int z;

public:
	Oil(){}
	Oil(int a,int b,int c):x(a),y(b),z(c){}
	~Oil(){}
};

class Node
{
public:
   Oil *o;
   int n;  //父节点位置

public:
	Node(){}
	Node(Oil *s_o,int c):o(s_o),n(c){}
	~Node(){}
};
 

bool isCir(Node *node,int cnt,Node arr[1000])
{
	for(int n=0;n<cnt;n++)
	{
		if(node->o->x==arr[n].o->x && node->o->y==arr[n].o->y && node->o->z==arr[n].o->z)
			return true;
	}
	return false;

}
int main()
{
	Oil *root = new Oil(10,0,0);
	Node arr[50];
	Node result[20];
	queue<Node *> oilQueue;
	Node *rootNode=new Node(root,-1); 
	oilQueue.push(rootNode);
	Oil * oil=new Oil();
	int cnt=0;//数组元素个数
	int t=0;//队列中记录的父节点
    int res=0;//记录最终结果的位置
	int r=0;//记录结果数组个数
	arr[0].o=root;
    arr[0].n=-1;
	//建立队列，进行广度优先遍历
	while(!oilQueue.empty())
	{
		Oil *newOil = new Oil();
		Node *newNode=new Node();
		oil = oilQueue.front()->o;
		if(!isCir(oilQueue.front(),cnt,arr))
		{
		   arr[cnt].o=oilQueue.front()->o;
           arr[cnt].n=oilQueue.front()->n;
		   cnt++;
		   t=cnt-1;
		}
		oilQueue.pop();	
		//7两瓶不满时装满
		if(oil->y<7)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->y=7;
			newOil->x=10-7-oil->z;
			newOil->z=oil->z;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			   oilQueue.push(newNode);
		}	
		//3两瓶不满时装满
		if(oil->z<3)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->z=3;
			newOil->x=10-3-oil->y;
			newOil->y=oil->y;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			   oilQueue.push(newNode);
		}
		//7两瓶不空时倒空
		if(oil->y>0)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->y=0;
			newOil->x=10-oil->z;
			newOil->z=oil->z;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			   oilQueue.push(newNode);
		}
		//3两瓶不空时倒空
		if(oil->z>0)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->z=0;
			newOil->x=10-oil->y;
			newOil->y=oil->y;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			   oilQueue.push(newNode);
		}
		//7两瓶中的油全倒入3两瓶
		if(oil->y>0 && oil->y+oil->z<=3)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->y=0;
			newOil->z=oil->y+oil->z;
			newOil->x=10-oil->y-oil->z;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			  oilQueue.push(newNode);
		}
		//3两瓶中的油全倒入7两瓶
		if(oil->z>0 && oil->y+oil->z<=7)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->z=0;
			newOil->y=oil->y+oil->z;
			newOil->x=10-oil->y-oil->z;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			   oilQueue.push(newNode);
		}
		//用3两瓶中的油装满7两瓶
		if(oil->y<7 && oil->y+oil->z>=7)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->y=7;
			newOil->z=oil->y+oil->z-7;
			newOil->x=10-oil->y-oil->z;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			   oilQueue.push(newNode);
		}
		//用7两瓶中的油装满3两
		if(oil->z<3 && oil->y+oil->z>=3)
		{
			newOil = new Oil();
			newNode = new Node();
			newOil->z=3;
			newOil->y=oil->y+oil->z-3;
			newOil->x=10-oil->y-oil->z;
			newNode->o=newOil;
			newNode->n=t;
			if(!isCir(newNode,cnt,arr))
			oilQueue.push(newNode);
		}
	}
	for(int q=0;q<cnt;q++)
	{
		if(arr[q].o->x==5)
		{
            res=q;
			break;
		}
	}
	while(arr[res].n!=-1){
		result[r]=arr[res];
		res=arr[res].n;
		r++;
	}
	if(arr[res].n==-1)
	{
		result[r]=arr[res];
		res=arr[res].n;
	}
	for(int p=r;p>=0;p--)
	{
       cout<<"<"<<result[p].o->x<<","<<result[p].o->y<<","<<result[p].o->z<<">"<<endl;
	}
	return 0;	
}

