#include<stdio.h>
#include<stdlib.h>

void addone(int a)
{
    a=a+1;
}
int main()
{

    int *a;
    a=(int*)malloc(sizeof(int));
    *a=100;



    addone(*a);
    printf("%d",*a);
    return 0;
}
