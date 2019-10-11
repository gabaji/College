#include<stdio.h>
#include<stdlib.h>

struct node //node declaration for BST
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data)
{
    struct node *a;
    a=(struct node*)malloc(sizeof(struct node));
    a->data=data;
    a->left=NULL;
    a->right=NULL;
    return a;
}
struct node* goleft(struct node *root,int add)
    {
        if(root==NULL)
        {   struct node* temp;
            temp = createnode(add);

            return temp;
        }
        else
        {
            insert(root->left);
            return root->left;
        }
    }

struct node* goright(struct node *root, int add)
    {
        if(root==NULL)
        {   struct node* temp;
            temp = createnode(add);

            return temp;
        }
        else
            {
                insert(root->right);
                return root->right;
            }
    }


void insert(struct node *root,int add)    //function that returns pointer to node.(adding at start)
{
    if(add > root->data)
        root->right = goright(root->right,add);
    if(add < root->data)
        root->left=goleft(root->left,add);

//    if(root==NULL)
//    struct node *t;
//    t=(struct node*)malloc(sizeof(struct node));
//    t=createnode(add);
//    start=t;    //start stores value of temp (pointer)
//    return start;

}
//struct node* insertend(struct node *start,int d)
//{
//
//    struct node *p;
//    struct node *temp; //node to be added to list in heap memory.
//    temp=(struct node*)malloc(sizeof(struct node));
//
//    p=start;
//    while(p->next!=NULL)    // iterate to the last.
//    {
//        p=p->next;
//    }
//    temp->next=NULL;
//    temp->data=d;
//    p->next=temp;
//    return start;
//}
//

int main()
{   struct node* start;
    start=createnode(10);
    insert(start,1);
    insert(start,15);
    printf("%d",start->right->data);

    return 0;
}
