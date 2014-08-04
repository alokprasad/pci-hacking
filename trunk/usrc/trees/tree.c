#include <stdio.h>
#include <stdlib.h>
	
struct node {
	int data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node * NODE;

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

void count_nodes(NODE root)
{
	int count;

	if(root != NULL) {
		count_nodes(root->llink);
		count++;
		count_nodes(root->rlink);
	}
	printf("Number of nodes in the tree are: %d",  count);
}

void count_leaf(NODE root)
{
	int count;

	if (root != NULL) {
		count_nodes(root->llink);
		if ((root->llink == NULL) && (root->rlink == NULL)) {
			count++;
		}
		count_nodes(root->rlink);
	}
	printf("Number of leaves in the tree are: %d", count);
}

int count_height(NODE root)
{
	if (root == NULL)
		return 0;
	
	//return (1 + max(count_height(root->llink), count_height(root->rlink)));
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
	int choice, sum;
	NODE root = NULL;

	printf("\t\t TREES PROGRAM \n");
	while(1) {
		printf("\n 1.INSERT \n 2.INORDER \n 3.PREORDER \n 4.POSTORDER"
			 "\n 5.COUNT NODES \n 6.COUNT_LEAF \n 7.COUNT HEIGHT \n 8.EXIT \n");
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
				count_nodes(root);
				break;

			case 6: if (root == NULL) {
					printf("List is empty \n");
					break;
				}
				count_leaf(root);
				break;			
			
			case 7: sum = count_height(root);
				printf("The height of the tree is : %d \n", sum);
				break;
		
			default: exit(0);	
		}
	}
}
