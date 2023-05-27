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
        while(p!=NULL){         /*找到返回1*/
            if(p->data==x) return 1;
            if(x>p->data) p=p->rchild;
            else p=p->lchild;
        }
    }
    return 0;                   /*是空树或者没找到时返回0*/
}
 /*二叉排序树的插入*/
int insert(node **root,int x)       /*双指针*/
{
    node *current,*parent=NULL,*s;
    current=*root;
    while(current!=NULL)            /*当不是空树时，查找x应该插入的位置*/
    {
        if(current->data==x) return 0;
        parent=current;             /*parent记录x应该插入的位置的根节点*/
        if(current->data<x) current=current->rchild;
        else current=current->lchild;
    }
    s=(node*)malloc(sizeof(node));  /*把s放在while循环后面，当有重复数据时，可以少创建一个节点*/
    s->data=x;s->lchild=NULL;s->rchild=NULL;
    if(parent==NULL) *root=s;
    else if(x<parent->data) parent->lchild=s;
    else parent->rchild=s;
    return 1;
}
/*二叉排序树的遍历*/
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
    while(n != -1){ a[i]=n;i++;scanf("%d",&n);} k=i; /*将用户输入的数据存到a[]数组*/
    node *root=NULL;                                /*为什么用双指针*/
    for(k=0; k<i; k++)
    { insert(&root,a[k]);}                          /*用插入的方法创建二叉有序树*/
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
