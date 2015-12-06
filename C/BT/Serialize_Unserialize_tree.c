/*
 * Set5_WT_Q2.c
 *
 *  Created on: 02-Sep-2015
 *      Author: vikas
 *
 *  Methods to serialize & de-serialize a tree,
 *  must complete the below 2 methods.
 *  File serialize (node *root) &
 *  node * deserialize(File f)
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

void create_tree(struct node **root_ref, int data);
void print_inorder(struct node* root_ref);
void serialize(struct node* root_ref, FILE *fp);
void deserialize(struct node** root_ref, FILE *fp);
struct node* newNode(int data);

int main(){
	struct node *root=NULL;
	int i,l=10,r;
	srand(clock());
	for(i=0;i<l;i++){
		r=(int)rand();
		r=r%100;
		create_tree(&root,r);
	}
	printf("Serializing to file:\n");
	print_inorder(root);
	FILE *fp;
	fp=fopen("Set5_WT_Q2.txt","w");
	serialize(root,fp);
	fclose(fp);
	struct node *root2=NULL;
	fp=fopen("Set5_WT_Q2.txt","r");
	deserialize(&root2,fp);
	printf("\nFrom de Serialization to tree:\n");
	print_inorder(root2);
	return 0;
}

void serialize(struct node *root_ref, FILE *fp){
	// If current node is NULL, store marker
	if (root_ref == NULL){
		fprintf(fp, "%d ", -1);
	    return;
	}
	// Else, store current node and recur for its children
	fprintf(fp, "%d ", root_ref->data);
	serialize(root_ref->left, fp);
	serialize(root_ref->right, fp);
}

void deserialize(struct node **root_ref, FILE *fp){
	// Read next item from file. If there are no more items or next
	// item is marker, then return
	int data;
	if (!fscanf(fp, "%d", &data) || data == -1)
		return;

	// Else create node with this item and recur for children
	*root_ref = newNode(data);
	deserialize(&((*root_ref)->left), fp);
	deserialize(&((*root_ref)->right), fp);
}

struct node* newNode(int data){
    struct node* new =(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
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
