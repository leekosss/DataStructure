#include<stdio.h>
typedef struct
{
    int index;  //索引
    int data;  //数值
}indexTab;  //索引表

int find(int a[],int aLen,indexTab b[],int bLen,int x)  
{
    int count=0;  //比较次数
    int i,j;
    if(x>b[bLen-1].data)  //大于最大值直接返回-1
    {
        printf("比较的次数为：%d\n",bLen+1);
        return -1;
    }  
    i=0;
    while(b[i].data<x)
    {
        count++;
        i++;
    }
    count++;
    for(j=b[i].index;j<b[i].index+7;j++)
    {
        count++;
        if(a[j]==x)
        {
            printf("比较的次数为：%d\n",count);
            return j;
        }
    }
    count++;
    printf("比较的次数为：%d\n",count);
    return -1;
}

int main()
{
    int a[21]={20,4,25,17,3,12,6,  40,30,27,55,48,35,70,  66,90,60,86,73,69,89};
    indexTab b[3]={{0,25},{7,70},{14,90}};
    int index=find(a,21,b,3,30);
    printf("下标：%d\n",index);
    return 0;
}