#include<stdio.h>
#define M 10000
int trsTwo(int a[],int N)
{
    int i=0;
    while(N>0)
    {
        a[i]=N%2;
        i++;
        N/=2;
    }
    return i;
}
int number(int a[],int length)
{
    int i,num=0;
    for(i=0;i<length;i++)
    {
        if(a[i]==1)
        {
            num++;
        }
    }
    return num;
}
int main()
{
    int N,num;
    scanf("%d",&N);
    int arr[M];
    int length;
    length=trsTwo(arr,N);
    num=number(arr,length);
    printf("%d",num);
    return 0;
}