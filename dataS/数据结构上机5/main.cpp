#include <iostream>
#include<stdio.h> 

#define MaxSize 100

typedef struct{		//������Ԫ�飬���һ����0Ԫ�� 
	int r;
	int c;
	int d;
}TupNode;

typedef struct{		//������Ԫ��˳����������ϡ����� 
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;

void CreatMat(TSMatrix &t,int a[M][N]){		//������Ԫ��˳��� 
	int i,j;
	t.rows=M; t.cols=N; t.nums=0;
	for(i=0;i<M;i++){		//������ɨ������Ԫ�� 
		for(j=0;j<N;j++){
			
			if(a[i][j]!=0){		//�洢��0Ԫ�� 
				t.data[t.nums].r=i;
				t.data[t.nums].c=j;
				t.data[t.nums].r=a[i][j];
				t.nums++;	 
			}
			
		}
	}
} 

void DispMat(TSMatrix t){	//��ͷɨ����Ԫ�飬���������Ԫ��ֵ 
	int i;
	if(t.nums<=0)
		return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("-----------------------------\n");
	for(i=0;i<t.nums;i++){
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
	}
} 

void TranMat(TSMatrix t,TSMatrix &tb) {		//ת����Ԫ��˳��� 
	int p,q=0;
	int v;
	tb.rows=t.cols; tb.cols=t.rows; t.nums=t.nums;
	if(t.nums!=0){
		for(v=0;v<t.cols;v++){		//tb.data[q]�м�¼���������� 
			for(p=0;p<t.nums;p++){	//pΪt.data���±� 
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

bool MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c){		//��Ԫ����� 
    int i,j;    
	ElemType va,vb,vc;    
	if (a.rows!=b.rows || a.cols!=b.cols)        
		return false;                        //��������������ʱ���ܽ����������    
	c.rows=a.rows;    
	c.cols=a.cols;       //c����������a����ͬ    
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


bool Value(TSMatrix &t,ElemType x,int i,int j)  //��Ԫ��Ԫ�ظ�ֵ
{   int k=0,k1;
    if (i>=t.rows || j>=t.cols)
	        return false;   //ʧ��ʱ����false
	while (k<t.nums && i>t.data[k].r)
		k++;                  //������
	while (k<t.nums && i==t.data[k].r && j>t.data[k].c)
		k++;		//������
	if (t.data[k].r==i && t.data[k].c==j)   //����������Ԫ��
		t.data[k].d=x;
	else                                    //������������Ԫ��ʱ����һ��Ԫ��
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
				return true;                  //�ɹ�ʱ����true
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
