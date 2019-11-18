#include<stdio.h>
#include<stdlib.h>

struct node //node declaration
{
    int data;
    struct node *next;
};

struct node* createnode()
{
    int i;
    struct node *a;
    a=(struct node*)malloc(sizeof(struct node));
    printf("Enter the first element of the list\n");
    scanf("%d",&i);
    a->data=i;
    a->next=NULL;

    return a;
}
struct node* push(struct node *start,int add)    //function that returns pointer to node.(adding at start)
{

    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=add;
    if(start==NULL)
    {
        t->next=NULL;
        return t;
    }
    t->next=start;
    start=t;
    //start stores value of temp (pointer)
    printf("%d pushed!\n",add);
    return start;
}
struct node* pop(struct node* start)
{
    struct node* temp;
    temp=start->next;
    printf("%d popped!\n",start->data);
    free(start);
    return temp;
}
void display(struct node* start)
{
    struct node *p;
    p=start;
    printf("Stack :- ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int x,choice;
struct node* start = NULL;
int main()
{
    printf("\n\t STACK OPERATIONS USING LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf(" Enter a value to be pushed:");
                scanf("%d",&x);
                start=push(start,x);
                break;
            }
            case 2:
            {
                start=pop(start);
                break;
            }
            case 3:
            {
                display(start);
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(choice!=4);
    return 0;
}

