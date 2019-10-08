#include<stdio.h>
#include<stdlib.h>

struct node //node declaration for BST
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data) //Empty node
{
    struct node *a;
    a=(struct node*)malloc(sizeof(struct node));
    a->data=data;
    a->left=NULL;
    a->right=NULL;
    return a;
}
struct node* goleft(struct node *root,int add) //Insertion using recursion.
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

}
int main()
{   struct node* start;
    start=createnode(10);
    insert(start,1);
    insert(start,15);
    printf("%d",start->right->data);

    return 0;
}
