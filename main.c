//
//  main.c
//  c语言作业2
//
//  Created by airshiner on 15/12/25.
//  Copyright © 2015年 airshiner. All rights reserved.
//
#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=a+b;
    printf("%d ",c);
    if (c<0) {
        c=-c;
        printf("-");
    }
    if (c>999999)
    {
        printf("%d,%03d,%03d",c/1000000,(c/1000)%1000,c%1000);
    }
    else if (c<=999)
    {
        printf("%d",c);
    }
    else
    {
        printf("%d,%03d",c/1000,c%1000);
    }
    return 0;
}