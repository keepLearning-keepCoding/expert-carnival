// pnt_add.c  -- 指针地址  （程序清单10.8)
#include<stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti=dates;  // 把数组地址赋给指针
    ptf=bills;

    printf("bytes occupied by short is %zd\nbytes occupied by double is %zd\n",sizeof(short),sizeof(double));
    /*
     * printf里的数字表示最小字段宽度
     */
    printf("%23s  %15s\n","short","double");
    for(index=0;index<SIZE;index++)
        /* 在C中，指针加1指的是增加一个存储单元，对数组而言，这意味着加1后的地址是下一个元素的地址，
         * 而非下一个字节的地址，这是为什么必须声明指针所指向对象类型的原因之一。
         */
        printf("pointers + %d: %10p %10p\n",index,pti+index,ptf+index);
}