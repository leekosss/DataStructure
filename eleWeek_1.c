#include<stdio.h>  //设计能存储char型数据的m度树
#include<stdlib.h>
#define m 2
#define MAX 100
typedef struct k   //定义m度树
{
    char data;
    struct k* c[m];
}tree;

typedef struct
{
    tree* data[MAX];  //定义队列
    int f,r;
}queue;
void init(queue *q)  //初始化队列
{
    q->f=0;
    q->r=0;
}
int isEmpty(queue *q)   //判断队列是否为空
{
    return q->f==q->r?1:0;
}
void enQueue(queue *q,tree* x)  //队尾入队
{
    q->data[q->r]=x;
    q->r=(q->r+1)%MAX;
}
tree* outQueue(queue *q)  //队首出队
{
    tree *p;
    p=q->data[q->f];
    q->f=(q->f+1)%MAX;
    return p;
}  

tree* createTree()   //建树
{  //先建根，再建子树
    char c;  
    int i;   
    c=getchar();
    if(c=='#')  //如果输入'#'，返回空树
        return NULL;
    tree *p;
    p=(tree*)malloc(sizeof(tree));  //造数的根
    p->data=c;
    for(i=0;i<m;i++)
        p->c[i]=createTree();  //运用递归造子树
    return p;
}
void pre(tree *p)  //前序遍历
{
    if(p==NULL)
        return;
    int i;
    printf("%c",p->data);   //先输出根，后输出子树
    for(i=0;i<m;i++)
        pre(p->c[i]);
}
void post(tree *p)  //后序遍历
{
    if(p==NULL)
        return;
    int i;
    for(i=0;i<m;i++)
        pre(p->c[i]);
    printf("%c",p->data);
}
tree* findX(tree *p,char x)  //在树中查找值为x的结点
{
    if(p==NULL)
        return NULL;  //树为空返回NULL
    if(p->data==x)
        return p;   //先在根中找
    int i;
    tree *t;
    for(i=0;i<m;i++)  //再在子树中找
    {
        t=findX(p->c[i],x);
        if(t!=NULL)   //找到了就会返回子树
            return t;
    }
    return NULL;  //没找到返回NULL
}
int count_YZ(tree *p)  //统计 叶子 结点数
{
    if(p==NULL)     //如果树为空，则没有叶子
        return 0;
    int sum=0,i;
    for(i=0;i<m;i++)
        if(p->c[i]!=NULL)
            break;
    if(i==m)
        return 1;   //如果树中根为叶子，返回1
    for(i=0;i<m;i++)
        sum+=count_YZ(p->c[i]);  //再加上子树中所有的结点数
    return sum;    //把节点数返回
}
int count_2(tree *p)  //统计 2度结点数量
{
    if(p==NULL)   //如果树为空，则没有2度结点
        return 0;
    int sum=0,i,count=0;
    for(i=0;i<m;i++)
        if(p->c[i]!=NULL)
            count++;
    if(count==2)   //如果树中根为二度结点，sum=1
        sum=1;
    for(i=0;i<m;i++)   
        sum+=count_2(p->c[i]);   //再加上子树中所有的二度结点数
    return sum; 
}
int countSum(tree *p)  //统计树中的结点总数
{
    if(p==NULL)   //根为空，返回0
        return 0;
    int sum=1,i;   //根不为空，总结点数此时为1
    for(i=0;i<m;i++)
        sum+=countSum(p->c[i]);   //加上子树中所有结点数
    return sum;
}
int treeHeight(tree *p)  //计算树的高度
{
    if(p==NULL)
        return 0;   //树为空，高度为0
    int i,h=0,max=0;
    for(i=0;i<m;i++)
    {
        max=treeHeight(p->c[i]);   //从子树中找最大子数高度
        if(max>h)
            h=max;
    }
    return h+1;   //返回最大子树高度+1  即为数的高度
}

void level(tree *p)   //树的层次遍历（利用队列先进先出的性质）
{
    /* 策略：
    1、根入队
    2、
    while（队列不空）
    {
        t=出队元素
        访问t
        树的所有非空孩子依次入队
    }
    */
    tree *t;
    int i;
    queue q;  //定义队列
    init(&q);  //初始化队列
    enQueue(&q,p);  //根入队
    while(isEmpty(&q)!=1)   //当根不为空时
    {
        t=outQueue(&q);
        printf("%c",t->data);  //根出队，打印根的值
        for(i=0;i<m;i++)                                
            if(t->c[i]!=NULL)
                enQueue(&q,t->c[i]);  //让所有树的所有非空孩子入队
    }
}

void aoru(tree *p,int kg,int jh)  //凹入输出  kg,jh：  空格、'#' 个数
{
    if(p==NULL)
        return;  //树为空直接return
    int i;
    for(i=0;i<kg;i++)
        printf("%c",' ');  //先输出空格
    printf("%c",p->data);  //再输出根
    for(i=0;i<jh;i++)
        printf("%c",'#');  //然后输出'#'
    printf("\n");
    for(i=0;i<m;i++)
        aoru(p->c[i],kg+2,jh-2);  //先输出根，再使用递归输出子树
}
void kuohao(tree *p)  //括号输出
{
    if(p==NULL)   //树为空直接return
        return;
    int i,x;
    printf("%c",p->data);
    for(x=0;x<m;x++)
        if(p->c[x]!=NULL)
            break;
    if(x<m)
        printf("(");  //如果根有孩子，则输出'('
    for(i=0;i<m;i++)
        kuohao(p->c[i]);  //使用递归输出子树
    if(x<m)
        printf(")");  //根有孩子，输出')'
}


int main()
{
    tree *p,*q;
    printf("请输入树中的结点，以'#'结束：\n");
    p=createTree();
    pre(p);
    printf("\n");
    q=findX(p,'A');
    printf("%c\n",q->data);
    printf("%d\n",count_YZ(p));
    printf("%d\n",count_2(p));
    printf("%d\n",countSum(p));
    printf("%d\n",treeHeight(p));
    aoru(p,2,20);
    kuohao(p);
    level(p);
    return 0;
}