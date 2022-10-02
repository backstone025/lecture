#ifndef STACKMAKER
#define STACKMAKER
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

typedef struct ll {
	int len;
	struct node* head;
}ll;

void push(ll* list, int value);
void pop(ll* list);
int get_size(ll* list);
int peek(ll* list);
void show(ll list);

#endif

