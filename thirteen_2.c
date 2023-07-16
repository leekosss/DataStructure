#include<stdio.h>
#include<stdlib.h>
#define M 20
#define WQD 9999
typedef struct 
{
    int v[M];   //图的点集
    int e[M][M];  //图的边集，即邻接矩阵
    int vNum,eNum;  //图中的点数，边数
}graph;   //定义图
void creatGraph(graph *g)   //创建邻接矩阵
{   //(0,2,4)(0,3,28)(1,0,2)(1,4,10)(2,1,15)(2,5,8)(4,3,4)(5,3,13)(5,4,18)
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
            g->e[i][j]=WQD;
    for(i=0;i<vNum;i++)
        g->e[i][i]=0;

    fflush(stdin);  //清除缓存字符，防止接下来(a,b)读取失败！

    printf("请输入图的边,例如:从0到1发出一条边值为2  (0,1,2) \n");
    for(i=0;i<eNum;i++)
    {
        scanf("(%d,%d,%d)",&a,&b,&c);
        g->e[a][b]=c;    //将邻接矩阵中的值改为1，代表a->b有一条边
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
void reverse_creat(LinJieBiao *g)  //逆邻接表创建
{
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
        insert(g,b,a);   //入边表
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
int xChuDu(LinJieBiao *g,int x)  //计算结点x的出度(邻接表)
{
    int count=0;
    eNode *e;
    e=g->v[x].first;
    while(e!=NULL)
    {
        count++;
        e=e->next;
    }
    return count;
}
int xRuDu(LinJieBiao *g,int x)  //计算结点x的入度(邻接表)
{
    int count=0,i;
    eNode *e;
    for(i=0;i<g->vNum;i++)
    {
        e=g->v[i].first;
        while(e!=NULL)
        {
            if(e->v==x)
                count++;
            e=e->next;
        }
    }
    return count;
}

int LinJieRuDu(graph *g,int x)   //计算结点x的入度(邻接矩阵)
{
    int i,count=0;
    for(i=0;i<g->vNum;i++)
    {
        if(g->e[i][x]!=0&&g->e[i][x]!=WQD)
            count++;
    }
    return count;
}
int LinJieChuDu(graph *g,int x)    //计算结点x的出度(邻接矩阵)
{
    int i,count=0;
    for(i=0;i<g->vNum;i++)
    {
        if(g->e[x][i]!=0&&g->e[x][i]!=WQD)
            count++;
    }
    return count;
}
int main()
{
    graph g;
    creatGraph(&g);
    printf("网络邻接矩阵:\n");
    printGraph(&g);
    LinJieBiao L1,L2;
    creat(&L1);
    printf("邻接表：\n");
    print(&L1);
    // reverse_creat(&L2);
    // printf("逆邻接表：\n");
    // print(&L2);
    // printf("邻接表中结点：%d的出度为:%d\n",5,xChuDu(&L1,5));
    // printf("邻接表中接待你：%d的入度为:%d\n",1,xRuDu(&L1,1));
    printf("邻接矩阵中结点:%d的出度为:%d\n",3,LinJieChuDu(&g,3));
    printf("邻接矩阵中结点:%d的入度为:%d\n",3,LinJieRuDu(&g,3));
    return 0;
}