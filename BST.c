#include<stdio.h>
#include<stdlib.h>

struct node* insert(struct node *root,int add);
struct node* createnode(int data);
struct node* goleft(struct node *root,int add);
struct node* goright(struct node *root, int add);

struct node //node declaration for BST
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* insert(struct node *root,int add)    //function that returns pointer to node.(adding at start)
{
    if(root==NULL)
        return(createnode(add));

    if(add > root->data)
        root->right = goright(root->right,add);
    if(add < root->data)
        root->left=goleft(root->left,add);

    return root;

}
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




//void preorder(struct node* root)
//{
//    printroot(root);
//    printleft(root);
//    printright(root);
//
//}
//void postorder(struct node* root)
//{
//    printleft(root);
//    printright(root);
//    printroot(root);
//}
void traverse(struct node* root,int type)
{
    if(type==0)         //inorder traversal
    {
        printleft(root,type);
        printroot(root);
        printright(root,type);
    }
    if(type==1) //preorder traversal
    {
        printroot(root);
        printleft(root,type);
        printright(root,type);
    }
    if(type==2)     //postorder traversal
    {
        printleft(root,type);
        printright(root,type);
        printroot(root);
    }

}

void printleft(struct node* root,int type)
{
    if(root->left==NULL)
        return;
    else
        traverse(root->left,type);
}
void printright(struct node* root,int type)
{
    if(root->right==NULL)
        return;
    else
        traverse(root->right,type);
}
void printroot(struct node* root)
{
    printf("%d ",root->data);
    return;
}
int main()
    {
    int n,x;
    struct node* start=NULL;
    printf("Enter number of elements you want to add ");
    scanf("%d",&n);
    for(;n>0;--n)
    {
        scanf("%d",&x);
        start=insert(start,x);
    }
    printf("\nInorder traversal ");
    traverse(start,0);
    printf("\nPreorder traversal ");
    traverse(start,1);
    printf("\nPostorder traversal ");
    traverse(start,2);
    printf("\n");
    return 0;
}
