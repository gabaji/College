#include<stdio.h>
#include<stdlib.h>
// Function should be declared before using in c to avoid implicit error.

struct node* rem(struct node* root,int data);
struct node* goleft(struct node *root,int add);
struct node* goright(struct node *root,int add);
struct node* insert(struct node *root,int add);
void inorder(struct node* root);

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
            root=insert(root,add);
            return root;
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
                root=insert(root,add);
                return root;
            }
    }
struct node* insert(struct node *root,int add)    //function that returns pointer to node.(adding at start)
{
    if(root==NULL)
        root=createnode(add);
    else
    {
        if(add > root->data)
            root->right = goright(root->right,add);
        if(add < root->data)
            root->left=goleft(root->left,add);
    }

    return root;

}
void printleft(struct node* root)
{
    if(root->left==NULL)
        return;
    else
        inorder(root->left);
}
void printright(struct node* root)
{
    if(root->right==NULL)
        return;
    else
        inorder(root->right);
}
void printroot(struct node* root)
{
    printf("%d ",root->data);
    return;
}
void inorder(struct node* root) // prints root followed by lift then right child.
{
    if(root==NULL)
        return;
    printleft(root);
    printroot(root);
    printright(root);

}
int min(struct node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root->data;
}

struct node* rem(struct node* root,int data) //returns root after removing data.

{
    if(root==NULL)
        return root;

    if(root->data == data)
    {
        if(root->left == NULL && root->right==NULL)
            return(NULL);
        else
        {
         if(root->right==NULL)
            return root->left;
         if(root->left==NULL)
            return root->right;
         if(root->left != NULL && root->right != NULL)
            {
            root->data=min(root->right);
            root->right=rem(root->right,min(root->right));
            //printf("%d",min(root->right));
            return root;
            }
        }
    }
        else
            {
            if(root->data > data)
                {
                    root->left=rem(root->left,data);
                    return root;
                }
        if(root->data < data)
                {
                    root->right=rem(root->right,data);
                    return root;
                }
            }


}



int main()
{   struct node* start;
    start=NULL;    //inputting the tree.
    int i,x;

    printf("Enter the number of elements you want to add\n");
    scanf("%d",&i);
    printf("Enter %d elements-\n",i);
    for(;i>0;--i)
    {
        scanf("%d",&x);
        start=insert(start,x);
    }
    inorder(start);
    printf("\nEnter the element you want to delete\n");
    scanf("%d",&x);
    start=rem(start,x);
    printf("Hopefully, your element is deleted!\n");
    inorder(start);

    return 0;
}
