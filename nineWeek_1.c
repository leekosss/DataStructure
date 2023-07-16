#include<stdio.h>   //通过输入相关三元组，实现稀疏矩阵的输入
typedef struct
{
    int i,j,v;
}SYZ;   //定义三元组
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
void output(SYZ *ma)   //三元组输出
{
    printf("三元组值为：\n");
    int k;
    for(k=1;k<=ma[0].v;k++)
    {
        printf("%d %d %d\n",ma[k].i,ma[k].j,ma[k].v);
    }
}
int main()
{
    SYZ ma[100];
    input(ma);
    output(ma);
    return 0;
}