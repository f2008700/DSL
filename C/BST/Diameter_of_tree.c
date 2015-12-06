/*
 * Set5_R1_Q1.c
 *
 *  Created on: 02-Sep-2015
 *      Author: vikas
 *
 *  Find diameter of a tree.
 *  The diameter of a tree (sometimes called the width) 
 *  is the number of nodes on the longest path between 
 *  two leaves in the tree. 
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void create_tree(struct node** root_ref, int data);
void print_inorder(struct node *root_ref);
int diameter(struct node* root_ref);
int height(struct node* root_ref);
int max(int a, int b);

int main(){
	struct node* root=NULL;
	int i,r,l=20;
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
	printf("Diameter of tree: %d",diameter(root));
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

int diameter(struct node* root_ref){
	if(root_ref==NULL){
		return 0;
	}
	int lh=height(root_ref->left);
	int rh=height(root_ref->right);

	int ld=diameter(root_ref->left);
	int rd=diameter(root_ref->right);

	return max(lh+rh+1, max(ld,rd));
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

int height(struct node* root_ref){
	if(root_ref==NULL){
		return 0;
	}
	return (1+max(height(root_ref->left),height(root_ref->right)));
}

int max(int a, int b){
	return a>=b?a:b;
}
