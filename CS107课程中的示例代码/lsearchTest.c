#include<stdio.h>
#include<string.h>  // 函数memcmp声明在这个头文件中
#define ARR_LEN  5
/*
 * 泛型线性搜索
 *  @key  待搜索的元素
 *  @base 数组的基地址
 *  @n 被搜索数组的长度 
 *  @elemSize 待搜索的元素的大小
 */
void *lsearch(void *key,
              void *base,
              int n,
              int elemSize)
{
    for(int i=0;i<n;i++){
        /* elemAddr 遍历到达的当前地址
         *  对空类型的指针base进行强制类型转换，让其指向的数据类型为char,
         *  这样进行指针的运算时，步长为1(因为char为一个字节长)
         */
        void *elemAddr = (char *)base + i*elemSize;
        if(memcmp(key,elemAddr,elemSize) == 0)
            return elemAddr;
    }
    return NULL;
}         
int main()
{   
    double a[ARR_LEN]={
        1.2,
        2.3,
        3.4,
        4.5,
        5.6
    };
    double key=3.4;
    void *addressOfKey=lsearch(&key,a,ARR_LEN,sizeof(double));
    printf("The base address of array is  %p\n",a);
    printf("and the address of the key is %p\n",addressOfKey);
    printf("the bytes occupied by double is %zd\n",sizeof(double));

    return 0;
}