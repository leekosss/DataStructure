#include<stdio.h>  //稀疏矩阵的普通转置
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
void transpose(SYZ *ma,SYZ *mb) //稀疏矩阵的普通转置
{
    if(ma[0].v==0)  //如果原矩阵无元素，则直接返回
        return;
    mb[0].i=ma[0].j;
    mb[0].j=ma[0].i;
    mb[0].v=ma[0].v;
    int col,k,p;
    for(col=1,k=1;col<=ma[0].j;col++) //遍历ma矩阵的列数
    {   // col为列数，k为mb矩阵三元组元素的下标
        for(p=1;p<=ma[0].v;p++)  //p为ma矩阵三元组元素的下标
        {   // 遍历三元组ma中列，如果ma三元组存在列数与col相等，说明三元组中有这一列的元素，将其赋值到mb中
            if(ma[p].j==col)
            {
                mb[k].i=ma[p].j;
                mb[k].j=ma[p].i;
                mb[k].v=ma[p].v;
                k++;   //赋值完将下标k往后移一位
            }
        }
    }
}
int main()
{
    SYZ ma[100],mb[100];
    input(ma);
    output(ma);
    transpose(ma,mb);
    output(mb);
    return 0;
}