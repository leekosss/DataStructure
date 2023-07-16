#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))
typedef struct k //定义单链表结点
{
    int data;
    struct k *next;
}node;
typedef struct //定义链式队列
{
    node *head, *tail;
} queqe;
queqe* init() //初始化
{
    queqe *qu;
    qu = (queqe *)malloc(sizeof(queqe)); //先分配内存空间
    qu->head = NULL;                     //将指针初始化为空
    qu->tail = NULL;
    return qu;
}
int isEmpty(queqe *qu) //判断队列是否为空
{
    return qu->head ? 0 : 1; //为空返回1，不为空返回0
}
void push(queqe *qu, int x) //入队
{
    node *p;
    p = newNode;
    p->next = NULL;
    p->data = x;
    if (isEmpty(qu)) //如果队列为空
    {
        qu->tail = p;
        qu->head = p;
        return;
    }
    qu->tail->next = p; //队列不为空时
    qu->tail = p;
}
node *pop(queqe *qu) //出队
{
    node *p;
    if (qu->head == NULL && qu->tail == NULL) //队列元素为空，直接返回
        return NULL;
    if (qu->head == qu->tail) //队列元素只有一个时
    {
        p = qu->head;
        qu->head = NULL;
        qu->tail = NULL;
        return p;
    }
    p = qu->head; //队列从头开始出队
    qu->head = p->next;
    return p;
}
void display(queqe *qu) //打印队列中的元素
{
    node *p;
    p = qu->head;
    printf("队列中的元素为：\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    queqe *qu;
    qu = init();
    printf("请输入5个数：\n");
    int x;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        push(qu, x);
    }
    display(qu);
    printf("出队三个元素：\n");

    for (int i = 0; i < 3; i++)
    {
        node *p=pop(qu);
        if(p)  //防止空指针引用
        {
            printf("%d ",p->data);   //返回出队的元素
        }
    }
    printf("\n");
    display(qu);
    return 0;
}