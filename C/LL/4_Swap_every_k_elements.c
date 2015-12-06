/* You are given a linked list and a parameter k.
 * You will have to swap values in a certain fashion,
 * swap value of node 1 with node k,
 * then node (k+1) with node 2k
 * and go on doing this in the similar fashion. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node* next;
};

void insert(struct node** head_ref, int data);
void print_list(struct node* head_ref);
void swap(struct node** old, struct node** new);
void shift_list(struct node **head_ref, int k);

int main() {
	struct node* head = NULL;
	int i, r, length = 20, k = 3;
	srand(clock());
	for (i = 0; i < length; i++) {
		r = (int) rand();
		r = (r % 150);
		insert(&head, r);
	}
	print_list(head);
//	printf("%d",head->data);
	shift_list(&head, k);
	print_list(head);
	return 0;
}

void shift_list(struct node **head_ref, int k) {
	struct node* old = *head_ref, *new = *head_ref;
	int i;
	for (; new != NULL && old != NULL;) {
		for (i = 0,new=old; i < k && new != NULL; i++) {
			new = new->next;
		}
		if (new != NULL) {
//			printf("Swapping OLD:%d\tNew:%d\n",old->data,new->data);
			swap(&old, &new);
			old = new->next;
		}
	}
}

void swap(struct node** old, struct node** new) {
	int temp;
	temp = (*old)->data;
	(*old)->data = (*new)->data;
	(*new)->data = temp;
}

void insert(struct node** head_ref, int data) {
	struct node* new = (struct node*) malloc(sizeof(struct node));
	struct node* traverse = NULL;
	new->data = data;
	new->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = new;
	} else {
		for (traverse = *head_ref; traverse->next != NULL;traverse = traverse->next);
		traverse->next = new;
	}
}

void print_list(struct node* head_ref) {
	if (head_ref == NULL) {
		return;
	}
	struct node* traverse = NULL;
	int i;
	for (i = 0, traverse = head_ref; traverse != NULL;i++, traverse = traverse->next) {
		printf("Node: %d\tValue:%d\n", i, traverse->data);
	}
}
