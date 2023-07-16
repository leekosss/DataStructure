#include<stdio.h>           
#include<stdlib.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
typedef struct k
{
    char data;
    struct k *left,*right;
}btree;
int findGen(char in[],int low2,int high2,char x)  //找根所在的下标
{
    int i;
    for(i=low2;i<=high2;i++)
        if(in[i]==x)
            return i;
    return -1;
}
btree* creat(char pre[],int low1,int high1,char in[],int low2,int high2)    
{    //给定前序中序遍历，编写函数创建二叉树 
    btree *t;
    if(low1>high1)
        return NULL;
    t=(btree*)malloc(sizeof(btree));
    t->data=pre[low1];
    int i,j;
    i=findGen(in,low2,high2,t->data);
    j=low1+i-low2;   //根据中序根划分前序的左右子树
    t->left=creat(pre,low1+1,j,in,low2,i-1);
    t->right=creat(pre,j+1,high1,in,i+1,high2);
    return t;
} 
void pre(btree *t)   //前序遍历
{
    if(t==NULL)
        return;
    printf("%c",t->data);
    pre(t->left);
    pre(t->right);
}
void mid(btree *t)  //中序遍历
{
    if(t==NULL)
        return;
    mid(t->left);
    printf("%c",t->data);
    mid(t->right);
}
int main()
{
    char myPre[]={'A','B','D','C','E','F'};
    char myIn[]={'D','B','A','C','F','E'};
    printf("前序:ABDCEF\n");
    printf("中序:DBACFE\n");
    printf("-------------\n");
    btree *t;
    t=creat(myPre,0,5,myIn,0,5);
    printf("前序:");
    pre(t);
    printf("\n");
    printf("中序:");
    mid(t);
    return 0;
}