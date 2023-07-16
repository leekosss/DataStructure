#include <stdio.h>
#include <string.h>
#define M 100
typedef struct
{
    char str[M];
    int len;
} seqString;
void creatString(seqString *s) //创建存储字符串的顺序表
{
    printf("请输入一串字符串：\n");
    gets(s->str);
    s->len = strlen(s->str);

}
seqString *delStr(seqString *s, int i, int n) //字符串删除
{
    if (i + n >= s->len) //如果要删除的字符串长度大于顺序表长度,直接改表长
    {
        s->len = i;
        s->str[s->len]='\0';
        return s;
    }
    for (int k = i + n; k < s->len; k++, i++) //将后面元素移到前面，再改表长
    {
        s->str[i] = s->str[k];
    }
    s->len = s->len - n;
    s->str[s->len]='\0';
    return s;
}
void insertStr(seqString *s1, int i, seqString *s2) //字符串插入
{
    if(i<0||i>s1->len)
    {
        printf("位置非法！请重新输入！\n");
        return;
    }
    int n = s2->len;
    for (int k = s1->len - 1; k >= i; k--)
    {
        s1->str[k + n] = s1->str[k];
    }
    for (int k = i, j = 0;j < s2->len; k++, j++) //合法插入位置为0 到 s1->len
    {
        s1->str[k] = s2->str[j];
    }
    s1->len += n;
}
void replaceStr(seqString *s1, int i, int n, seqString *s2) //字符串替换
{
    delStr(s1, i, n); //先删除，再插入
    insertStr(s1, i, s2);
}
void show(seqString *s) //打印字符串
{
    int i = 0;
    printf("字符串内容为：\n");
    while (i < s->len)
    {
        printf("%c", s->str[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    seqString str;
    creatString(&str);
    show(&str);
    seqString *p;
    p = delStr(&str, 2, 4);
    show(p);
    seqString s2;
    creatString(&s2);
    show(&s2);
    insertStr(&str, 1, &s2);
    show(&str);
    replaceStr(&str,1,4,&s2);
    show(&str);
    return 0;
}