#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct DoublyLinkedNode {
    void *data;
    struct DoublyLinkedNode *next;
    struct DoublyLinkedNode *prev;
} DoublyLinkedNode;

typedef struct {
    DoublyLinkedNode *head;
    DoublyLinkedNode *tail;
    unsigned long long size;
} DoublyLinkedList;

DoublyLinkedList *create_doubly_linked_list();
void destroy_doubly_linked_list(DoublyLinkedList *list);

int insert_at_head_doubly_linked_list(DoublyLinkedList *list, void *data);
int insert_at_tail_doubly_linked_list(DoublyLinkedList *list, void *data);
int insert_at_index_doubly_linked_list(DoublyLinkedList *list, void *data, unsigned long long index);

void *peek_head_doubly_linked_list(const DoublyLinkedList *list);
void *peek_tail_doubly_linked_list(const DoublyLinkedList *list);
void *peek_index_doubly_linked_list(const DoublyLinkedList *list, unsigned long long index);

void *remove_head_doubly_linked_list(DoublyLinkedList *list);
void *remove_tail_doubly_linked_list(DoublyLinkedList *list);
void *remove_index_doubly_linked_list(DoublyLinkedList *list, unsigned long long index);

#endif //LINKED_LIST_H
