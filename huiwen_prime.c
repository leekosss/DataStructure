#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool isPrime(int x)
{
    int i;
    if(x==2)
    {
        return true;
    }
    if(x%2==0)
    {
        return false;
    }
    for(i=2;i<x;i++)
    {
        if(x%i==0)
        {
            return false;
        }
        if(i==x-1)
        {
            return true;
        }
    }
    return false;
}
bool isHuiWen(int x)
{
    int i,len=0;
    int a[100]={0};
    while(x>0)
    {
        a[len]=x%10;
        x/=10;
        len++;
    }
    int left=0,right;
    right=len-1;
    while(left<right)
    {
        if(a[left]==a[right])
        {
            left++;
            right--;
        }
        else 
        {
            return false;
        }
    }
    return true;
}
int main(){
    int i;
    int num=0,n;
    int arr[10000]={0};
    scanf("%d",&n);
    for(i=(int)(pow(10,n-1));i<(int)(pow(10,n));i++)
    {  
        if(isPrime(i)&&isHuiWen(i))
        {
            arr[num]=i;
            num++;
        }
    }
    printf("%d\n",num);
    for(i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}