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
        L->length=i;
        scanf("%d",&x);
    }
}
void inputList(seqList *L)    //输出顺序表
{
    printf("输出顺序表\n");
    int i=0;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->a[i]);
    }
    printf("\n");
}
int search(seqList *L)     //查找指定元素
{
    int i;
    int x;
    printf("请输入要查找的元素：");
    scanf("%d",&x);
    for(i=0;i<L->length;i++)
    {
        if(L->a[i]==x)
        {
            return i;
        }
    }
    return -1;
}
void insert(seqList *L)   //插入元素到指定位置
{
    int i;
    int m,x;
    printf("请输入插入的位置和值：\n");
    scanf("%d%d",&m,&x);
    if(m<0||m>L->length)
    {
        printf("error position!\n");
        return;
    }
    for(i=L->length-1;i>=m;i--)
    {
        L->a[i+1]=L->a[i];
    }
    L->a[m]=x;
    L->length++;
    
}
void dele(seqList *L)     //删除指定位置的元素
{
    int i;
    int m;
    printf("请输入删除的位置：\n");
    scanf("%d",&m);
    if(m<0||m>=L->length)
    {
        printf("error position\n");
        return;
    }
    for(i=m+1;i<L->length;i++)
    {
        L->a[i-1]=L->a[i];
    }
    L->length--;
}
void selectSort(seqList *L)    //选择排序
{
    printf("选择排序：\n");
    int temp,i,j,min;
    for(i=0;i<L->length-1;i++)
    {
        min=i;
        for(j=i+1;j<L->length;j++)
        {
            if(L->a[min]>L->a[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=L->a[i];
            L->a[i]=L->a[min];
            L->a[min]=temp;
        }
    }
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
void deleteFourPlus(seqList *L)     //删除顺序表中大于4的数
{
    int i=0,j=0;
    while(i<L->length)  //快速删除
    {
        if(L->a[i]>4)
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
    // selectSort(&L);
    // inputList(&L);
    // printf("查找元素的下标为：%d\n",search(&L));
    // insert(&L);
    // inputList(&L);
    // dele(&L);
    // inputList(&L);
    // selectSort(&L);
    // inputList(&L);
    printf("偶数在前，奇数在后:\n");
    ouji(&L);
    inputList(&L);
    // selectSort(&L);
    // printf("删除顺序表中大于4的数\n");
    // deleteFourPlus(&L);
    // inputList(&L);
    // seqList L2,L3; 
    // creatList(&L2);   //创建升序表 L2
    // selectSort(&L2);
    // addList(&L,&L2,&L3);   // 将升序表L1,L2 合并成降序表L3
    // inputList(&L3);
    return 0;
}