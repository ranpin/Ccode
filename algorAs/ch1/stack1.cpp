#include<stdio.h>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    printf("ջ��Ԫ�أ�%d\n",st.top());
    printf("��ջ˳��");
    while(!st.empty()){     //ջ��Ϊ��ʱ�������Ԫ��
        printf("%d ",st.top());
        printf("lll");
        st.pop();
    }
    printf("\n");
}
