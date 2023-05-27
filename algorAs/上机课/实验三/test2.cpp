#include <iostream>
#include <stdlib.h>
#include <stdio.h>
void shuchushudu(int chess[9][9]) {
	// TODO Auto-generated method stub
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
			{
			printf("%d  ",chess[i][j]);
			}
			printf(" \n");
		}
}
bool isValid(int chess[9][9], int i, int j) {

		// TODO Auto-generated method stub
		bool flag=true;
		int data=chess[i][j];
		for(int k=0;k<9;k++)
		{
			//i行相等
			if( (k!=j) && (chess[i][k]==data))
			{
			  return false;
			}
			//j列相等
			if( (k!=i) && (chess[k][j]==data))
			{
				return false;
			}
		}

		//九宫相等
		int iGrid=(i/3)*3;
		int jGrid=(j/3)*3;
		for(int k2=iGrid;k2<iGrid+3;k2++)
		{
			for(int k3=jGrid;k3<jGrid+3;k3++)
			{
				if((i==k2) && (j==k3))
				{
					continue;
				}
				if(chess[k2][k3]==data)
				{
					return false;
				}
			}
		}
		return true;
	}
	
bool sudoku(int chess[9][9]) {
		// TODO Auto-generated method stub
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				       //过滤掉不为0的情况
				   if(chess[i][j] != 0)
				  	continue;
						for(int d=1;d<=9;d++)
						{
							chess[i][j]=d;
							if(isValid(chess,i,j) && sudoku(chess) )
							{
								return true;
							}
							chess[i][j]=0;
						}
						return false;
			}
		}
		shuchushudu(chess);
		return true;
	}

int main() {

		// TODO Auto-generated method stub

		int chess[9][9] = { 

				{0,0,5,3,0,0,0,0,0},

				{8,0,0,0,0,0,0,2,0},

				{0,7,0,0,1,0,5,0,0},

				{4,0,0,0,0,5,3,0,0},

				{0,1,0,0,7,0,0,0,6},

				{0,0,3,2,0,0,0,8,0},

				{0,6,0,5,0,0,0,0,9},

				{0,0,4,0,0,0,0,3,0},

				{0,0,0,0,0,9,7,0,0}

				} ;
		sudoku(chess);
    return 0;
}

