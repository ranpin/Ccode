#include<stdio.h>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    printf("栈顶元素：%d\n",st.top());
    printf("出栈顺序：");
    while(!st.empty()){     //栈不为空时输出所有元素
        printf("%d ",st.top());
        printf("lll");
        st.pop();
    }
    printf("\n");
}
