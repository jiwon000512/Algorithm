#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int data)
{
    if (!(*root))
    {
        struct node *tmp_root = new struct node;
        (*tmp_root).data = data;
        *root = tmp_root;
    }

    if ((**root).data > data)
    {
        insert(&(**root).left, data);
    }
    else if ((**root).data < data)
    {
        insert(&(**root).right, data);
    }
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        cout << (*root).data << ' ';
        preOrder((*root).left);
        preOrder((*root).right);
    }
}

void inOrder(struct node *root)
{
    if (!root)
        return;
    else
    {
        inOrder((*root).left);
        cout << (*root).data << ' ';
        inOrder((*root).right);
    }
}

void postOrder(struct node *root)
{
    if (!root)
        return;
    else
    {
        postOrder((*root).left);
        postOrder((*root).right);
        cout << (*root).data << ' ';
    }
}

int size(struct node *root)
{
    if (!root)
        return 0;
    else
        return size(root->left) + size(root->right) + 1;
}

int height(struct node *root)
{
    if (!root)
        return -1;
    else
    {
        int leftHeight, rightHeigt;
        leftHeight = height(root->left);
        rightHeigt = height(root->right);
        return 1 + (leftHeight >= rightHeigt ? leftHeight : rightHeigt);
    }
}

int sumOfWeight(struct node *root)
{
    if (!root)
        return 0;
    else
        return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data;
}

int maxPathWeight(struct node *root)
{
    if (!root)
        return 0;
    else
    {
        int leftWeight, rightWeight;
        leftWeight = maxPathWeight(root->left);
        rightWeight = maxPathWeight(root->right);
        return root->data + (leftWeight >= rightWeight ? leftWeight : rightWeight);
    }
}

void mirror(struct node **root)
{
    if (!(*root))
        return;
    struct node *tmp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = tmp;
    mirror(&(*root)->left);
    mirror(&(*root)->right);
}

void destruct(struct node **root)
{
    if (!(*root))
        return;
    *root = NULL;
}

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--)
    {
        int num, i;
        struct node *root = NULL;
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data;
            scanf("%d", &data);
            insert(&root, data);
        }
        printf("%d\n", size(root));
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root));
        printf("%d\n", maxPathWeight(root));
        mirror(&root);
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        destruct(&root);
        if (root == NULL)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}