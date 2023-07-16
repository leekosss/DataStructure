#include<stdio.h>  //根据三元组表，以矩阵方式输出稀疏矩阵
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
        scanf("%d%d%d",&ma[k].i,&ma[k].j,&ma[k].v);   //将数据存到三元组表
    }
}
void output(SYZ *ma)   //以矩阵的方式输出稀疏矩阵
{
    int i,j,k=1;   //i 行数  j 列数 k  输出三元组中元素所处下标
    printf("稀疏矩阵如下：\n");
    for(i=1;i<=ma[0].i;i++)
    {
        for(j=1;j<=ma[0].j;j++)
        {
            if(i==ma[k].i&&j==ma[k].j)   //是三元组元素就输出
            {
                printf("%-3d ",ma[k].v);
                k++;
            }
            else 
            {
                printf("%-3d ",0);   //不是就输出0
            }
            if(j==ma[0].j)    //到一行末尾就换行
                printf("\n");
        }
    }
}
int main()
{
    SYZ ma[100];
    input(ma);
    output(ma);
    return 0;
}