/*
 * Set3_IR2_Q1.c
 *
 *  Created on: 26-Jul-2015
 *      Author: vikas
 *
 *  Delete nth node from end of a linked list in a single scan.
 */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node * next;
};

void create_list(struct node** head_ref, int data);
void print_list(struct node* head_ref);
void delete_n_from_end(struct node **head_ref,int n);

int main(){
	struct node* head=NULL;
	int i,r,length=10,n=2;
	srand(clock());
	for(i=0;i<length;i++){
		r=(int)rand();
		r=r%100;
		create_list(&head,r);
	}
	print_list(head);
	delete_n_from_end(&head,n);
	print_list(head);
	return 0;
}

void delete_n_from_end(struct node **head_ref,int n){
	struct node *old, *new,*temp;
	int i=0;
	for(new=*head_ref;i<=n && new!=NULL; i++, new=new->next);
	for(old=*head_ref;new!=NULL;old=old->next, new=new->next);
	temp=old->next;
	old->next=old->next->next;
	free(temp);
}

void print_list(struct node* head_ref){
	struct node* traverse=NULL;
	for(traverse=head_ref;traverse!=NULL;traverse=traverse->next)
		printf("%d ",traverse->data);
	printf("\n");
}

void create_list(struct node** head_ref, int data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new;
		return;
	}
	else{
		struct node* traverse;
		for(traverse=*head_ref;traverse->next!=NULL;traverse=traverse->next);
		traverse->next=new;
	}
}
