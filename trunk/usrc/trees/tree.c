/*
 * 1) Creating a binary tree
 * 2) Traversing the tree using - Preorder, Inorder, Postorder, Level-order
 * 3) Find the number elements in the tree
 * 4) Find the number of leaves in the tree
 * 5) Find the height of the tree
 * 6) search a element in the tree
 */

#include <stdio.h>
#include <stdlib.h>
	
struct node {
	int data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node * NODE;

int count_n, count_l;

NODE getnode()
{
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	return temp;
}

void inorder(NODE root)
{
	if (root != NULL) {
		inorder(root->llink);
		printf("%d ->",root->data);
		inorder(root->rlink);
	}
}

void preorder(NODE root)
{
	if (root != NULL) {
		printf("%d ->",root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}

void postorder(NODE root)
{
	if (root != NULL) {
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d ->",root->data);
	}
}

void printlevel(NODE root, int level)
{
        if (root == NULL)
                return;

        if (level == 1)
                printf(" %d ", root->data);
        else {
                printlevel(root->llink, level - 1);
                printlevel(root->rlink, level - 1);
        }
}

void levelorder(NODE root)
{
	int i, h = count_height(root);

	for (i = 1; i <= h; i++) {
		printf("\n");
		printlevel(root, i);	
	}
}

void count_nodes(NODE root)
{
	if(root != NULL) {
		count_nodes(root->llink);
		count_n++;
		count_nodes(root->rlink);
	}
}

void count_leaf(NODE root)
{
	if (root != NULL) {
		count_leaf(root->llink);
		if ((root->llink == NULL) && (root->rlink == NULL)) {
			count_l++;
		}
		count_leaf(root->rlink);
	}
}

int count_height(NODE root)
{
	int lheight = 0, rheight = 0;

	if (root->llink != NULL)
		lheight = count_height(root->llink);
	if (root->rlink != NULL)
		rheight = count_height(root->rlink);

	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}

int tree_search(NODE root, int key)
{
	while (root != NULL) {
		if (key > root->data)
			return tree_search(root->rlink, key);
		else if (key < root->data)
			return tree_search(root->llink, key);
		else
			return 1;
	}
	return 0;
}


NODE insert(NODE root)
{
	int num;
	NODE temp, cur, prev;

	printf("\n Enter the number to insert to the tree:");	
	scanf("%d", &num);
	
	temp = getnode();
	temp->data = num;
	temp->llink = NULL;
	temp->rlink = NULL;
	
	if (root == NULL)
		return temp;

	cur = root;
	prev = NULL;
	while(cur != NULL) {
		prev =cur;
		if (num <= cur->data)
			cur = cur->llink;
		else
			cur = cur->rlink;
	}
	
	if(num < prev->data)
		prev->llink = temp;
	else
		prev->rlink = temp;

	return root;
}

int main()
{
	int choice, sum, key, res;
	NODE root = NULL;

	printf("\t\t TREES PROGRAM \n");
	while(1) {
		printf("\n 1.INSERT \n 2.INORDER \n 3.PREORDER \n 4.POSTORDER \n 5.LEVELORDER"
			 "\n 6.COUNT NODES \n 7.COUNT LEAF \n 8.COUNT HEIGHT \n 9.SEARCH \n 10.EXIT \n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: root = insert(root);
				break;
		
			case 2: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				printf("Inorder traversal is \n");	
				inorder(root);
				break;	
		
			case 3: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				printf("Preorder traversal is \n");	
				preorder(root);
				break;	

			case 4: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				printf("Postorder traversal is \n");	
				postorder(root);
				break;

			case 5: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				printf("Levelorder traversal is \n");
				levelorder(root);
				break;
					
			case 6: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				count_nodes(root);
				printf("Number of nodes in the tree are: %d",  count_n);
				break;

			case 7: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				count_leaf(root);
				printf("Number of leaves in the tree are: %d", count_l);
				break;			
			
			case 8: sum = count_height(root);
				printf("The height of the tree is : %d \n", sum);
				break;
			
			case 9: printf("Enter a key to search \n");
				scanf("%d", &key);
				res = tree_search(root, key);
				
				if (res == 1)
					printf("Element found \n");
				else
					printf("Element not found \n");
				break;
				
			default: exit(0);	
		}
	}
}
