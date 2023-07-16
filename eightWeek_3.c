#include<stdio.h>
#include<stdlib.h>
typedef struct k
{
    char str[10];
    struct k *next; //定义链块结构
}node;
node* read(char *p)  
{
    node *head,*q,*r;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    q=head;
    int i=0,j=0;
    while(p[i]!='\0')
    {
        if(j==9&&q->str[9]!='\0')
        {
            q->str[9]=p[i];
            r=(node*)malloc(sizeof(node));   //当空间不够时，再造新结点
            r->next=NULL;
            q->next=r;   //将结点连接起来
            q=r;
            j=0;
        }
        q->str[j]=p[i];
        j++;
        i++;
    }
    q->str[j]='\0';
    return head;
}
void show(node *head)
{
    node *p;
    p=head;
    int i=0;
    printf("字符串内容为：\n");
    while(p->str[i]!='\0')
    {
        printf("%c",p->str[i]);
        i++;
        if(i==9&&p->str[9]!='\0')
        {
            printf("%c",p->str[9]);
            p=p->next;
            i=0;
        }
    }
}
int main()
{
    node *head;
    head=read("abcdefghijklmnkksadadad");
    show(head);
    return 0;
}