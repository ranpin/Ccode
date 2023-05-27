#include<stdio.h>
#include<stdlib.h>

typedef struct node
{   int data;
    struct node *lchild;
    struct node *rchild;
}node;

int search(node *root,int x)
{   node *p;
    if(root!=NULL)
    {   p=root;
        while(p!=NULL){         /*�ҵ�����1*/
            if(p->data==x) return 1;
            if(x>p->data) p=p->rchild;
            else p=p->lchild;
        }
    }
    return 0;                   /*�ǿ�������û�ҵ�ʱ����0*/
}
 /*�����������Ĳ���*/
int insert(node **root,int x)       /*˫ָ��*/
{
    node *current,*parent=NULL,*s;
    current=*root;
    while(current!=NULL)            /*�����ǿ���ʱ������xӦ�ò����λ��*/
    {
        if(current->data==x) return 0;
        parent=current;             /*parent��¼xӦ�ò����λ�õĸ��ڵ�*/
        if(current->data<x) current=current->rchild;
        else current=current->lchild;
    }
    s=(node*)malloc(sizeof(node));  /*��s����whileѭ�����棬�����ظ�����ʱ�������ٴ���һ���ڵ�*/
    s->data=x;s->lchild=NULL;s->rchild=NULL;
    if(parent==NULL) *root=s;
    else if(x<parent->data) parent->lchild=s;
    else parent->rchild=s;
    return 1;
}
/*�����������ı���*/
void travel(node *root)
{
    if(root==NULL) return;
    if(root->lchild!=NULL) travel(root->lchild);
    printf("%d ",root->data);
    if(root->rchild!=NULL) travel(root->rchild);
}
int main()
{
    int a[8],i=0,k,n,x;
    scanf("%d",&n);
    while(n != -1){ a[i]=n;i++;scanf("%d",&n);} k=i; /*���û���������ݴ浽a[]����*/
    node *root=NULL;                                /*Ϊʲô��˫ָ��*/
    for(k=0; k<i; k++)
    { insert(&root,a[k]);}                          /*�ò���ķ�����������������*/
    	travel(root);
    	scanf("%d",&x);
    	int s=search(root,x);
    if(s==1)
    {
        printf("%d",x);
    }
    else printf("-1");
    return 0;
}
