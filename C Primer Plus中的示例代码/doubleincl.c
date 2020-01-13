// doubleincl.c  -- 包含两次头文件
#include <stdio.h>
#include "names.h"
#include "names.h"  // 第二次包含头文件,若把names.h中的#ifndef保护删除后，则程序无法通过编译。

int main()
{
    names winner = {"Less","Ismoor"};
    printf("The winner is %s %s.\n",winner.first,winner.last);
    return 0;
}

