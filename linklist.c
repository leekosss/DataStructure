#include<stdio.h>
#include<stdlib.h>
#define  newNode (linklist *)malloc(sizeof(linklist))
typedef struct k
{
    int data;
    struct k *next;
}linklist;
linklist* append()  //创建单链表  (尾插法)
{
    int x;  //单链表中的值
    linklist *head,*q,*tail; // 定义头节点，指针，尾部指针
    head=newNode;  //分配内存空间
    head->next=NULL;  //将头节点指针初始化为空
    tail=head;  //初始化尾部指针，使其指向尾部（头节点）
    printf("请输入一组数，以-1结束\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        q=newNode;  
        q->data=x;
        q->next=NULL;
        tail->next=q;  //将单链表尾部指向新创建的空间
        tail=q;   // 更新头节点的位置
        scanf("%d",&x);
    }
    return head;
}
void show(linklist *head)  //打印单链表的值
{
    linklist *q=head->next;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}
int totalNum(linklist *head)  //统计单链表的元素个数
{
    int total=0;
    linklist *q=head->next;
    while(q!=NULL)
    {
        total++;
        q=q->next;
    }
    return total;
}
// void searchIndex(linklist *head,int i)   //找第i个元素
// {
//     linklist *q=head->next;
//     int index=1; // index  当前单链表元素的下标
//     while(q!=NULL)
//     {
//         if(index!=i)
//         {
//             index++;
//         }
//         else
//         {
//             printf("恭喜！下标为 %d 的元素找到了！\n",i);
//             return;   //找到了就结束函数
//         }
//         q=q->next;
//     }
//     printf("对不起，没有找到！\n");
// }
void searchValue(linklist *head,int x) //寻找值为x的元素,并将其删除
{
    linklist *q=head->next,*pre=head;
    while(q!=NULL)
    {
        if(q->data==x)
        {
            pre->next=q->next;
            free(q);
            return;
        }
        q=q->next;
        pre=pre->next;
    }
    printf("对不起,没有找到.");
}
void insertBefore(linklist *head,int x,int y)  //在值为x的元素前插入y
{
    linklist *pre=head,*p=head->next,*q;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q=newNode;  //创立一个新节点
            q->data=y;
            q->next=p;
            pre->next=q;
            return;
        }
        p=p->next;
        pre=pre->next;
    }
    printf("对不起，插入失败！");
}
void insertAfter(linklist *head,int x,int y)  //在值为x的元素后插入y
{
    linklist *last,*p=head->next,*q;   //last 是p后面的一个指针
    last=p->next;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q=newNode;
            q->data=y;
            q->next=last;
            p->next=q;
            return;
        }
        p=p->next;
        last=last->next;
    }
    printf("对不起，插入失败！");
}
void insert(linklist *head,int x)  //在升序表中插入x
{
    linklist *p=head->next,*pre=head,*q;
    q=newNode;
    while(p!=NULL)   //将x插入升序表中间
    { 
        if(p->data>=x)
        {
            
            q->data=x;
            q->next=p;
            pre->next=q;
            return;
        }
        else
        {
            p=p->next;
            pre=pre->next;
        }
    }
    if(pre->next==NULL&&x>pre->data)   //插入x到升序表的最后
    {
        q->data=x;
        q->next=NULL;
        pre->next=q;
        return;
    }
    printf("插入失败！\n");
}
void insertFirst(linklist *head)   //将单链表最小值插入到表头
{
    linklist *p=head->next,*pre=head,*min=head->next,*prMin=head;
    while(p!=NULL)
    {
        if(p->data<min->data)
        {
            min=p;
            prMin=pre;
        }
        p=p->next;
        pre=pre->next;
    }  
    prMin->next=min->next;       //将最小元素的结点剔除，放到链表头（不是简单交换相应的数值）
    min->next=head->next;
    head->next=min;
}
int main()
{
    linklist *head;
    head=append();
    printf("单链表的值为\n");
    show(head);
    int sum;
    sum=totalNum(head);
    printf("\n总共有%d个元素\n",sum);
    int index;
    printf("请输入想到查找单链表元素的下标\n");  //通过下标来查找元素
    scanf("%d",&index);
    searchIndex(head,index);
    int x;
    printf("请输入想要删除单链表元素的值\n");
    scanf("%d",&x);
    searchValue(head,x);
    show(head);
    int y;
    printf("请输入两个数，分别表示要查找的值，其前面插入的值\n");
    scanf("%d%d",&x,&y);
    insertBefore(head,x,y);
    show(head);
    printf("请输入两个数，分别表示要查找的值，其后面插入的值\n");
    scanf("%d%d",&x,&y);
    insertAfter(head,x,y);
    show(head);
    printf("请输入一个数，插入升序表中\n");
    scanf("%d",&x);
    insert(head,x);
    show(head);
    printf("\n将单链表最小值插入到表头\n");
    insertFirst(head);
    show(head);
    return 0;
}