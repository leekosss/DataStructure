#include <stdio.h>   //递归实现找最大最小值
typedef struct
{ //定义顺序表
    int a[100];
    int length;
} seqList;
void creatList(seqList *L) //创建顺序表
{
    int x, i = 0;
    printf("请输入顺序表的数据:(以-1结束)\n");
    scanf("%d", &x);
    while (x != -1)
    {
        L->a[i] = x;
        i++;
        scanf("%d", &x);
    }
    L->length = i;
}
int max(seqList *L, int low, int high)
{
    if (low > high)
        return -1;    //没有元素则返回-1
    //只有一个元素则返回该下标（防止数组越界）
    int k;
    k = max(L, low + 1, high);
    if (k==-1||L->a[low] >= L->a[k]) //如果a[low]>数组中剩余元素的最大值，返回下标 low
        return low;  //k==-1（防止数组越界）
    else
        return k;    // 否则返回剩余元素中最大值的下标
}
int min(seqList *L, int low, int high)
{
    if (low > high)
        return -1;
    int k;
    k = min(L, low + 1, high);
    if (k==-1||L->a[low] <= L->a[k])
        return low;
    else
        return k;
}
int main()
{
    seqList L;
    creatList(&L);
    printf("最大值的下标为：%d\n", max(&L, 0, L.length - 1));
    printf("最小值的下标为：%d\n", min(&L, 0, L.length - 1));
    return 0;
}
