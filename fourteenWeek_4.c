#include<stdio.h>
int search_1(int a[],int left,int right,int x)
{
    if(left>right)
        return -1;
    int mid;
    mid=(right-left)*3/7+left;
    if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
        return search_1(a,left,mid-1,x);
    else
        return search_1(a,mid+1,right,x);
}
int search_2(int a[],int left,int right,int x)
{
    int mid,count=0;
    while(left<=right)
    {
        count++;
        mid=(right-left)*3/7+left;
        if(a[mid]==x)
        {
            printf("查找次数：%d\n",count);
            return mid;
        }
        else if(a[mid]>x)
        {
            right=mid-1;
        }
        else
            left=mid+1;
    }
    printf("查找次数：%d\n",count);
    return -1;
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d\n",search_1(a,0,9,4));
    printf("%d\n",search_2(a,0,9,5));
    return 0;
}