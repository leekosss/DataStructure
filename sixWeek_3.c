#include <stdio.h> //头指针型单链表
#include <stdlib.h>
#define newNode (linklist *)malloc(sizeof(linklist))
typedef struct k
{
    int data;
    struct k *next;
} linklist;
linklist *creatLink() //建表
{
    linklist *head, *p, *tail;
    int x;
    printf("请输入一组数，以-1结束：\n");
    scanf("%d", &x);
    if (x == -1)
        return NULL; //可能一开始就输入-1，为空表
    head = newNode;  //第一个单独处理
    head->next = NULL;
    head->data = x;
    tail = head;
    scanf("%d", &x);
    while (x != -1)
    {
        p = newNode;
        p->next = NULL;
        p->data = x;
        tail->next = p;
        tail = p;
        scanf("%d", &x);
    }
    return head;
}
void show(linklist *head)
{
    linklist *p;
    p = head;
    printf("链表内容为：\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
linklist *delOdd(linklist *head) //删除单链表中的奇数
{                                // 因为链表为头指针型，可能删除第一个元素，故需返回首地址
    linklist *pre, *p, *q;
    if(head == NULL)   //防止空指针引用
        return NULL;
    pre = head;
    p = head->next;
    while(p!=NULL) 
        {
            if(p->data%2==1)
            {
                q=p;
                p=p->next;
                pre->next=p;
                free(q);
            }
            else 
            {
                p=p->next;
                pre=pre->next;
            }
        }
    if(head->data%2==1)   //第一个结点数为奇数
    {
        q=head;
        head=head->next;
        free(q);
    }
    return head;
}
linklist *insertSorted(linklist *head, int x) //升序表插入x
{
    linklist *p, *pre, *q;
    q = newNode;
    q->next = NULL;
    q->data = x;
    if (head == NULL) //当升序表为空表时
        return q;
    if (x < head->data) //当x小于升序表第一个元素时，插在表头
    {
        q->next = head;
        return q;
    }
    pre = head;
    p = head->next;
    while (p != NULL && x > p->data)
    {
        p = p->next;
        pre = pre->next;
    } //出循环后p->data>x
    q->next = p;
    pre->next = q;
    return head;
}
linklist *lowToUp(linklist *h1, linklist *h2) //两降序表合成升序表
{
    //使用头插法
    linklist *r;
    linklist *head=NULL;  //初始化为空
    while(h1!=NULL&&h2!=NULL) 
    {
        if(h1->data>h2->data)
        {
            r=h1;
            h1=h1->next;
            r->next=head;
            head=r;
        }
        else
        {
            r=h2;
            h2=h2->next;
            r->next=head;
            head=r;
        }
    }
    while(h1!=NULL)
    {
        r=h1;
        h1=h1->next;
        r->next=head;
        head=r;
    }
    while(h2!=NULL)
    {
        r=h2;
        h2=h2->next;
        r->next=head;
        head=r;
    }
    return head;
}
int main()
{
    linklist *head;
    head = creatLink();
    show(head);
    // head = delOdd(head);
    // printf("删除奇数\n");
    // show(head);
    // printf("请输入x，并插入在升序表中：");
    // int x;
    // scanf("%d", &x);
    // head = insertSorted(head, x);
    // show(head);
    linklist *h2, *h3;
    h2 = creatLink();
    h3 = lowToUp(head, h2);
    show(h3);
    return 0;
}