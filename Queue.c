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
    t->next=start;
    start=t;
    //start stores value of temp (pointer)
    printf("%d pushed!\n",add);
    traverse(start);
    return start;
}
void traverse(struct node* start)
{
    struct node *p;
    p=start;
    printf("New linked list :- ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
struct node* pop(struct node* start)
{
    struct node* p;
    if (start == NULL)
        return start;
    p=start;
    while (p->next->next != NULL)
        p=p->next;
    printf("%d popped!\n",p->next->data);
    free(p->next);
    p->next=NULL;
    traverse(start);
    return start;
    }
int main()
{
    printf("Queue implementation using linked list\n\n");
    struct node* a;
    a=createnode(10);
    a=push(a,20);
    a=push(a,30);
    a=push(a,40);
    a=pop(a);
    a=pop(a);
    return 0;
}
