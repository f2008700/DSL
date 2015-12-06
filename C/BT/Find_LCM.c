/*
 * Set5_R1_Q2.c
 *
 *  Created on: 04-Sep-2015
 *      Author: vikas
 *
 *  Find a lowest common Ancestor, the variation was the tree was just a Binary Tree, not BST.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<stdbool.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void print_inorder(struct node *root_ref);
void create_tree(struct node** root_ref, int data);
bool isPresent_in_tree(struct node *root_ref, int d1);
int LeastCommonAncestor(struct node* root_ref,int d1, int d2);

int main(){
	struct node* root=NULL;
//	int i,r,l=20;
	create_tree(&root,20);
	create_tree(&root,45);
	create_tree(&root,12);
	create_tree(&root,4);
	create_tree(&root,56);
	create_tree(&root,23);
	create_tree(&root,17);
	create_tree(&root,5);
	create_tree(&root,10);
	create_tree(&root,11);
	create_tree(&root,45);
	create_tree(&root,18);
	create_tree(&root,4);
	create_tree(&root,8);
	create_tree(&root,30);
	create_tree(&root,31);
	create_tree(&root,51);
	create_tree(&root,9);
	create_tree(&root,3);
//	srand(clock());
//	for(i=0;i<l;i++){
//		r=(int)rand();
//		r=r%50;
//		create_tree(&root,r);
//	}
	print_inorder(root);
	printf("\n");
	int a=4,b=30;
	printf("Least Common Ancestor of: %d and %d is %d",a,b,LeastCommonAncestor(root,a,b));
	return 0;
}

void print_inorder(struct node *root_ref){
	if(root_ref->left!=NULL)
		print_inorder(root_ref->left);
	if(root_ref!=NULL)
		printf("%d->",root_ref->data);
	if(root_ref->right!=NULL)
		print_inorder(root_ref->right);
}

int LeastCommonAncestor(struct node *root_ref, int d1, int d2){
	if(root_ref==NULL)
		return -1;
	bool left_d1=true, right_d1=true, left_d2=true, right_d2=true;
	struct node *traverse;
	for(traverse=root_ref;;){
		left_d1=isPresent_in_tree(traverse->left,d1);
		right_d1=isPresent_in_tree(traverse->right,d1);
		left_d2=isPresent_in_tree(traverse->left,d2);
		right_d2=isPresent_in_tree(traverse->right,d2);
		if(left_d1 && left_d2 && right_d1 && right_d2){
			return -1;
		}
		if((left_d1&&right_d2)||(right_d1&&left_d2)){
			return traverse->data;
		}
		else if(left_d1&&left_d2){
			if(traverse->data==d1 ||traverse->data==d2){
				return traverse->data;
			}else {
				traverse=traverse->left;
			}
		}else if(right_d1&&right_d2){
			if(traverse->data == d1 ||traverse->data==d2 ){
				return traverse->data;
			}else{
				traverse=traverse->right;
			}
		}else{ // only one of the element was present
			return -1;
		}
	}
	return 0;
}

bool isPresent_in_tree(struct node *root_ref, int d1){
	if(root_ref==NULL){
		return false;
	}else if(root_ref->data==d1){
		return true;
	}
	bool left, right;
	left=isPresent_in_tree(root_ref->left,d1);
	right=isPresent_in_tree(root_ref->right,d1);
	return (left || right);
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
