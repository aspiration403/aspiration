#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  struct tree *left;
  int data;
  struct tree *right;
}Btree_t;

void insert(Btree_t **root, int val)
{
  Btree_t *start = *root;
  if (NULL == start)
  {
     start = (Btree_t *)malloc(sizeof(Btree_t));
     start->data = val;
     start ->left = NULL;
     start->right = NULL;
     *root = start; 
  }
  else
  {
    if (start->data > val)
    {
       insert(&(start->right), val);
    }
    else
    {
       insert(&(start->left), val);
    }
  }
}

void inorder(Btree_t *start)
{
  if (start)
  {
    inorder(start->left);
    printf("Data :-- %d \n",start->data);
    inorder(start->right);
  }
}

/*data left right*/
void preorder(Btree_t *start)
{
  if (start)
  {
    printf("Data :-- %d \n",start->data);
    inorder(start->left);
    inorder(start->right);
  }
}
/* left right data*/
void postorder(Btree_t *start)
{
  if (start)
  {
    inorder(start->left);
    inorder(start->right);
    printf("Data :-- %d \n",start->data);
  }
}


int main()
{
  int num, val,i;
  Btree_t *root = NULL;
  printf("\n How many data you want to insert in tree : ");
  scanf("%d",&num);
  printf("\nInsert Element for tree \n");
  for (i = 0; i < num; i++)
  {
     scanf("%d",&val);
     insert(&root, val);
  }

  printf("Data Output :--->INORDER\n");
  inorder(root);
  printf("Data Output :--->PREORDER\n");
  preorder(root);
  printf("Data Output :--->POSTORDER\n");
  postorder(root);
  return 0;
}
