#include<stdio.h>
#include<string.h>
int count_1(int a[],int n)   //递归算平台个数
{
    if(n<0)
        return 0;  //当数组中没有元素时
    if(n==0)
        return 1;    //当数组元素只有一个时
    if(a[n-1]==a[n])   //如果第n个元素与n-1元素相等时 ，平台个数不变
        return count_1(a,n-1);
    else
        return count_1(a,n-1)+1;   //不相等则+1
}
int count_2(int a[],int n)  //非递归算平台个数
{
    if(n<0)
        return 0;   //当数组中没有元素时
    if(n==0)
        return 1;  //当数组元素只有一个时
    int i,total=1;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            total++;   //不相等则+1
    }
    return total;
}
int main()
{
    int a[]={5,5,3,1,3,3,2,2};
    printf("%d ",count_1(a,sizeof(a)/sizeof(a[0])-1));
    printf("%d ",count_2(a,sizeof(a)/sizeof(a[0])-1));
    return 0;
}
