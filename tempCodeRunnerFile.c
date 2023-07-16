typedef struct 
// {
//     btree *c[MAX];
//     int f,r;
// }queue;  //队列
// void init(queue *q)  //队列初始化
// {
//     q->f=0;
//     q->r=0;
// }
// int isEmpty(queue *q)  //判断队列是否为空
// {
//     return q->f==q->r?1:0;
// }
// void enQueue(queue *q,btree *x)  //入队
// {
//     q->c[q->r]=x;
//     q->r=(q->r+1)%MAX;
// }
// btree* outQueue(queue *q)  //出队
// {
//     btree *t;
//     t=q->c[q->f];
//     q->f=(q->f+1)%MAX;
//     return t;
// }