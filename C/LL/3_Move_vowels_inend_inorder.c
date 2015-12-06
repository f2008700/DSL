/* Given a linked list containing character in each node,
 * segregate its nodes in such a way that
 * all nodes containing a vowel are moved to the end of the linked list.
 * We will have to maintain the order.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct linkedlist {
	char data;
	struct linkedlist* next;
};

void insert(struct linkedlist **head_ref, char c);
void print_list(struct linkedlist *head_ref);
bool isVowel(struct linkedlist *node);
void shift_vowels(struct linkedlist **head_ref);

int main() {
	struct linkedlist* head = NULL;
	int i, length = 50, r;
	srand(clock());
	for (i = 1; i < length; i++) {
		r = (int) rand();
		r = (r % 26) + 97;
		insert(&head, (char) r);
	}
	printf("Printing original linked list!\n");
	print_list(head);
	shift_vowels(&head);
	printf("Printing new linked list!\n");
	print_list(head);
	return 0;
}

void shift_vowels(struct linkedlist **head_ref) {
	struct linkedlist *traverse = NULL, *Vowel_head = NULL, *Vowel_tail = NULL,
			*Syllable_head = NULL, *Syllable_tail = NULL;
	for (traverse = *head_ref; traverse != NULL; traverse = traverse->next) {
		if (isVowel(traverse)) {
			if (Vowel_head == NULL) {
				Vowel_head = traverse;
				Vowel_tail = traverse;
			} else {
				Vowel_tail->next = traverse;
				Vowel_tail = Vowel_tail->next;
			}
		} else {
			if (Syllable_head == NULL) {
				Syllable_head = traverse;
				Syllable_tail = traverse;
			} else {
				Syllable_tail->next = traverse;
				Syllable_tail = Syllable_tail->next;
			}
		}
	}
		Vowel_tail->next = NULL;
		Syllable_tail->next = NULL;
	if (Syllable_head == NULL) {
		*head_ref = Vowel_head;
	} else {
		*head_ref = Syllable_head;
		Syllable_tail->next = Vowel_head;
	}
}

//TODO and make this algo work!
void shift_vowels2(struct linkedlist **head_ref) {
	struct linkedlist *before_old = NULL, *old = NULL, *new = NULL,
			*temp = NULL;
	for (old = *head_ref, new = old->next;;) {
		if (old == NULL || old->next == NULL)
			return;
		else {
			if (old == (*head_ref)->next) {
				before_old = *head_ref;
			}
			if (!isVowel(old)) {
				before_old = old;
				old = new;
				new = old->next;
				continue;
			} else if (isVowel(old) && !isVowel(new)) {
				if ((*head_ref) == old)
					*head_ref = new;
				temp = new->next;
				new->next = old;
				old->next = temp;
				if (before_old != NULL) {
					before_old->next = new;
					before_old = before_old->next;
				}
				new = old->next;

			} else {
				for (; new->next != NULL && isVowel(new->next); new = new->next)
					;
				temp = new->next;
				new->next = temp->next;
				if ((*head_ref) == old) {
					*head_ref = temp;
					before_old = temp;
				}
//				before_old->next = temp;
				temp->next = old;
//				if (before_old != NULL) {
//					before_old->next = new;
//					before_old = before_old->next;
//				}
			}
		}
	}
}

bool isVowel(struct linkedlist *node) {
	if (node->data == 'a' || node->data == 'e' || node->data == 'i'
			|| node->data == 'o' || node->data == 'u')
		return true;
	else
		return false;
}

void insert(struct linkedlist **head_ref, char c) {
	struct linkedlist *new = (struct linkedlist *) malloc(
			sizeof(struct linkedlist));
	struct linkedlist *traverse;
	new->data = c;
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

void print_list(struct linkedlist *head_ref) {
	if (head_ref == NULL) {
		return;
	} else {
		struct linkedlist* traverse = head_ref;
		for (; traverse != NULL; traverse = traverse->next) {
			printf("%c ", traverse->data);
		}
		printf("\n");
	}
}
