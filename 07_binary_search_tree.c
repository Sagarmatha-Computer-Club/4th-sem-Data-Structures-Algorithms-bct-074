#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root;
//function prototypes
void inorder();
void preorder();
void postorder();
struct node *insert();
struct node *delete (struct node *, int);
struct node *newNode();
struct node *search_leaf(struct node *);

int main()
{
	int choice, data;
	while (1)
	{
		printf("\nEnter your choice: \n");
		printf("\n1.Insert\n2.Traverse\n3.Delete\n4.Exit\n>> ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			{
				printf("\nEnter a number: ");
				scanf("%d", &data);
				if(root==NULL)
				{
					root=newNode(data);
				}
				else
				{
					insert(root,data);
				}
			break;
			case 2:
				printf("\nEnter the choice of traverse: \n");
				printf("\n1.Inorder\n2.Preorder\n3.sPostorder\n\n");
				scanf("%d", &choice);
				switch (choice)
				{
				case 1:
					inorder(root);
					break;
				case 2:
					preorder(root);
					break;
				case 3:
					postorder(root);
					break;
				}
				break;
			case 3:
			{
				printf("Enter value to be deleted: ");
				scanf("%d", &data);
				delete (root, data);
			}
			break;
			case 4: exit(0);
			break;
			}
		}
	}
	return 0;
}

struct node *newNode(int val)//inserting a new node on tree
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insert(struct node *sub_root, int val)//inserting a item or data in tree
{
	struct node *temp;
	temp = sub_root;
	if (sub_root == NULL)
	{
		return newNode(val);
	}
	else if (val < (temp->data))
	{
		sub_root->left = insert(temp->left, val);
	}
	else
	{
		sub_root->right = insert(temp->right, val);
	}
	return temp;
}

void inorder(struct node *sub_root) //traverse in a left, root, right order
{
	if (sub_root != NULL)
	{
		inorder(sub_root->left);
		printf("%d\t", sub_root->data);
		inorder(sub_root->right);
	}
}

void preorder(struct node *sub_root) //traverse in root, left, right order

{
	if (sub_root != NULL)
	{
		printf("%d\t", sub_root->data);
		preorder(sub_root->left);
		preorder(sub_root->right);
	}
}

void postorder(struct node *sub_root) //traverse in left, right, root order
{
	if (sub_root != NULL)
	{
		postorder(sub_root->left);
		postorder(sub_root->right);
		printf("%d\t", sub_root->data);
	}
}
struct node *delete (struct node *sub_root, int value)//deleting a node or a data
{
	struct node *p, *temp;
	temp = sub_root;
	if(root==NULL)
		return NULL;

	if (sub_root->data == value)
	{
		if((sub_root->left==NULL)&&(sub_root->right==NULL))
			return NULL;

		else if((sub_root->left!=NULL)&&(sub_root->right!=NULL))
		{
			p=search_leaf(sub_root);
			sub_root->data=p->data;
		}
		else
		{
			if(sub_root->left==NULL)
				return sub_root->right;

			else
				return sub_root->left;
		}
	}
	else if (sub_root->data > value)
	{
		if (sub_root == NULL)
		{
			printf("\nValue not found.\n");
			return NULL;
		}
		else
		{
			sub_root->left=delete (sub_root->left, value); //searching value to left of the sub root
		}
	}
	else
	{
		if (sub_root == NULL)
		{
			printf("\nValue not found.\n");
			return NULL;
		}
		else
		{
			sub_root->right=delete (sub_root->right, value); //Searching value to right of the sub root
		}
	}
	return sub_root;
}
struct node *search_leaf(struct node *sub_root) //searching a left most value of right node
{
	struct node *temp;
	if (sub_root->left==NULL)
	{
		temp->data=sub_root->data;
		delete(sub_root,sub_root->data);
		return temp;
	}
	else
	{
		return search_leaf(sub_root->left);
	}
}