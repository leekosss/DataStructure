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
void sort(seqList *L,int low,int high)  //奇数在前，偶数在后
{
    if(low>high)
        return;
    if(L->a[low]%2==1&&L->a[high]%2==0)  //low为奇数，high为偶数，不用管
        sort(L,low+1,high-1);
    else if(L->a[low]%2==1&&L->a[high]%2==1)  //low为奇数，high为奇数，low不用变，往后移一位
        sort(L,low+1,high);
    else if(L->a[low]%2==0&&L->a[high]%2==0)  //low为偶数，high为偶数，high往前移一位  
        sort(L,low,high-1);
    else if(L->a[low]%2==0&&L->a[high]%2==1)  //low为偶数，high为奇数，将两个数交换
    {
        int temp;     
        temp=L->a[low];
        L->a[low]=L->a[high];
        L->a[high]=temp;
        sort(L,low+1,high-1);
    }
}
int main()
{
    seqList L;
    creatList(&L);
    sort(&L,0,L.length-1);
    inputList(&L);
    return 0;
}