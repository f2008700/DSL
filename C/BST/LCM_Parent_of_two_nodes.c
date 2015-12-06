/*
 * Set4_R2_Q1.c
 *
 *  Created on: 29-Aug-2015
 *      Author: vikas
 *
 *  Given a Binary tree and two nodes.
 *  Need to find the minimum ancestor, no parent nodes given.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

void create_tree(struct node **root_ref, int data);
void print_inorder(struct node* root_ref);
bool is_present(struct node* root_ref, int data);
int common_ancestor(struct node* root_ref, int data1, int data2);
void swap(int *a, int *b);

int main(){
	struct node *root=NULL;
	int i,l=10,r;
	srand(clock());
	for(i=0;i<l;i++){
		r=(int)rand();
		r=r%100;
		create_tree(&root,r);
	}
	printf("Print Inorder traversal\n");
	print_inorder(root);
	printf("\n");
	r=24;
	bool is_bool=is_present(root->left, r);
	if(is_bool){
		printf("Element %d is present!\n",r);
	}else{
		printf("Not present! %d\n",r);
	}
	printf("Common Ancestor: %d",
			common_ancestor(root,22,27));
	return 0;
}

int common_ancestor(struct node* root_ref, int data1, int data2){
	struct node* traverse;
	if(data1>data2){
		swap(&data1,&data2);
	}
	for(traverse=root_ref;traverse!=NULL;){
		bool left, right;

		left=is_present(traverse->left,data1);
		right=is_present(traverse->right,data2);

		if((left==true && right==true)||
				(traverse->data==data1) ||
				(traverse->data==data2)){
				return traverse->data;
		}else if(left == true){
			// Automatically qualifies that right was false
			traverse=traverse->left;
		}else if(right==true){
			// Automatically qualifies that left was false
			traverse=traverse->right;
		}else{
			// Both left and right false imply that element was not found only
			return -1;
		}
	}
}

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

bool is_present(struct node* root_ref, int data){
	struct node* traverse=root_ref;
	for(;traverse!=NULL;){
		if(data==traverse->data){
			return true;
		}
		if(data < traverse->data){
			traverse=traverse->left;
		}else{
			traverse=traverse->right;
		}
	}
	return false;
}

void print_inorder(struct node* root_ref){
	if(root_ref->left!=NULL){
		print_inorder(root_ref->left);
	}
	printf("%d->",root_ref->data);
	if(root_ref->right!=NULL){
		print_inorder(root_ref->right);
	}
}

void create_tree(struct node **root_ref, int data){
	printf("Inserting: %d\n",data);
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	if(*root_ref==NULL){
		*root_ref=new;
	}else{
		struct node* traverse=*root_ref;
		for(;;){
			if(data<traverse->data){
				if(traverse->left!=NULL){
					traverse=traverse->left;
				}else{
					traverse->left=new;
					break;
				}
			}else{
				if(traverse->right!=NULL){
					traverse=traverse->right;
				}else{
					traverse->right=new;
					break;
				}

			}
		}
	}
}
