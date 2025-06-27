#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct SinglyLinkedNode {
    void *data;
    struct SinglyLinkedNode *next;
} SinglyLinkedNode;

typedef struct {
    SinglyLinkedNode *head;
    unsigned long long size;
} SinglyLinkedList;

SinglyLinkedList *create_singly_linked_list();
void destroy_singly_linked_list(SinglyLinkedList *list);

int insert_at_head_singly_linked_list(SinglyLinkedList *list, void *data);
int insert_at_tail_singly_linked_list(SinglyLinkedList *list, void *data);
int insert_at_index_singly_linked_list(SinglyLinkedList *list, void *data, unsigned long long index);

void *peek_head_singly_linked_list(const SinglyLinkedList *list);
void *peek_tail_singly_linked_list(const SinglyLinkedList *list);
void *peek_index_singly_linked_list(const SinglyLinkedList *list, unsigned long long index);

void *remove_head_singly_linked_list(SinglyLinkedList *list);
void *remove_tail_singly_linked_list(SinglyLinkedList *list);
void *remove_index_singly_linked_list(SinglyLinkedList *list, unsigned long long index);

void print_singly_linked_list(const SinglyLinkedList *list, void (*print)(void *data));
#endif //SINGLY_LINKED_LIST_H
