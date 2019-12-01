

#include<iostream>

using namespace std; 

struct treeNo
{
    int data;
    treeNo *left;
    treeNo *right;
};

treeNo *Insert(treeNo *node,int data)
{
    if(node==NULL)
    {
        treeNo *temp;
        temp=new treeNo;
//temp = (treeNode *)malloc(sizeof(treeNode));
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    /* Else there is nothing to do as the data is already in the tree. */
    return node;
}
treeNo* FindMin(treeNo *node)
{
    if(node==NULL)
    {
        /* There is no element in the tree */
        return NULL;
    }
    if(node->left) /* Go to the left sub tree to find the min element */
        return FindMin(node->left);
    else
        return node;
}
void Inorder(treeNo *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}
treeNo * Delet(treeNo *node, int data)
{
    treeNo *temp;
    if(node==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < node->data)
    {
        node->left = Delet(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delet(node->right, data);
    }
    else
    {
        /* Now We can delete this node and replace with either minimum element
        in the right sub tree or maximum element in the left subtree */
        if(node->right && node->left)
        {
            /* Here we will replace with minimum element in the right sub tree */
            temp = FindMin(node->right);
            node -> data = temp->data;
            /* As we replaced it with some other node, we have to delete that node */
            node -> right = Delet(node->right,temp->data);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); /* temp is longer required */
        }
    }
    return node;
}
treeNo * Find(treeNo *node, int data)
{
    if(node==NULL)
    {
        /* Element is not found */
        return NULL;
    }
    if(data > node->data)
    {
        /* Search in the right sub tree. */
        return Find(node->right,data);
    }
    else if(data < node->data)
    {
        /* Search in the left sub tree. */
        return Find(node->left,data);
    }
    else
    {
        /* Element Found */
        return node;
    }
}

int main()
{
    treeNo *root = NULL,*temp;
    int ch;
    //clrscr();
    while(1)
    {
       cout<<"\n1.Insertion\n2.Deletion\n3.Searching\n4.Exit\n";
        cout<<"Enter ur choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter element to be insert:";
            cin>>ch;
            root = Insert(root, ch);
            cout<<"\nElements in BST are:";
            Inorder(root);
            break;
        case 2:
            cout<<"\nEnter element to be deleted:";
            cin>>ch;
            root = Delet(root,ch);
            cout<<"\nAfter deletion elements in BST are:";
            Inorder(root);
            break;
       case 3:
            cout<<"\nEnter element to be searched:";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"Element not found";
            }
            else
            {
                cout<<"Element "<<temp->data<<" is Found\n";
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\nEnter correct choice:";
            break;
        }
    }
    return 0;
}   
