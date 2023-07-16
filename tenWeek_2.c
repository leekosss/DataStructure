#include<stdio.h>   //在顺序表中查找x（递归）
typedef struct{    //定义顺序表
    int a[100];
    int length;
}seqList;
void creatList(seqList *L)   //创建顺序表
{
    int x,i=0;
    printf("Please input data:(end with -1)\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        L->a[i]=x;
        i++;
        scanf("%d",&x);
    }
    L->length=i;
}
int find_1(seqList *L,int x,int low,int high)  //首点+余部
{   
    if(low>high)  
        return -1;    //找不到返回-1
    if(L->a[low]==x)
        return low;     //找到返回low，否则返回余部
    // else
        return find_1(L,x,low+1,high);
}
int find_2(seqList *L,int x,int low,int high)  //前部+尾点
{
    if(low>high)
        return -1;
    if(L->a[high]==x)
        return high;
    // else
        return find_2(L,x,low,high-1);
}
int find_3(seqList *L,int x,int low,int high)  //中点+左部+右部
{   
    if(low>high)
        return -1;  //找不到返回-1
    int mid,left,right;
    mid=(low+high)/2;
    if(L->a[mid]==x)    //中点找到返回中点
        return mid;
    left=find_3(L,x,low,mid-1);
    if(left!=-1)
        return left;  //左边找到了就把左边返回
    else   //左边和中间都没找到，就返回右边
        return find_3(L,x,mid+1,high);
}
void output(int index)
{
    if(index == -1)
        printf("Not Found.\n");
    else
        printf("Found it.index is：%d\n",index);
}
int main()
{
    seqList L;
    creatList(&L);
    int x;
    printf("Please input the value you want to find:\n");
    scanf("%d",&x);
    int index;
    index=find_1(&L,x,0,L.length-1);
    output(index);
    index=find_2(&L,x,0,L.length-1);
    output(index);
    index=find_3(&L,x,0,L.length-1);
    output(index);
    return 0;
}