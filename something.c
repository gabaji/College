#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* addnode(struct node *start,int add)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=add;
    t->next=start;
    start=t;
    return start;

}

void insertatend(struct node *start,int d)
{
    struct node *p;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    temp->next=NULL;
    temp->data=d;
    p->next=temp;
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



int main()
{
    struct node *a;
    a=(struct node*)malloc(sizeof(struct node));
    a->data=10;
    a->next=NULL;
    a=addnode(a,20);
    a=addnode(a,30);
    insertatend(a,100);
    traverse(a);
    return 0;

}
