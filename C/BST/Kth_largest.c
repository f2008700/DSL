/*
 * BT_Kth_largest.c
 *
 *  Created on: 04-Dec-2015
 *      Author: vikas
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void create_tree(struct node** root_ref, int data);
void create_tree_wrapper(struct node** root_ref);
void print_tree(struct node* root);
void K_largest(struct node *root, int k);
void K_largest_util(struct node *root, int k, int *c);

int main() {
	struct node *root=NULL;
	create_tree_wrapper(&root);

//	int i, r, length = 20;
//	srand(clock());
//	for (i = 0; i < length; i++) {
//		r = (int) rand();
//		r = r % 40;
//		printf("%d ", r);
//		create_tree(&root, r);
//	}
	printf("\n");
	print_tree(root);
	printf("\n");
	K_largest(root,9);
	return 0;
}

void K_largest(struct node *root, int k){
	int c=0;
	K_largest_util(root, k, &c);
}

void K_largest_util(struct node *root, int k, int *c){
	if(root==NULL || *c>k) return;

	K_largest_util(root->right, k, c);
	(*c)++;

	if(*c==k){
		printf("\n%d",root->data);
	}
	K_largest_util(root->left, k, c);
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


void create_tree_wrapper(struct node** root_ref){
	create_tree(root_ref, 50);
	create_tree(root_ref, 30);
	create_tree(root_ref, 20);
	create_tree(root_ref, 40);
	create_tree(root_ref, 70);
	create_tree(root_ref, 60);
	create_tree(root_ref, 80);
}
void create_tree(struct node** root_ref, int data) {
	struct node* new = (struct node*) malloc(sizeof(struct node));
	struct node* traverse = NULL;
	new->data = data;
	new->left = new->right = NULL;
	if (*root_ref == NULL ) {
		*root_ref = new;
	} else {
		for (traverse = *root_ref;;) {
			if (data < traverse->data) {
				if (traverse->left != NULL ) {
					traverse = traverse->left;
				} else {
					traverse->left = new;
					break;
				}
			} else {
				if (traverse->right != NULL ) {
					traverse = traverse->right;
				} else {
					traverse->right = new;
					break;
				}
			}
		}
	}
}
