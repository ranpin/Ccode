#include<stdio.h>
#include<set>
using namespace std;
set<int>s;
void fun(int n){
    for(int i=2;i<=10;i++){
        int r=n%i;
        s.insert(r);
    }
}
int main(){
    for(int i=0;i<=5000;i++){
        fun(i);
        if(s.size()==9){
            printf("%d\n",i);
            break;
        }
        else s.clear();
    }
	return 0;
}
