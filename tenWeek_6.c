#include<stdio.h>
#include<string.h>
int count_1(int a[],int n)   //�ݹ���ƽ̨����
{
    if(n<0)
        return 0;  //��������û��Ԫ��ʱ
    if(n==0)
        return 1;    //������Ԫ��ֻ��һ��ʱ
    if(a[n-1]==a[n])   //�����n��Ԫ����n-1Ԫ�����ʱ ��ƽ̨��������
        return count_1(a,n-1);
    else
        return count_1(a,n-1)+1;   //�������+1
}
int count_2(int a[],int n)  //�ǵݹ���ƽ̨����
{
    if(n<0)
        return 0;   //��������û��Ԫ��ʱ
    if(n==0)
        return 1;  //������Ԫ��ֻ��һ��ʱ
    int i,total=1;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            total++;   //�������+1
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
