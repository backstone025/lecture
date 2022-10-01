#ifndef DDL_MAKER
#define DDL_MAKER

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
	struct node* prev;
}node;

typedef struct ll {
	int len;
	struct node* head;
	struct node* tail;
}ll;

void add(ll* list, int pos, int value);
void remove(ll* list, int pos);

#endif
