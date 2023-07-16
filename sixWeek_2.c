#include <stdio.h>
#include <stdlib.h>
#define newNode (linklist *)malloc(sizeof(linklist))
typedef struct k   
{
    int data;
    struct k *next;
} linklist;      //头节点型链表
linklist *creatLink()
{
    linklist *head, *p, *tail;
    int x;
    head = newNode;
    head->next = NULL;
    tail = head;
    printf("请输入一组数据，以-1结束：\n");
    scanf("%d", &x);
    while (x != -1)
    {
        p = newNode;
        p->data = x;
        p->next = NULL;
        tail->next = p;
        tail = p;
        scanf("%d", &x);
    }
    return head;
}
void show(linklist *head)
{
    linklist *p;
    p = head->next;
    printf("单链表的值为：\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void delOdd(linklist *head) //删除所有奇数
{
    linklist *p, *pre, *q;
    pre = head;
    p = head->next;
    while (p != NULL)
    {
        if (p->data % 2 == 1)
        {
            q = p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    }
}
void delPre(linklist *head, int x) //删除x的前一结点
{
    linklist *pre, *p;
    pre = head;
    p = head->next;
    if (x == p->data)
    {
        printf("错误！该值前面无元素！\n");
        return;
    }
    while (p->next != NULL && p->next->data != x)
    {
        p = p->next;
        pre = pre->next;
    }
    if (p->next != NULL && p->next->data == x)
    {
        pre->next = p->next;
        free(p);
    }
    if (p->next == NULL)
        printf("链表中无此值！\n");
}
void insertSorted(linklist *head, int x) //有序表插入
{
    linklist *p, *pre, *q;
    pre = head;
    p = head->next;
    q = newNode;
    q->next = NULL;
    q->data = x;
    if (p == NULL)   //单链表为空
    {
        head->next = q;
        return;
    }
    while (p != NULL && x > p->data)
    {
        p = p->next;
        pre = pre->next;
    }
    q->next = p;
    pre->next = q;
}
linklist *lowToUp(linklist *h1, linklist *h2) //两降序表合成升序表
{
    linklist *p, *q, *r;
    linklist *h3;
    h3 = newNode;
    h3->next = NULL;
    p = h1->next;
    q = h2->next;
    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
        {
            r = p;
            p = p->next;
            r->next = h3->next;
            h3->next = r;
        }
        else
        {
            r = q;
            q = q->next;
            r->next = h3->next;
            h3->next = r;
        }
    }
    while (p != NULL)
    {
        r = p;
        p = p->next;
        r->next = h3->next;
        h3->next = r;
    }
    while (q != NULL)
    {
        r = q;
        q = q->next;
        r->next = h3->next;
        h3->next = r;
    }
    return h3;
}
int main()
{
    linklist *head;
    head = creatLink();
    show(head);
    delOdd(head);
    show(head);
    int x;
    printf("请输入x:");
    scanf("%d", &x);
    delPre(head, x);
    show(head);
    printf("请输入x:");
    scanf("%d", &x);
    insertSorted(head, x);
    show(head);
    linklist *h2, *h3;
    h2 = creatLink();
    h3 = lowToUp(head, h2);
    show(h3);
    return 0;
}