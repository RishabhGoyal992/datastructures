//deletion of a node from a binary tree


#include<stdio.h>
#include<stdlib.h>
int n;
struct node *tree = NULL;
int a[1000];
int q[1000];
int front = 0;
int rear = 0;

struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *
newnode (int d)
{
  struct node *nn = (struct node *) malloc (sizeof (struct node));
  nn->data = d;
  nn->left = NULL;
  nn->right = NULL;
  return nn;
}

struct node *
inserttree (struct node *r, int i)
{
  if (i < n)
    {
      struct node *temp = newnode (a[i]);
      r = temp;
      r->left = inserttree (r->left, 2 * i + 1);
      r->right = inserttree (r->right, 2 * i + 2);
    }
  return r;
}

void
levelorder (struct node *r)
{
  if (r)
    {
      struct node *temp = r;
      printf ("\n");
      while (temp)
	{
	  if (temp)
	    {
	      printf ("%d ", temp->data);
	      if (temp->left)
		{
		  q[++rear] = temp->left;
		}
	      if (temp->right)
		{
		  q[++rear] = temp->right;
		}
	      temp = q[++front];
	    }
	}
      printf ("\n");
    }
}

void
delnode (int d)
{
  front = 0;
  rear = 0;

  struct node *t1 = tree;
  //t1 will be pointing to the node where d is present
  while (t1)
    {
      if (t1->data == d)
	{
	  break;
	}
      if (t1->left)
	{
	  q[++rear] = t1->left;
	}
      if (t1->right)
	{
	  q[++rear] = t1->right;
	}
      t1 = q[++front];
    }
  front = 0;
  rear = 0;
  struct node *t3 = NULL;
  struct node *t2 = tree;
  //t3 will be pointing to the last node
  while (t2)
    {
      if (t2->left)
	{
	  q[++rear] = t2->left;
	}
      if (t2->right)
	{
	  q[++rear] = t2->right;
	}
      t3 = t2;
      t2 = q[++front];
    }

  front = 0;
  rear = 0;

  int x = t3->data;

  //deleting the last node 

  struct node *t4 = tree;
  front = 0;
  rear = 0;

  while (t4)
    {
      if (t4->left == t3)
	{

	  t4->left = NULL;
	  free (t3);
	  break;
	}

      if (t4->right == t3)
	{

	  t4->right = NULL;
	  free (t3);
	  break;
	}
      if (t4->left)
	{
	  q[++rear] = t4->left;
	}
      if (t4->right)
	{
	  q[++rear] = t4->right;
	}
      t4 = q[++front];

    }

  t1->data = x;
  front = 0;
  rear = 0;

}

void
inorder (struct node *p)
{
  if (p)
    {
      inorder (p->left);
      printf ("%d ", p->data);
      inorder (p->right);
    }
}

void
main ()
{
  printf ("\n\t\tDELETION FROM BINARY TREE\n");
  printf ("\nenter the number of nodes : ");
  scanf ("%d", &n);

  printf ("\nenter the values :\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  struct node *root = NULL;
  root = inserttree (root, 0);
  tree = root;
  printf ("\n inorder traversal : ");
  inorder (root);
  printf ("\nenter the node value you want to delete : ");
  int x;
  scanf ("%d", &x);
  delnode (x);
  printf ("\nAFTER DELETION - INORDER - \n");
  inorder (root);

  return;
}
