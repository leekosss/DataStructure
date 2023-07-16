#include<stdio.h>
#include<stdlib.h>
#define newNode (linkList *)malloc(sizeof(linkList))
typedef struct k
{
    int data;
    struct k *next;
}linkList;
linkList * tailInsert()   //尾插法建立链表
{   
    linkList *h;
    h=newNode;
    h->next=NULL;
    int x;
    linkList *head=h,*tail=h,*p;
    printf("请输入一系列数值，以-1结束\n");
    scanf("%d",&x);
    while(x!=-1) 
    {
        p=newNode;
        p->next=NULL;
        p->data=x;
        tail->next=p;
        tail=p;
        scanf("%d",&x);
    }
    return h;
}
void tailInsert1(linkList *h) 
{   
    
    int x;
    linkList *tail=h,*p;
    printf("请输入一系列数值，以-1结束\n");
    scanf("%d",&x);
    while(x!=-1) 
    {
        p=newNode;
        p->next=NULL;
        p->data=x;
        tail->next=p;
        tail=p;
        scanf("%d",&x);
    }
    
}
linkList * headInsert()  //  头插法
{
    linkList *h;
    h=newNode;
    h->next=NULL;
    linkList *head;
    int x;
    printf("\n请输入一系列数值，以-1结束\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        head=newNode;
        head->next=NULL;
        head->data=x;
        head->next=h->next;
        h->next=head;
        scanf("%d",&x);
    } 
    return h;
}
void show(linkList *h)
{
    linkList *p=h->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    linkList *h;
    // h=tailInsert();
    // show(h);
    // linkList *h1;
    // h1=headInsert();
    // show(h1);
    h=newNode;
    h->next=NULL;
    tailInsert1(h);
    show(h);
    return 0;
}
