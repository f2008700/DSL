/* Write a function that returns the length of the longest leaf-to-leaf path in a binary tree. */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void insert(struct node** root_ref, int data);
int depth_Tree();
void inorder(struct node* root_ref);
void print_longest_path(struct node* root_ref);
void print_longest_left_path(struct node* root_ref);
void print_longest_right_path(struct node* root_ref);

int main() {
	struct node *root = NULL;
	int length = 5, i, r;
	srand(clock());
	for (i = 0; i < length; i++) {
		r = (int) rand();
		r = r % 30;
		printf("%d ", r);
		insert(&root, r);
	}
	insert(&root, 10);
	insert(&root, 7);
	insert(&root, 5);
	insert(&root, 6);
	insert(&root, 8);
	insert(&root, 9);
	printf("\n");
	inorder(root);
	printf("\n");
	printf("Node: %d\tDepth:%d\n", root->right->data, depth_Tree(root->right));
	print_longest_path(root);
	return 1;
}

void insert(struct node** root_ref, int data) {
	struct node* new = (struct node*) malloc(sizeof(struct node));
	struct node* traverse = *root_ref;
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	if (*root_ref == NULL) {
		*root_ref = new;
	} else {
		for (; traverse != NULL;) {
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
}

void print_longest_path(struct node* root_ref) {
	printf("Longest leaf to leaf path:\n");
	print_longest_left_path(root_ref->left);
	printf("%d ", root_ref->data);
	print_longest_right_path(root_ref->right);
}

void print_longest_left_path(struct node *root_ref) {
	if (root_ref == NULL)
		return;
	if (root_ref->left != NULL
			&& depth_Tree(root_ref->left) >= depth_Tree(root_ref->right)) {
		print_longest_left_path(root_ref->left);
	} else {
		print_longest_left_path(root_ref->right);
	}
	printf("%d ", root_ref->data);
}

void print_longest_right_path(struct node *root_ref) {
	if (root_ref == NULL)
		return;
	printf("%d ", root_ref->data);
	if (root_ref->left != NULL
			&& depth_Tree(root_ref->left) >= depth_Tree(root_ref->right)) {
		print_longest_right_path(root_ref->left);
	} else {
		print_longest_right_path(root_ref->right);
	}
}

void inorder(struct node* root_ref) {
	if (root_ref->left != NULL) {
		inorder(root_ref->left);
	}
	printf("%d ", root_ref->data);
	if (root_ref->right != NULL) {
		inorder(root_ref->right);
	}
}

int depth_Tree(struct node* node_ref) {
	int left = 0, right = 0;
	if (node_ref == NULL) {
		return 0;
	}
	if (node_ref->left != NULL) {
		left = 1 + depth_Tree(node_ref->left);
	}
	if (node_ref->right != NULL) {
		right = 1 + depth_Tree(node_ref->right);
	}
	if (left > right) {
		return left;
	} else {
		return right;
	}
}
