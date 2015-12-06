/*
 * Set5_R2_Q4.c
 *
 *  Created on: 04-Sep-2015
 *      Author: vikas
 *
 *  Write a method to check if a tree is BST or not.
 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* test=NULL;

void create_tree(struct node** root_ref, int data);
void create_tree_wrapper(struct node **root);
void create_binary_tree(struct node** root_ref, int data);
void create_binary_tree_wrapper(struct node **root);
void print_inorder(struct node* root_ref);
void check_bst(struct node* root_ref);

int main(){
	struct node* root;
	create_tree_wrapper(&root);
	print_inorder(root);
	printf("\nChecking now\n");
	check_bst(root);
	root=NULL;
	create_binary_tree_wrapper(&root);
	print_inorder(root);
	printf("\nChecking now\n");
	check_bst(root);
	return 0;
}

// Main implementation.
void check_bst(struct node *root_ref){
	if(root_ref->left!=NULL){
		check_bst(root_ref->left);
	}
	if(root_ref!=NULL){
		if(root_ref->left!=NULL){
			if(root_ref->left->data > root_ref->data){
				printf("Not a BST\n");
				printf("Left Node: %d is greater than its root: %d\n",root_ref->left->data,root_ref->data);
			}
		}
		if(root_ref->right!=NULL){
			if(root_ref->data > root_ref->right->data){
				printf("Not a BST\n");
				printf("Right Node: %d is lesser than its root: %d\n",root_ref->right->data,root_ref->data);
			}
		}
	}
	if(root_ref->right!=NULL){
		check_bst(root_ref->right);
	}
}


// Binary Tree
void create_binary_tree_wrapper(struct node** root_ref){
	create_binary_tree(root_ref,20);
	create_binary_tree(root_ref,45);
	create_binary_tree(root_ref,12);
	create_binary_tree(root_ref,4);
	create_binary_tree(root_ref,56);
	create_binary_tree(root_ref,23);
	create_binary_tree(root_ref,17);
	create_binary_tree(root_ref,5);
	create_binary_tree(root_ref,10);
	create_binary_tree(root_ref,11);
	create_binary_tree(root_ref,45);
	create_binary_tree(root_ref,18);
	create_binary_tree(root_ref,4);
	create_binary_tree(root_ref,8);
	create_binary_tree(root_ref,30);
	create_binary_tree(root_ref,31);
	create_binary_tree(root_ref,51);
	create_binary_tree(root_ref,9);
	create_binary_tree(root_ref,3);
}

void create_binary_tree(struct node** root_ref, int data) {
	struct node* new=(struct node*) malloc(sizeof(struct node));
	struct node* traverse=NULL;
	new->data=data;
	new->left=new->right= NULL;
	if(*root_ref==NULL){
		*root_ref=new;
	}else{
		for(traverse=*root_ref;;){
			if(data<traverse->data){
				if(traverse->left!=NULL){
					traverse = traverse->left;
				}else{
					traverse->left = new;
					break;
				}
			}else{
				if (traverse->right != NULL ) {
					traverse = traverse->right;
				}else{
					traverse->right = new;
					break;
				}
			}
		}
	}
}

// Tree
void create_tree_wrapper(struct node** root){
	create_tree(root,20);
	create_tree(root,45);
	create_tree(root,12);
	create_tree(root,4);
	create_tree(root,56);
	create_tree(root,23);
	create_tree(root,17);
	create_tree(root,5);
	create_tree(root,10);
	create_tree(root,11);
	create_tree(root,45);
	create_tree(root,18);
	create_tree(root,4);
	create_tree(root,8);
	create_tree(root,30);
	create_tree(root,31);
	create_tree(root,51);
	create_tree(root,9);
	create_tree(root,3);
}

void create_tree(struct node** root_ref, int data){
	static int r=0;
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	struct node* traverse;
	if(*root_ref==NULL){
		*root_ref=new;
//		printf("Inserting %d\n",data);
		return;
	}
	for(traverse=*root_ref;;r=(r+3)%10){
//		printf("r: %d\n",r);
		if(r<5){
			if(traverse->left!=NULL){
				traverse=traverse->left;
			}else{
//				printf("Inserting %d on LEFT of %d\n",data,traverse->data);
				traverse->left=new;
				break;
			}
		}else{
			if(traverse->right!=NULL){
				traverse=traverse->right;
			}else{
//				printf("Inserting %d on right of %d\n",data,traverse->data);
				traverse->right=new;
				break;
			}
		}
	}
}

void print_inorder(struct node *root_ref){
	if(root_ref->left!=NULL)
		print_inorder(root_ref->left);
	if(root_ref!=NULL)
		printf("%d->",root_ref->data);
	if(root_ref->right!=NULL)
		print_inorder(root_ref->right);
}


/*
// Implementation 2.
void check_bst(struct node *root_ref){
	if(root_ref->left!=NULL)
		check_bst(root_ref->left);
	if(root_ref!=NULL){
		if(test==NULL){
			test=root_ref;
		}else if(root_ref->data>test->data){
			printf("This is not BST");
			return;
		}else{
			test=root_ref;
		}
	}
	if(root_ref->right!=NULL)
		check_bst(root_ref->right);
}
*/
