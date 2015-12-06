/*
 * Set5_WT_Q1.c
 *
 *  Created on: 31-Aug-2015
 *      Author: vikas
 *
 *  Given a linked list, sort without extra space.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node* next;
};

void insert_list(struct node** head_ref, int data);
void print_list(struct node* head_ref);
void sort_list(struct node** head_ref);

int main(){
	struct node* head=NULL;
	int i,l=50,r;
	srand(clock());
	for(i=0;i<l;i++){
		r=(int)rand();
		r=r%500;
		insert_list(&head,r);
	}
	printf("Original list");
	print_list(head);
	sort_list(&head);
	printf("\nSorted list");
	print_list(head);
	return 0;
}

// Create a new list, add elements in it.
void sort_list(struct node** head_ref){
	if( 	(*head_ref==NULL) ||
			((*head_ref)->next==NULL)){
		return;
	}
	struct node *traverse, *inner_traverse,*min,*traverse_in;
	for(traverse=*head_ref;traverse!=NULL;){
		min=traverse;
		// Find the minimum in the list
		for(inner_traverse=traverse;
			inner_traverse->next!=NULL;
			inner_traverse=inner_traverse->next){
			if(min->next->data > inner_traverse->next->data){
				min=inner_traverse;
			}
		}
		// 3. last condition, once all minimum have been extracted
		// from the main list.
		if(traverse->next==NULL){
			min=traverse;
			for(traverse_in=*head_ref;traverse_in->next!=NULL && traverse_in->next->data < min->data;traverse_in=traverse_in->next);
			min->next=traverse_in->next;
			traverse_in->next=min;
//			printf("\nPrinting traverse");
//			print_list(traverse);
//			printf("\nPrinting head");
//			print_list(*head_ref);
			return;
		}
//		printf("Min: %d\n",min->next->data);
		// 1. First entry
		if(traverse==*head_ref){
			*head_ref=min->next;
			min->next=min->next->next;
			(*head_ref)->next=NULL;
//			printf("\nPrinting traverse");
//			print_list(traverse);
//			printf("\nPrinting head");
//			print_list(*head_ref);
		}else{
			// 2. Rest all elements
			for(traverse_in=*head_ref;traverse_in->next!=NULL;traverse_in=traverse_in->next);
			traverse_in->next=min->next;
			min->next=min->next->next;
			traverse_in->next->next=NULL;
//			printf("\nPrinting traverse");
//			print_list(traverse);
//			printf("\nPrinting head");
//			print_list(*head_ref);
		}

	}
}

void print_list(struct node* head_ref){
	struct node* traverse=head_ref;
	printf("\n-----------------------------\n");
	for(;traverse!=NULL;traverse=traverse->next){
		printf("%d->",traverse->data);
	}
	printf("\n");
}

void insert_list(struct node** head_ref, int data){
	struct node* new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->next=NULL;
	struct node* traverse;
	if(*head_ref==NULL){
		*head_ref=new;
		return;
	}
	for(traverse=*head_ref;traverse->next!=NULL;traverse=traverse->next);
	traverse->next=new;
}
