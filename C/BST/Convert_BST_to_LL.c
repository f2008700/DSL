/*
 * Set6_FF1_Q1.c
 *
 *  Created on: 23-Nov-2015
 *      Author: vikas
 *  Given a Binary Search Tree, in-place convert it to DLL.
 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct lli {
	int data;
	struct lli* next;
};

void insert(struct node** root_ref, int data);
void convert_to_LL(struct node *root_ref, struct lli **ll_ref);
void inorder(struct node* root_ref);

int main() {
	struct node *root=NULL;
	struct lli *ll=NULL;
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
	convert_to_LL(root, &ll);

	struct lli *temp=ll;
	for(;temp!=NULL;temp=temp->next){
		printf("%d ",temp->data);
	}
	printf("\n");

	return 1;
}

void convert_to_LL(struct node *root_ref, struct lli **ll_ref){
	printf("Hello\n");
	if(root_ref->left!=NULL){
		convert_to_LL(root_ref->left, ll_ref);
	}
	struct lli *new=(struct lli *)malloc(sizeof(struct lli));
	new->data=root_ref->data;
	new->next=NULL;
	if(*ll_ref==NULL){
		*ll_ref=new;
	}else{
		struct lli *temp=*ll_ref;
		for(;temp->next!=NULL;temp=temp->next);
		temp->next=new;
	}
	if(root_ref->right!=NULL){
		convert_to_LL(root_ref->right, ll_ref);
	}

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



void inorder(struct node* root_ref) {
	if (root_ref->left != NULL) {
		inorder(root_ref->left);
	}
	printf("%d ", root_ref->data);
	if (root_ref->right != NULL) {
		inorder(root_ref->right);
	}
}
