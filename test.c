#include<stdio.h>
#include<stdlib.h>
int main()
{

   int i,j,k;
   k=5; //levels

   for(i=0;i<k;i=++i)
   {
       for(j=0;j<2*k;++j)
       {
           if(j==(k-4*i) || j ==(k+4*i))
            printf("*");
            else
                printf("\t");
       }
       printf("\n");
   }

   return 0;
}
