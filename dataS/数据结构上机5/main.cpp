#include <iostream>
#include<stdio.h> 

#define MaxSize 100

typedef struct{		//定义三元组，存放一个非0元素 
	int r;
	int c;
	int d;
}TupNode;

typedef struct{		//定义三元组顺序表，存放整个稀疏矩阵 
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;

void CreatMat(TSMatrix &t,int a[M][N]){		//创建三元组顺序表 
	int i,j;
	t.rows=M; t.cols=N; t.nums=0;
	for(i=0;i<M;i++){		//按行序扫描所有元素 
		for(j=0;j<N;j++){
			
			if(a[i][j]!=0){		//存储非0元素 
				t.data[t.nums].r=i;
				t.data[t.nums].c=j;
				t.data[t.nums].r=a[i][j];
				t.nums++;	 
			}
			
		}
	}
} 

void DispMat(TSMatrix t){	//从头扫描三元组，依次输出各元素值 
	int i;
	if(t.nums<=0)
		return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("-----------------------------\n");
	for(i=0;i<t.nums;i++){
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
	}
} 

void TranMat(TSMatrix t,TSMatrix &tb) {		//转置三元组顺序表 
	int p,q=0;
	int v;
	tb.rows=t.cols; tb.cols=t.rows; t.nums=t.nums;
	if(t.nums!=0){
		for(v=0;v<t.cols;v++){		//tb.data[q]中记录以列序排列 
			for(p=0;p<t.nums;p++){	//p为t.data的下标 
				if(t.data[p].c==v){
					tb.data[q].r=t.data[q].c;
					tb.data[q].c=t.data[q].r;
					tb.data[q].d=t.data[q].d;
					q++;
				}
			}
		}
	}
}

bool MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c){		//三元组相加 
    int i,j;    
	ElemType va,vb,vc;    
	if (a.rows!=b.rows || a.cols!=b.cols)        
		return false;                        //行数或列数不等时不能进行相加运算    
	c.rows=a.rows;    
	c.cols=a.cols;       //c的行列数与a的相同    
	c.nums=0;    
	for(i=0; i<M; i++)        
		for(j=0; j<N; j++){            
			Assign(a,va,i,j);            
			Assign(b,vb,i,j);            
			vc=va+vb;            
			if(vc)                
				Value(c,vc,i,j);       
		}    
	return true;
}


bool Value(TSMatrix &t,ElemType x,int i,int j)  //三元组元素赋值
{   int k=0,k1;
    if (i>=t.rows || j>=t.cols)
	        return false;   //失败时返回false
	while (k<t.nums && i>t.data[k].r)
		k++;                  //查找行
	while (k<t.nums && i==t.data[k].r && j>t.data[k].c)
		k++;		//查找列
	if (t.data[k].r==i && t.data[k].c==j)   //存在这样的元素
		t.data[k].d=x;
	else                                    //不存在这样的元素时插入一个元素
	{   
		for (k1=t.nums-1; k1>=k; k1--){            
			t.data[k1+1].r=t.data[k1].r;
			t.data[k1+1].c=t.data[k1].c;
			t.data[k1+1].d=t.data[k1].d;
			}
			t.data[k].r=i;
			t.data[k].c=j;
			t.data[k].d=x;
			t.nums++;
			}
				return true;                  //成功时返回true
}


int main(int argc, char** argv) {
	int A[] = { 0 0 0 0 0
				1 1 1 1 1  
				2 2 2 2 2  
				3 3 3 3 3 
				4 4 4 4 4 

				};
	int B[] = {
				4 4 4 4 4
				3 3 3 3 3
				2 2 2 2 2
				1 1 1 1 1
				0 0 0 0 0
			};
	
	return 0;
}
