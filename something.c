#include<stdio.h>
#include<stdlib.h>

struct node //node declaration
{
    int data;
    struct node *next;
};

struct node* createnode(int data)
{
    struct node *a;
    a=(struct node*)malloc(sizeof(struct node));
    a->data=data;
    a->next=NULL;
    return a;
}
struct node* insertbegin(struct node *start,int add)    //function that returns pointer to node.(adding at start)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=add;
    t->next=start;
    start=t;    //start stores value of temp (pointer)
    return start;

}

struct node* insertend(struct node *start,int d)
{

    struct node *p;
    struct node *temp; //node to be added to list in heap memory.
    temp=(struct node*)malloc(sizeof(struct node));

    p=start;
    while(p->next!=NULL)    // iterate to the last.
    {
        p=p->next;
    }
    temp->next=NULL;
    temp->data=d;
    p->next=temp;
    return start;
}

void traverse(struct node* start)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
struct node* deleteatstart(struct node* start)
{
    struct node* temp;
    temp=start->next;
    free(start);
    return temp;
}
struct node* deleteatend(struct node* start)
{
    struct node* p;
    if (start == NULL)
        return start;
    p=start;
    while (p->next->next != NULL)
        p=p->next;
    p->next=NULL;
    return start;
    }
int main()
{   struct node* start;
    start=createnode(10);
    start = insertbegin(start,1);
    start = insertend(start,2);
    start = deleteatend(start);
    traverse(start);

    return 0;
}
