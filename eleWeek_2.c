#include<stdio.h>
#include<stdlib.h>
#define m 3
typedef struct k
{
    int data;
    struct k* c[m];
}tree;  //定义树
tree* create()  //int 型数据的m度树
{
    int x,i;
    scanf("%d",&x);
    if(x==0)
        return NULL;
    tree *p;
    p=(tree*)malloc(sizeof(tree));
    p->data=x;
    for(i=0;i<m;i++)
        p->c[i]=create();
    return p;
}
void pre(tree *p)   //前序遍历
{
    if(p==NULL)
        return;
    printf("%d ",p->data);
    int i;
    for(i=0;i<m;i++)
        pre(p->c[i]);
}
int treeSum(tree *p)  //计算树中所有结点的累加和
{
    if(p==NULL)
        return 0;  //数为空则无结点
    int sum=0,i;
    sum+=p->data;   //结点数=根的值+所有子结点的值
    for(i=0;i<m;i++)
        sum+=treeSum(p->c[i]);
    return sum;
}
tree* merge(tree* a,tree* b)  //两棵树合并成一棵树
{
    if(a==NULL)  //树a为空返回树b
        return b;
    if(b==NULL)  //树b为空返回树a
        return a;
    tree *t;
    t=a;  //树a不为空，指针指向树a
    t->data=a->data+b->data;   //将a，b树的根的值相加
    int i;
    for(i=0;i<m;i++)
        t->c[i]=merge(a->c[i],b->c[i]);   //再把a，b子树的值对应相加
    return t;
    
}


int main()
{
    tree *p,*q;
    printf("请输入树中的结点,以0结束:\n"); //例如: 1 2 4 0 0 0 5 0 0 0 0 3 6 0 0 0 0 0 0 ==21
    p=create();
    // printf("%d\n",treeSum(p));
    tree *t;
    printf("请输入树中的结点,以0结束:\n"); 
    q=create();
    t=merge(p,q);
    pre(t);
    return 0;
}