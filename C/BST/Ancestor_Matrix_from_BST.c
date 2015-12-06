/*
 * There is a binary tree of size N. All nodes are numbered between 1-N(inclusive).
 * There is a N*N integer matrix Arr[N][N], all elements are initialized to zero.
 * So for all the nodes A and B, put Arr[A][B] = 1 if A is an ancestor of B
 * (NOT just the immediate ancestor).
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct node {
	int data;
	int index;
	struct node* left;
	struct node* right;
};

int count;
void insert(struct node **root_ref, int data);
void inorder(struct node* root_ref);
bool isParent(struct node* parent, struct node* child);
struct node* getNode(struct node* root_ref, int index);

int main() {
	struct node* root = NULL;
	int length = 5, i, r, j;
	int *arr = (int *) malloc(sizeof(int) * length);
	int **final = (int **) malloc(sizeof(int*) * length);
	srand(clock());
	for (i = 0; i < length; i++) {
		r = (int) rand();
		r = r % 30;
		printf("%d ", r);
		arr[i] = r;
		insert(&root, r);
		final[i] = (int *) malloc(sizeof(int) * length);
	}
	printf("\n");
	inorder(root);
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
		if(isParent(getNode(root,i),getNode(root,j))) {
					final[i][j]=1;
			}else {
				final[i][j]=0;
			}
		}
	}
	for(i=0;i<length;i++) {
		for(j=0;j<length;j++) {
			printf("%d ",final[i][j]);
		}
		printf("\n");
	}
	return 1;
}

void insert(struct node **root_ref, int data) {
	struct node* new = (struct node*) malloc(sizeof(struct node));
	struct node* traverse = *root_ref;
	new->data = data;
	new->index = count;
	new->left = NULL;
	new->right = NULL;
	count++;
	if (*root_ref == NULL) {
		*root_ref = new;
		return;
	}
	for (;;) {
		if (data < traverse->data) {
			if (traverse->left == NULL) {
				traverse->left = new;
				break;
			} else {
				traverse = traverse->left;
			}
		} else {
			if (traverse->right == NULL) {
				traverse->right = new;
				break;
			} else {
				traverse = traverse->right;
			}
		}
	}
}

struct node* getNode(struct node* root_ref, int index) {
	struct node* traverse = root_ref;
	struct node* left;
	struct node* right;
	if (traverse == NULL)
		return NULL;
	else if (traverse->index == index) {
		return traverse;
	} else {
		left = getNode(traverse->left, index);
		right = getNode(traverse->right, index);
		if (left == NULL) {
			return right;
		} else {
			return left;
		}
	}
}

bool isParent(struct node* parent, struct node* child) {
	if (parent == NULL || child == NULL || child==parent)
		return false;
	struct node *traverse = parent;
	for (;;) {
		if (traverse == NULL) {
			return false;
		}
		if (child->data == traverse->data) {
			return true;
		} else if (child->data < traverse->data) {
			traverse = traverse->left;
		} else {
			traverse = traverse->right;
		}
	}
}

void inorder(struct node* root_ref) {
	if (root_ref->left != NULL) {
		inorder(root_ref->left);
	}
	if (root_ref != NULL) {
		printf("Node: %d, Index: %d\n", root_ref->data, root_ref->index);
	}
	if (root_ref->right != NULL) {
		inorder(root_ref->right);
	}
}
