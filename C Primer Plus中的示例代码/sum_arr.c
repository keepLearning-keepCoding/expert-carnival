/* 数组元素之和，用移动指针指向来遍历数组*/
#include<stdio.h>
#define SIZE 10
int sump(int *start,int *end);
int main(void)
{
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer=sump(marbles,marbles+SIZE);
    /* printf中，在%和转换说明符d之间的l为转换说明修饰符，
     * %ld表示long int
     */
    printf("The total number of marbles is %ld.\n",answer);

    return 0;
}
/* 移动指针进行数组求和 */
int sump(int *start,int *end)
{
    int total=0;
    while(start<end)
    {
        total+=*start;  // 把当前项的值加入total变量中
        start++;        // 让指针指向下一个元素
    }
    return total;
}