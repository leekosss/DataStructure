#include<stdio.h>
#include<stdlib.h>
typedef struct k
{
    int data;
    struct k *left,*right;
}btree;
btree* insertX(btree *t,int x)  // 在二叉排序树插入x
{
    btree *q,*p,*pre;
    q=(btree *)malloc(sizeof(btree));
    q->left=NULL;
    q->right=NULL;
    q->data=x;
    if(t==NULL)
    {
        q->left=NULL;
        q->right=NULL;
        return q;
    }
    p=t;
    while(p!=NULL)
    {
        pre=p;
        if(x>p->data)
            p=p->right;
        else
            p=p->left;
    }
    if(x<=pre->data)
        pre->left=q;
    else
        pre->right=q;
    
    return t;
}

btree* insertXDG(btree *t,int x)  //递归二叉排序树插入x
{
    btree *p;
    p=(btree*)malloc(sizeof(btree));
    if(t==NULL)
    {
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    if(x<=t->data)
    {
        t->left=insertX(t->left,x);
    }
    else 
        t->right=insertX(t->right,x);
    return t;
}
btree* createBSF(btree *t,int x)  //基于插入操作建树
{   
    btree *p;
    p=(btree*)malloc(sizeof(btree));
    if(t==NULL)
    {
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    if(x<=t->data)
        t->left=createBSF(t->left,x);
    else
        t->right=createBSF(t->right,x);
    return t;
}

btree* findX(btree *t,int x) //二叉排序树查找x
{
    if(t==NULL)
        return NULL;
    if(t->data==x)
        return t;
    if(x<=t->data)
        return findX(t->left,x);
    else
        return findX(t->right,x);
}
btree* maxNum(btree *t)
{
    if(t==NULL)
        return NULL;
    btree* max;
    btree *p;
    p=t;
    while(p!=NULL)
    {
        max=p;
        p=p->right;
    }
    return max;
}
btree* minNum(btree *t)
{
    if(t==NULL)
        return NULL;
    btree *p;
    btree* min;
    p=t;
    while(p!=NULL)
    {
        min=p;
        p=p->left;
    }
    return min;
}
int isBST(btree *t)  //判断t是否为二叉排序树
{
    if(t==NULL)
        return 1;
    btree *ma,*mi;
    ma=maxNum(t->left);
    mi=minNum(t->right);
    if((t->left!=NULL&&ma->data>t->data)||(t->right!=NULL&&mi->data<t->data))
        return 0;
    if(isBST(t->left))
        return isBST(t->right);
    else
        return 0;
}
void del_1_node(btree* t,btree *c)  //删除一度结点
{
    btree *pre,*p;
    p=t;
    while(p!=NULL&&p!=c)
    {
        pre=p;
        if(c->data<=p->data)
            p=p->left;
        else
            p=p->right;
    }  // 指针p找到结点c
    if(p!=NULL)
    {
        if(p->data<=pre->data)
        {
            if(p->left!=NULL)
                pre->left=p->left;
            else
                pre->left=p->right;
        }
        else
        {
            if(p->left!=NULL)
                pre->right=p->left;
            else
                pre->right=p->right;
        }
    }

}

void mid(btree *t)  //中序遍历
{
    if(t==NULL)
        return;
    mid(t->left);
    printf("%d ",t->data);
    mid(t->right);
}
int main()
{
    btree *t=NULL;
    int i;
    int a[]={1,4,7,2,5,8,0,-5,3};
    for(i=0;i<9;i++)
    {
        t=createBSF(t,a[i]);
    }
    mid(t);
    printf("\n");
    t=insertX(t,-3);
    mid(t);
    printf("\n");
    btree* x;
    x=findX(t,4);
    if(x!=NULL)
    {
        printf("\n找到了！");
    }
    else
        printf("\nNULL!");

    del_1_node(t,t->right->left);
    mid(t);
    return 0;
}