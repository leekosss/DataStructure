#include<stdio.h>  //稀疏矩阵的快速转置
typedef struct
{
    int i,j,v;
}SYZ;
void input(SYZ *ma)    //输入三元组，实现稀疏矩阵的输入
{
    int k;
    printf("请输入稀疏矩阵的行数、列数、非零元素个数：\n");
    scanf("%d%d%d",&ma[0].i,&ma[0].j,&ma[0].v);
    printf("请输入元素所在的行数、列数、值：\n");
    for(k=1;k<=ma[0].v;k++)
    {
        scanf("%d%d%d",&ma[k].i,&ma[k].j,&ma[k].v);
    }
}
void output(SYZ *m)   //以矩阵的方式输出稀疏矩阵
{
    int i,j,k=1;   //i 行数  j 列数 k  输出三元组中元素所处下标
    printf("稀疏矩阵如下：\n");
    for(i=1;i<=m[0].i;i++)
    {
        for(j=1;j<=m[0].j;j++)
        {
            if(i==m[k].i&&j==m[k].j)   //是三元组元素就输出
            {
                printf("%-3d ",m[k].v);
                k++;
            }
            else 
            {
                printf("%-3d ",0);   //不是就输出0
            }
            if(j==m[0].j)    //到一行末尾就换行
                printf("\n");
        }
    }
}
void fillNum(SYZ *m,int num[])  //计算稀疏矩阵每一列的个数
{
    int i;
    for(i=1;i<=m[0].v;i++)
    {
        int k;
        k=m[i].j;
        num[k]++;
    }
}
void fillPos(SYZ *m,int pos[],int num[])  //计算某一列在新三元组的起始地址
{
    int k=2;
    pos[1]=1;
    for(int i=1;i<=m[0].j;i++,k++)
    {
        pos[k]=pos[k-1]+num[k-1];
    }
}
void fastTranspose(SYZ *ma,SYZ *mb)  //稀疏矩阵快速转置
{
    if(ma[0].v==0)  //如果原矩阵无元素，则直接返回
        return;
    mb[0].i=ma[0].j;
    mb[0].j=ma[0].i;
    mb[0].v=ma[0].v;
    int num[50]={0},pos[50]={0};
    fillNum(ma,num);
    fillPos(ma,pos,num);
    int col,k;
    for(col=1;col<=ma[0].v;col++)  //遍历原三元组
    {   
        k=ma[col].j;  //得到原三元组某一行元素的列数
        mb[pos[k]].i=ma[col].j;  //将原三元组col行元素赋值到新三元组pos[k]行位置
        mb[pos[k]].j=ma[col].i;
        mb[pos[k]].v=ma[col].v;
        pos[k]++;
    }
}

int main()
{
    SYZ ma[100],mb[100];
    input(ma);
    output(ma);
    fastTranspose(ma,mb);
    output(mb);
    return 0;
}