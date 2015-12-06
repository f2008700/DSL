#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node* next;
	struct node* random;
};
void insert(struct node** head_ref, int n);
void generate_random(struct node** head_ref);
void print_list(struct node* head_ref);
void clone_list(struct node* head_ref, struct node** copy_ref);

int main() {
	struct node* head;
	struct node* head_copy;
	head = NULL;
	head_copy=NULL;
	int i, r, length = 10;
	srand(clock());
	for (i = 0; i < length; i++) {
		r = (int) rand();
		r = r % 1000;
		printf("%d ", r);
		insert(&head, r);
	}
	printf("\n");
	print_list(head);
	generate_random(&head);
	print_list(head);
	clone_list(head,&head_copy);
//	print_list(head_copy);
	return 0;
}

void clone_list(struct node* head_ref, struct node** copy_ref){
	struct node* old=head_ref;
	struct node* old_ref;
	struct node* new=*copy_ref;
	struct node* new_ref;
	for(;old!=NULL;old=old->next){
		insert(copy_ref,old->data);
	}

	printf("Printing the copied list\n");
	print_list(*copy_ref);
	printf("Printing original list\n");
	print_list(head_ref);
	for(old=head_ref,new=*copy_ref;old!=NULL;old=old->next,new=new->next){
		for(old_ref=head_ref,new_ref=*copy_ref;old_ref!=NULL;old_ref=old_ref->next,new_ref=new_ref->next){
			if(old->random==old_ref){
				new->random=new_ref;
			}
		}
	}
	printf("Printing the copied list\n");
	print_list(*copy_ref);
	printf("Printing original list\n");
	print_list(head_ref);

}

void insert(struct node** head_ref, int n) {
	struct node* new = (struct node*) malloc(sizeof(struct node));
	struct node* traverse;
	new->data = n;
	new->next = NULL;
	new->random = NULL;
	if (*head_ref == NULL) {
		*head_ref = new;
	} else {
		for (traverse = *head_ref; traverse->next != NULL;traverse = traverse->next);
		traverse->next = new;
	}
}

void generate_random(struct node** head_ref) {
	int i, r;
	struct node* traverse = *head_ref;
	struct node* trav;
	srand(clock());
	printf("Generating random list!\n");
	for (; traverse != NULL; traverse = traverse->next) {
		r = (int) rand();
		r = r % 10;
		for (i = 0, trav = *head_ref; i < r; i++, trav = trav->next);
		traverse->random = trav;
		if (traverse->next != NULL) {
			printf("Element: %d, next: %d, random: %d", traverse->data, traverse->next->data, traverse->random->data);
		} else {
			printf("Element: %d, next: NULL, random: %d", traverse->data, traverse->random->data);
		}
		printf("\n");
	}
}

void print_list(struct node* head_ref) {
	struct node* traverse = head_ref;
	printf("Printing the list!\n");
	for (; traverse != NULL; traverse = traverse->next) {
		if (traverse->next != NULL && traverse->random != NULL) {
			printf("Element: %d, next: %d, random: %d", traverse->data, traverse->next->data, traverse->random->data);
		} else if (traverse->next != NULL) {
			printf("Element: %d, next: %d, random: NULL", traverse->data, traverse->next->data);
		} else {
			printf("Element: %d, next: NULL, random: NULL", traverse->data);
		}
		printf("\n");
	}
}
