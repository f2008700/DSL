/*
 * Set3_IR1_Q1.c
 *
 *  Created on: 25-Jul-2015
 *      Author: vikas
 *
 *  You are given two linked lists whose nodes contain a digit as data member.
 *  Both lists represent a number.
 *  You have to add them and return the resultant list.
 *  Input: 9->9->3->4->5 and 8->9->1 (represent 99345 and 891)
 *  Output: 1->0->0->2->3->6
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node* next;
};

void create_list(struct node** head_ref, int length);
void print_list(struct node* head_ref);
struct node** reverse_list(struct node** head_ref);

int main() {
	struct node *arr1 = NULL, *arr2 = NULL;
	int l1 = 10, l2 = 5;
	create_list(&arr1,1);
	create_list(&arr1,3);
	create_list(&arr1,5);
	create_list(&arr1,7);
//	create_list(&arr1,9);
//	create_list(&arr1,11);
//	create_list(&arr1,13);
//	create_list(&arr1,15);
	struct node **temp = reverse_list(&arr1);
	print_list(*temp);
	return 0;
	srand(clock());
	int i, r;
	for (i = 0; i < l1; i++) {
		r = (int) rand();
		r = r % 10;
		printf("%d ", r);
		create_list(&arr1, r);
	}
	print_list(arr1);
	for (i = 0; i < l2; i++) {
		r = (int) rand();
		r = r % 10;
		printf("%d ", r);
		create_list(&arr2, l2);
	}
	print_list(arr2);
	return 0;
}

struct node** reverse_list(struct node** head_ref) {
	if (*head_ref == NULL) {
//		struct node* new=(struct node*)malloc(sizeof(struct node));
//		new->data=15;
		struct node* new_ref = NULL;
		return &new_ref;
	} else {
		struct node* traverse = NULL, *new=NULL, **temp = NULL;
		temp=reverse_list(&((*head_ref)->next));
		new= (struct node*) malloc(sizeof(struct node));
		new->data = (*head_ref)->data;
		new->next = NULL;
		if (*temp == NULL) {
			*temp = new;
		} else {
			for (traverse = *temp; traverse->next != NULL;traverse = traverse->next);
			traverse->next = new;
		}
		new=traverse=NULL;
//		free(new); free(traverse);
		return temp;
	}
}

void print_list(struct node* head_ref) {
	struct node* traverse = head_ref;
	for (; traverse != NULL; traverse = traverse->next) {
		printf("%d ", traverse->data);
	}
	printf("\n");
}

void create_list(struct node** head_ref, int data) {
	struct node* new = NULL, *traverse = NULL;
	new = (struct node*) malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = new;
	} else {
		for (traverse = *head_ref; traverse->next != NULL;
				traverse = traverse->next)
			;
		traverse->next = new;
	}
}
