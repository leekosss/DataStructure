#include<stdio.h>  //朴素的模式匹配算法
#include<string.h>
int success(char *t,char *p,int i)  //判断模式串是否是文本串的字串
{
    int j;
    for(j=0;j<strlen(p);j++)
    {
        if(t[i+j]!=p[j])
            return 0;
    }
    return 1;
}
int simpleMatch(char *t,char *p)
{
    int i;
    for(i=0;i<=strlen(t)-strlen(p);i++)  //当文本串剩余长度小于模式串长度时直接结束
    {
        if(success(t,p,i))    //判断是否匹配成功
        {           
            return 1;
        }
    }
    return -1;
}
int main()
{
    char str1[100],str2[100];
    printf("请输入文本串：\n");
    gets(str1);
    printf("请输入模式串：\n");
    gets(str2); 
    int m=simpleMatch(str1,str2);
    if(m==-1)
        printf("匹配失败！");
    else if(m==1)
        printf("匹配成功！");
    return 0;
}