#include<stdio.h>
#include<stdlib.h>
typedef struct k
{
    int data;
    struct k *next;
}linklist;
linklist* append()  //创建单链表  (尾插法)
{
    linklist *head,*p,*tail;
    head=(linklist*)malloc(sizeof(linklist));
    head->next=NULL;
    tail=head;
    int x;
    printf("请输入一组数，以-1结束\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        p=(linklist*)malloc(sizeof(linklist));
        p->next=NULL;
        p->data=x;
        tail->next=p;
        tail=p;
        scanf("%d",&x);
    }
    return head;
}
void show_1(linklist *head)  //正序输出单链表
{
    if(head->next==NULL)
        return;
    printf("%d ",head->next->data);   //先输出首
    show_1(head->next);   //再输出余部
}
void show_2(linklist *head)   //逆序输出单链表
{
    if(head->next==NULL)
        return;
    show_2(head->next);   
    printf("%d ",head->next->data);  //先输出尾，再输出前部
}
int main()
{
    linklist *h;
    h=append();
    show_1(h);
    printf("\n");
    show_2(h);
    return 0;
}