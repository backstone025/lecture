#ifndef NODE_MAKER
#define NODE_MAKER

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next = (node*)malloc(sizeof(node));
}node;

#endif#pragma once
