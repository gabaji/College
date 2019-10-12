#include<stdio.h>
#include<stdlib.h>

int main()
{
    int temp,arr[100],i,j,k=0;
    printf("Enter the number of elements\n");
    scanf("%d",&j);
    printf("Enter the elements:-\n");
    for(i=0;i<j;++i)
        scanf("%d",&arr[i]);
    for(i=1;i<=j;++i)
    {
        while(i>k)
        {
            if(arr[i] < arr[k])
            {
                temp = arr[i];
                arr[i]=arr[k];
                arr[k]=temp;

            }
        ++k;
        }
    k=0;
    }
    printf("Sorted array:-\n");

    for(i=0;i<j;++i)
        printf("%d ",arr[i]);

    return 0;

}
