#ifndef NODE_MAKER
#define NODE_MAKER

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct ll {
    struct node* head;
    int len;
} ll;

#endif#pragma once
