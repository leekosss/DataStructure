#include <stdio.h>
#include <stdlib.h>
#define m 3
#define MAX 100
typedef struct k{
    int data;
    struct k *c[m];
}tree;

typedef struct{//数组+队首、队尾指针
    tree* data[MAX];//注意：后续队列应用中，需要使用到出队元素的孩子，故队列中存储的只能是tree*类型
    int f,r;
}queue;

void init(queue *q)//初始化
{
    q->f=0;
    q->r=0;
}

int isEmpty(queue *q)//判空
{
    if(q->f==q->r) return 1;
    else return 0;
}

void enQueue(queue *q,int x)//入队
{
    q->data[q->r]=x;
    q->r=(q->r+1)%MAX;
}

tree *outQueue(queue *q)//出队
{
    tree *x;
    x=q->data[q->f];
    q->f=(q->f+1)%MAX;
    return x;
}

tree *create()
{
    int i;
    tree *t;
    char c;
    c=getchar();
    if(c=='#') return NULL;//输入‘#’号表示空
    //走至此处说明创建的是非空树
    t=(tree *)malloc(sizeof(tree));//造根
    t->data=c;//赋值
    for(i=0;i<m;i++)
        t->c[i]=create();//将新建的树交给t的孩子t->c[i];
    return t;
}

void level(tree *t){
    tree *p; int i;
    queue q; init(&q);//创建并初始化队列
    enQueue(&q,t);//对应1、根入队
    while( isEmpty(&q)!=1 ){
        p=outQueue(&q);
        printf("%d ",p->data);
        for(i=0; i<m; i++)
            if(p->c[i]!=NULL)enQueue(&q, p->c[i]);
    }
}

main(){ tree *t ,*a;
    printf("请输入结点，0表示NULL：");
    a=create();
    printf("\n层次遍历结果为：\n");
    level(t);
}