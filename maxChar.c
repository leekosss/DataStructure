#include<stdio.h>
#define M 10000
int main()
{
    int arr[26]={0};
    int i;
    char zimu[M];
    scanf("%s",zimu);
    for(i=0;i<26;i++)
    {
        arr[zimu[i]-'a']++;
    }
    int max=0;
    for(i=0;i<26;i++)
    {
        if(arr[max]<arr[i])
        {
            max=i;
        }
    }
    printf("%c %d",max+97,arr[max]);
    return 0;
}