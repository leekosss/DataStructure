#include<stdio.h>  
#include<stdlib.h>
#define MAX 100
typedef struct k
{
    char data;
    struct k *left,*right;
}btree;   //存储char型数据的二叉树
btree* createBtree()  //建树
{
    char c;
    c=getchar();
    if(c=='#')
        return NULL;
    btree *t;
    t=(btree*)malloc(sizeof(btree));
    t->data=c;
    t->left=createBtree();
    t->right=createBtree();
    return t;
} 
void pre(btree *t)   //前序遍历
{
    if(t==NULL)
        return;
    printf("%c",t->data);
    pre(t->left);
    pre(t->right);
}
void mid(btree *t)  //中序遍历
{
    if(t==NULL)
        return;
    mid(t->left);
    printf("%c",t->data);
    mid(t->right);
}
void post(btree *t)  //后序遍历
{
    if(t==NULL)
        return;
    post(t->left);
    post(t->right);
    printf("%c",t->data);
}

typedef struct 
{
    btree *c[MAX];
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
void enQueue(queue *q,btree *x)  //入队
{
    q->c[q->r]=x;
    q->r=(q->r+1)%MAX;
}
btree* outQueue(queue *q)  //出队
{
    btree *t;
    t=q->c[q->f];
    q->f=(q->f+1)%MAX;
    return t;
}

void level(btree *t)  //层次遍历
{
    btree *p;
    queue q;
    init(&q);
    enQueue(&q,t);
    while(isEmpty(&q)!=1)
    {
        p=outQueue(&q);
        printf("%c",p->data);
        if(p->left!=NULL)
            enQueue(&q,p->left);  //让出队根的所有非空元素入队
        if(p->right!=NULL)    
            enQueue(&q,p->right);
    }
}
btree* findX(btree *t,char x)  //在二叉树t中查找值为x的结点
{
    if(t==NULL)   
        return NULL;
    if(t->data==x)
        return t;
    if(findX(t->left,x)!=NULL)
        return findX(t->left,x);
    return findX(t->right,x);
}

btree* findXParent(btree *t,char x)   //在二叉树t中查找值为x的结点,返回其双亲结点(t->data!=x)
{
    if(t==NULL)
        return NULL;
    if(t->left!=NULL&&t->left->data==x)
        return t;
    if(t->right!=NULL&&t->right->data==x)
        return t;
    if(findXParent(t->left,x)!=NULL)
        return findXParent(t->left,x);
    return findXParent(t->right,x);
}
int count_0(btree *t)  //统计二叉树中0度结点个数
{
    if(t==NULL)
        return 0;
    if(t->left==NULL&&t->right==NULL)
        return 1;
    return count_0(t->left)+count_0(t->right);
}
int count_1(btree *t)  //统计1度结点个数
{
    if(t==NULL)
        return 0;
    int sum=0;
    if((t->left==NULL&&t->right!=NULL)||(t->left!=NULL&&t->right==NULL))
        sum=1;
    return count_1(t->left)+count_1(t->right)+sum;
}
int count_2(btree *t)  //统计2度结点个数
{
    if(t==NULL)
        return 0;
    int sum=0;
    if(t->right!=NULL&&t->left!=NULL)
        sum=1;
    return count_2(t->left)+count_2(t->right)+sum;
}
int btreeHeight(btree *t)   //统计二叉树高度
{
    if(t==NULL)
        return 0;
    int h=0;
    if(btreeHeight(t->left)>h)
        h=btreeHeight(t->left);
    if(btreeHeight(t->right)>h)
        h=btreeHeight(t->right);
    return h+1;
}
int xHeight(btree *t,char x)  //在二叉树找x，找到返回其高度
{  
    if(t==NULL)
        return 0;
    if(t->data==x)
        return 1;
    if(xHeight(t->left,x)!=0)
        return xHeight(t->left,x)+1;
    if(xHeight(t->right,x)!=0)
        return xHeight(t->right,x)+1;
}
void swap(btree *t)  //将二叉树左右子树互换
{
    if(t==NULL||(t->left==NULL&&t->right==NULL))
        return;
    btree *temp;
    temp=t->left;
    t->left=t->right;
    t->right=temp;
    swap(t->left);
    swap(t->right);
}

typedef struct  //定义栈
{
    btree *c[MAX];
    int top;
}Stack;
void initStack(Stack *s)  //初始化栈
{
    s->top=0;
}
int isEmptyStack(Stack *s)
{
    return s->top==0?1:0;
}
void enStack(Stack *s,btree *x)  //入栈
{
    s->c[s->top]=x;
    s->top++;
}
btree* outStack(Stack *s)  //出栈
{
    btree *t;
    s->top--;
    t=s->c[s->top];
    return t;
}
//ABE#F##C#DGI#J#K##H####
void preKN(btree *t)  //非递归 将二叉树（孩子兄弟表示）以k叉树形式前序遍历
{
    Stack s;
    initStack(&s);
    while(t!=NULL||isEmptyStack(&s)!=1)
    {
        if(t!=NULL)
        {
            printf("%c",t->data);
            enStack(&s,t);
            t=t->left;
        }
        else
        {
            t=outStack(&s);
            t=t->right;
        }
    }
}
void postKN(btree *t)   //非递归   将二叉树以k叉树形式后序遍历
{   // 二叉树中序非递归遍历
    Stack s;
    initStack(&s);
    while(t!=NULL||isEmptyStack(&s)!=1)
    {
        if(t!=NULL)
        {
            enStack(&s,t);
            t=t->left;
        }
        else
        {
            t=outStack(&s);
            printf("%c",t->data);
            t=t->right;
        }
    }
}
btree* midfindX(btree *t,char x)  //中序非递归遍历，查找值为x的元素
{
    Stack s;
    initStack(&s);
    while(t!=NULL||isEmptyStack(&s)!=1)
    {
        if(t!=NULL)
        {
            enStack(&s,t);
            t=t->left;
        }
        else
        {
            t=outStack(&s);
            if(t!=NULL&&t->data==x)
                return t;
            t=t->right;
        }
    }
    return NULL;
}

void preFirstNode(btree *t)  //输出二叉树前序遍历首点
{
    if(t==NULL)
        return;
    printf("%c\n",t->data);
}
void preLastNode(btree *t)  //输出二叉树前序遍历尾点
{
    if(t==NULL)
        return;
    while(t->left!=NULL||t->right!=NULL)
    {
        if(t->right!=NULL)
            t=t->right;
        else
            t=t->left;
    }
    printf("%c\n",t->data);
}

void midFirstNode(btree *t)  //中序遍历首点
{
    if(t==NULL)
        return;
    while(t->left!=NULL)
        t=t->left;
    printf("%c\n",t->data);
}
void midLastNode(btree *t)  //中序遍历尾点
{
    if(t==NULL)
        return;
    while(t->right!=NULL)
        t=t->right;
    printf("%c\n",t->data);
}
void postFirstNode(btree *t)  //后序遍历首点
{
    if(t==NULL)
        return;
    while(t->left!=NULL||t->right!=NULL)
    {
        if(t->left!=NULL)
            t=t->left;
        else
            t=t->right;
    }
    printf("%c\n",t->data);
}
void postLastNode(btree *t)  //后序遍历尾点
{
    if(t==NULL)
        return;
    printf("%c\n",t->data);
}
int main()
{
    btree *t;
    t=createBtree();
    pre(t);
    printf("\n");
    // mid(t);
    // printf("\n");
    // post(t);
    // printf("\n");
    // level(t);
    // printf("\n");
    // printf("%c\n",findX(t,'B')->data);
    // printf("%c\n",findXParent(t,'B')->data);
    // printf("%d\n",count_0(t));
    // printf("%d\n",count_1(t));
    // printf("%d\n",count_2(t));
    // printf("%d\n",btreeHeight(t));
    printf("%d\n",xHeight(t,'H'));
    // swap(t);
    // pre(t);
    // preKN(t);
    // printf("%c",midfindX(t,'A')->data);
    // preFirstNode(t);
    // preLastNode(t);
    // midFirstNode(t);
    // midLastNode(t);
    // postFirstNode(t);
    // postLastNode(t);
    return 0;
}