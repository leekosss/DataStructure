#include<stdio.h>
int search_1(int a[],int left,int right,int x)
{
    if(left>right)
        return -1;
    int mid;
    mid=(left+right)/2;
    if(a[mid]==x)
        return mid;
    else if(x<a[mid])
        return search_1(a,left,mid-1,x);
    else
        return search_1(a,mid+1,right,x);
}
int search_2(int a[],int left,int right,int x)
{
    int count=0,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        count++;
        if(a[mid]==x)
        {
            printf("查找：%d 成功！查找次数为：%d\n",x,count);
            return mid;
        }
        else if(a[mid]>x)
            right=mid-1;
        else
            left=mid+1;
        
    }
    printf("查找：%d 失败！查找次数为：%d\n",x,count);
    return -1;
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    printf("下标:%d\n",search_1(a,0,9,4));
    printf("下标：%d\n",search_2(a,0,9,4));
    return 0;
}