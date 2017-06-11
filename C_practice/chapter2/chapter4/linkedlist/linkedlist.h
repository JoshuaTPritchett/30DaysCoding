#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct {
    struct node next;
    int value;
} node;

typedef node Node;

int add(struct Node *head);
int remove(struct Node *head, int value);
int remove_head(struct Node *head);
int insert_position(struct Node *head, int value, int position);
int get_size(struct Node *head);

#endif
