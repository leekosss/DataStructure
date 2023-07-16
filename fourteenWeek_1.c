#include<stdio.h>
#include<stdlib.h>
#define M 20
typedef struct 
{
    int v[M];   //图的点集
    int e[M][M];  //图的边集，即邻接矩阵
    int vNum,eNum;  //图中的点数，边数
}graph;   //定义图
void creatGraph(graph *g)   //创建邻接矩阵
{   //(0,2)(0,3)(1,0)(1,4)(2,1)(2,5)(4,3)(5,3)(5,4)
    int vNum,eNum,a,b,c;
    printf("请输入图的点数和边数\n");
    scanf("%d %d",&vNum,&eNum);
    g->vNum=vNum;
    g->eNum=eNum;
    int i,j;
    for(i=0;i<vNum;i++)   //初始化点集
        g->v[i]=i;
    for(i=0;i<vNum;i++)   //初始化边集
        for(j=0;j<vNum;j++)
            g->e[i][j]=0;

    fflush(stdin);  //清除缓存字符，防止接下来(a,b)读取失败！

    printf("请输入图的边,例如:从0到1发出一条边值为2  (0,1) \n");
    for(i=0;i<eNum;i++)
    {
        scanf("(%d,%d)",&a,&b);
        g->e[a][b]=1;    //将邻接矩阵中的值改为1，代表a->b有一条边
    }
}
void printGraph(graph *p)  //输出邻接矩阵
{
    int i,j;
    for(i=0;i<p->vNum;i++)
    {
        for(j=0;j<p->vNum;j++)
            printf("%-8d",p->e[i][j]);
        printf("\n");
    }
}

typedef struct k
{
    int v;  //图的点下标
    struct k *next;
}eNode;  //邻接表的边
typedef struct
{
    int vData;  //点集
    eNode* first;   //边集
}vNode;   
typedef struct
{
    vNode v[M];
    int vNum,eNum;
}LinJieBiao;  //邻接表
void insert(LinJieBiao *g,int a,int b)  //将点的下标插入邻接表
{   
    eNode *e,*tail;
    e=(eNode*)malloc(sizeof(eNode));
    e->next=NULL;
    e->v=b;
    if(g->v[a].first==NULL)
    {
        g->v[a].first=e;
        return;
    }
    tail=g->v[a].first;
    while(tail->next!=NULL)
        tail=tail->next;
    tail->next=e;

}
void creat(LinJieBiao *g)  //邻接表创建
{  //(0,2)(0,3)(1,0)(1,4)(2,1)(2,5)(4,3)(5,3)(5,4)  || 6个点，9条边
    int vNum,eNum,i,j,a,b;
    printf("请输入点和边的个数:\n");
    scanf("%d %d",&vNum,&eNum);
    g->vNum=vNum;
    g->eNum=eNum;
    for(i=0;i<vNum;i++)
    {
        g->v[i].vData=i;
        g->v[i].first=NULL;
    }
    fflush(stdin);
    printf("请输入图的边,例如:从0到1发出一条边为  (0,1) \n");
    for(i=0;i<eNum;i++)
    {
        scanf("(%d,%d)",&a,&b);
        insert(g,a,b);  //出边表
    }
}
void print(LinJieBiao *g)  //邻接表输出
{
    int i;
    eNode *e;
    for(i=0;i<g->vNum;i++)
    {
        printf("%-3d | ",g->v[i].vData);
        e=g->v[i].first;
        while(e!=NULL)
        {
            printf("-> %-3d",e->v);
            e=e->next;
        }
        printf("\n");
    }
}

typedef struct 
{
    int c[M];
    int f,r;
}queue;  //队列
void init(queue *q)  //队列初始化
{
    q->f=0;
    q->r=0;
}
int isEmpty(queue *q)  //判断队列是否为空
{
    return q->f==q->r?1:0;
}
void enQueue(queue *q,int x)  //入队
{
    q->c[q->r]=x;
    q->r=(q->r+1)%M;
}
int outQueue(queue *q)  //出队
{
    int t;
    t=q->c[q->f];
    q->f=(q->f+1)%M;
    return t;
}


//邻接表的深度遍历
void DfsBiaoShen(LinJieBiao *L,int v,int visited[])
{
    printf("%d",v);
    visited[v]=1; //已被访问
    eNode *e;
    e=L->v[v].first;
    while(e!=NULL)
    {
        if(visited[e->v]==0)  //未被访问则访问
            DfsBiaoShen(L,e->v,visited);
        e=e->next;
    }
}

//邻接表广度遍历
void BfsBiaoGuang(LinJieBiao *L,int v,int visited[])
{
    queue q;
    init(&q);
    enQueue(&q,v);
    visited[v]=1;
    eNode *e;
    while(isEmpty(&q)!=1)
    {
        v=outQueue(&q);
        printf("%d",v);
        for(e=L->v[v].first;e!=NULL;e=e->next)
        {
            if(visited[e->v]==0)
            {
                visited[e->v]=1;
                enQueue(&q,e->v);
            }
        }
    }
    
}


void DfsLinJieBiao(LinJieBiao *L)
{
    int visited[M]={0};  // 判断点是否被访问
    int v;
    for(v=0;v<L->vNum;v++)
    {
        if(visited[v]==0)
            // DfsBiaoShen(L,v,visited);  //邻接表深度优先
            BfsBiaoGuang(L,v,visited);  //邻接表广度优先
    }
}

void DfsGraph(graph *g,int v,int visited[])  //邻接矩阵深度优先
{
    printf("%d",v);
    visited[v]=1;
    int i;
    for(i=0;i<g->vNum;i++)
    {
        if(g->e[v][i]==1&&visited[i]==0)
        {
            visited[i]=1;
            DfsGraph(g,i,visited);
        }
    }
}

void BfsGraph(graph *g,int v,int visited[])  //邻接矩阵广度遍历
{
    queue q;
    init(&q);
    enQueue(&q,v);
    visited[v]=1;
    int i;
    while(isEmpty(&q)!=1)
    {
        v=outQueue(&q);
        printf("%d",v);
        for(i=0;i<g->vNum;i++)
        {
            if(g->e[v][i]==1&&visited[i]==0)
            {
                enQueue(&q,i);
                visited[i]=1;
            }
        }
    }
}
void LinJieGraph(graph *g)
{
    int visited[M]={0};
    int v;
    for(v=0;v<g->vNum;v++)
    {
        if(visited[v]==0)
        {
            DfsGraph(g,v,visited);
            // BfsGraph(g,v,visited);
        }
    }
}

int main()
{
    // LinJieBiao L;
    // creat(&L);
    // print(&L);
    // DfsLinJieBiao(&L);
    graph g;
    creatGraph(&g);
    printGraph(&g);
    LinJieGraph(&g);
    return 0;
}