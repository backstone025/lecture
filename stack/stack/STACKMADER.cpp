#include "STACKMADER.h"

void push(ll* list, int value) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;

	if (list->len == 0) {
		new_node->next = NULL;
		list->head = new_node;
	}

	else if (list->len > 0) {
		node* tmp = list->head;
		new_node->next = tmp;
		list->head = new_node;
	}

	(list->len)++;
}

void pop(ll* list) {
	if (list->len == 0) {
		printf("!\n");
		return;
	}
	node* tmp = list->head;
	list->head = tmp->next;
	printf("%d Á¦°Å\n", tmp->value);
	free(tmp);

	(list->len)--;
}

int get_size(ll* list) {
	return list->len;
}

int peek(ll* list) {
	node* tmp = list->head;
	return tmp->value;
}

void show(ll list) {
	node* tmp = list.head;
	printf("\n");

	for (int i = 0; i < list.len; i++) {
		printf("[ %d ]\n", tmp->value);
		tmp = tmp->next;
	}
		printf("\n");
}
