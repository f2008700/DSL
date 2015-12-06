/*
 * Set3_IR1_Q3.c
 *
 *  Created on: 27-Jul-2015
 *      Author: vikas
 *
 *  Two nodes of a BST are given. Print the path from 1st node to the 2nd node.
 *  You are also provided the parent pointers in addition to
 *  normal left and right pointers.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

void create_tree(struct node** root_ref, int data);
void print_tree(struct node* root);
bool isChild(struct node* root_ref, struct node* child);
void Print_Path(struct node* node1, struct node* node2);
void Print_path_root_to_node(struct node* root_ref, struct node* child);

int main() {
	struct node *root;
	int i, r, length = 20;
	srand(clock());
	for (i = 0; i < length; i++) {
		r = (int) rand();
		r = r % 40;
		printf("%d ", r);
		create_tree(&root, r);
	}
	printf("\n");
	print_tree(root);
	printf("\n");
	Print_Path(root->left->left->left, root->right->left);
	printf("\n");
	return 0;
}

void Print_Path(struct node* node1, struct node* node2) {
	if (node1 == NULL || node2 == NULL ) {
		return;
	} else {
		struct node* traverse = node1;
		bool ifChild = false;
		int i = 0;
		for (i = 0; traverse != NULL ; traverse = traverse->parent, i++) {
			printf("%d->", traverse->data);
			ifChild = isChild(traverse, node2);
			if (ifChild == true) {
				if (node2->data < traverse->data)
					Print_path_root_to_node(traverse->left, node2);
				else
					Print_path_root_to_node(traverse->right, node2);
				return;
			}

		}
	}
}

void Print_path_root_to_node(struct node* root_ref, struct node* child) {
	if (root_ref == NULL || child == NULL ) {
		return;
	} else {

		struct node* traverse = root_ref;
		for (; traverse != child;) {
			printf("%d->", traverse->data);
			if (child->data < traverse->data)
				traverse = traverse->left;
			else
				traverse = traverse->right;
		}
		printf("%d\n", child->data);
	}
}

bool isChild(struct node* root_ref, struct node* child) {
	if (root_ref == NULL || child == NULL ) {
		return false;
	} else if (root_ref->data == child->data) {
		return true;
	} else {
		bool left = false, right = false;
		if (root_ref->left != NULL ) {
			left = isChild(root_ref->left, child);
		}
		if (root_ref->right != NULL ) {
			right = isChild(root_ref->right, child);
		}
		if (left == true || right == true) {
			return true;
		} else {
			return false;
		}
	}
}

void print_tree(struct node * root_ref) {
	if (root_ref->left != NULL ) {
		print_tree(root_ref->left);
	}
	printf("%d ", root_ref->data);
	if (root_ref->right != NULL ) {
		print_tree(root_ref->right);
	}
}

void create_tree(struct node** root_ref, int data) {
	struct node* new = (struct node*) malloc(sizeof(struct node));
	struct node* traverse = NULL;
	new->data = data;
	new->left = new->right = new->parent = NULL;
	if (*root_ref == NULL ) {
		*root_ref = new;
	} else {
		for (traverse = *root_ref;;) {
			if (data < traverse->data) {
				if (traverse->left != NULL ) {
					traverse = traverse->left;
				} else {
					traverse->left = new;
					new->parent = traverse;
					break;
				}
			} else {
				if (traverse->right != NULL ) {
					traverse = traverse->right;
				} else {
					traverse->right = new;
					new->parent = traverse;
					break;
				}
			}
		}
	}
}
