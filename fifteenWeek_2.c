#include<stdio.h>  
void sortByInsert(int a[],int n)  // 直接插入排序
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}
void sortBySelect(int a[],int n) //直接选择排序
{  //无序集只有一个元素可直接结束（比他更小的元素已经被排到他前面了）
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}
void sortBySwap(int a[],int n)  //直接交换排序
{
    int i,j,temp;
    while(n>0)
    {
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
        n--;
    }
}
int main()
{
    int a[10]={1,3,5,7,8,9,2,4,0,6};
    int i;
    // sortByInsert(a,10);
    // sortBySelect(a,10);
    sortBySwap(a,10);
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}