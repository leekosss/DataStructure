#include <stdio.h>

/*  angle_1
  样例：
5  5  5  5  5
4  4  4  4
3  3  3
2  2
1
*/
void angle_1(int n) //打印第一个倒三角
{
    if (n <= 0)
        return; //行数小于等于零就结束
    int i;
    for (i = 0; i < n; i++)
        printf("%-3d", n); //先打印第一行，再打印剩下n-1行
    printf("\n");
    angle_1(n - 1);
}
/*
angle_2  样例：

1  2  3  4  5
   1  2  3  4
      1  2  3
         1  2
            1
*/
void angle_2(int n, int max) //打印第二个倒置三角
{
    if (n > max || n <= 0) //如果n超过了最大长度max则直接结束
        return;
    int i;
    for (i = 1; i <= max - n; i++)
        printf("%-3c", ' '); //先打印空格
    for (i = 1; i <= n; i++)
        printf("%-3d", i); //再打印数字
    printf("\n");
    angle_2(n - 1, max); //先打印第一行，再打印 剩下n-1行
}
/*
angle_3   样例：

   1  2  3  4  5  4  3  2  1  
      1  2  3  4  3  2  1
         1  2  3  2  1
            1  2  1
               1
*/
void angle_3(int n, int max) //打印第三个倒置三角
{
    if (n <= 0 || n > max)
        return;
    int i;
    for (i = 1; i <= max - n; i++)
        printf("%-3c", ' '); 
    for (i = 1; i <= n; i++)
        printf("%-3d", i);
    for (i = n - 1; i >= 1; i--)
        printf("%-3d", i);
    printf("\n");
    angle_3(n - 1, max);  //先打印第一行，再打印剩下n-1行
}
int main()
{
    angle_1(6);
    angle_2(5, 6);
    angle_3(5, 6);
    return 0;
}