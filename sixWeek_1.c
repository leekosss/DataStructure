#include<stdio.h>
typedef struct{    //定义顺序表
    int a[100];
    int length;
}seqList;
void creatList(seqList *L)   //创建顺序表
{
    int x,i=0;
    printf("请输入顺序表的数据:(以-1结束)\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        L->a[i]=x;
        i++;
        scanf("%d",&x);
    }
    L->length=i;
}
void inputList(seqList *L)    //输出顺序表
{
    printf("顺序表内容为：\n");
    int i=0;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->a[i]);
    }
    printf("\n");
}
void ouji(seqList *L)   //排序：偶数在前，奇数在后
{
    int i=0,j=L->length-1,temp;
    while(i<j)
    {
        while(i<j && L->a[i]%2==0)   //i<j 是因为，怕顺序表中全为偶数，导致数组越界产生错误
        {
            i++;
        }
        while(i<j && L->a[j]%2==1)   //防止全是奇数
        {
            j--;
        }
        if(i<j)
        {
            temp=L->a[i];
            L->a[i]=L->a[j];
            L->a[j]=temp;
        }
        i++;
        j--;
    }
}
void delOdd(seqList *L)  //删除表中所有奇数
{
    int i=0,j=0;
    while(i<L->length)
    {
        if(L->a[i]%2==1)
        {
            i++;
        }
        else
        {
            L->a[j]=L->a[i];
            i++;
            j++;
        }
    }
    L->length=j;
}
void insertSorted(seqList *L,int x)   //升序表插入
{
    int i=0,j;
    while(i<L->length&&x>L->a[i])
    {
        i++;
    }
    for(j=L->length-1;j>=i;j--)
    {
        L->a[j+1]=L->a[j];
    }
    L->a[i]=x;
    L->length++;
    

}
void addList(seqList *L1,seqList *L2,seqList *L3)    //将升序表L1，L2合并成降序表L3
{
    int i=L1->length-1,j=L2->length-1;
    L3->length=0;
    while(i>=0&&j>=0)
    {
        if(L1->a[i]>L2->a[j])
        {
            L3->a[L3->length]=L1->a[i];
            i--;
            L3->length++;
        }
        else 
        {
            L3->a[L3->length]=L2->a[j];
            j--;
            L3->length++;
        }
    }
    while(i>=0)
    {
        L3->a[L3->length]=L1->a[i];
        i--;
        L3->length++;
    }
    while(j>=0)
    {
        L3->a[L3->length]=L2->a[j];
        j--;
        L3->length++;
    }
    //将L1，L2的值放到L3中
}
int main()
{
    seqList L;
    creatList(&L);
    delOdd(&L);
    inputList(&L);
    int x;
    printf("请输入x：\n");
    scanf("%d",&x);
    insertSorted(&L,x);
    inputList(&L);
    seqList L2,L3;
    creatList(&L2);
    addList(&L,&L2,&L3);
    inputList(&L3);
    return 0;
}