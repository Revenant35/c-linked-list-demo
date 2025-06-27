#include "../include/doubly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

static DoublyLinkedNode *create_doubly_linked_node(
    void *data
) {
    DoublyLinkedNode *node = malloc(sizeof(DoublyLinkedNode));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

static DoublyLinkedNode *get_index_doubly_linked_list(
    const DoublyLinkedList *list,
    const unsigned long long index
) {
    if (list->head == NULL || list->size == 0) {
        return NULL;
    }

    DoublyLinkedNode *current = list->head;
    for (unsigned long long i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) {
            return NULL;
        }
    }

    return current;
}

DoublyLinkedList *create_doubly_linked_list() {
    return malloc(sizeof(DoublyLinkedList));
}

void destroy_doubly_linked_list(
    DoublyLinkedList *list
) {
    free(list);
}

int insert_at_head_doubly_linked_list(
    DoublyLinkedList *list,
    void *data
) {
    DoublyLinkedNode *new_node = create_doubly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    if (list->head == NULL || list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return 0;
    }

    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
    list->size++;

    return 0;
}

int insert_at_tail_doubly_linked_list(
    DoublyLinkedList *list,
    void *data
) {
    DoublyLinkedNode *new_node = create_doubly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    if (list->tail == NULL || list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return 0;
    }

    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;

    return 0;
}

int insert_at_index_doubly_linked_list(
    DoublyLinkedList *list,
    void *data,
    const unsigned long long index
) {
    if (index > list->size) {
        return -1;
    }

    if (index == 0) {
        return insert_at_head_doubly_linked_list(list, data);
    }

    if (index == list->size) {
        return insert_at_tail_doubly_linked_list(list, data);
    }

    DoublyLinkedNode *node = get_index_doubly_linked_list(list, index);
    if (node == NULL) {
        return -1;
    }

    DoublyLinkedNode *new_node = create_doubly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    new_node->prev = node->prev;
    new_node->next = node;
    node->prev->next = new_node;
    node->prev = new_node;
    list->size++;

    return 0;
}

void *peek_head_doubly_linked_list(
    const DoublyLinkedList *list
) {
    return list->head != NULL ? list->head->data : NULL;
}

void *peek_tail_doubly_linked_list(
    const DoublyLinkedList *list
) {
    return list->tail != NULL ? list->tail->data : NULL;
}

void *peek_index_doubly_linked_list(
    const DoublyLinkedList *list,
    const unsigned long long index
) {
    const DoublyLinkedNode *tail = get_index_doubly_linked_list(list, index);

    return tail != NULL ? tail->data : NULL;
}

void *remove_head_doubly_linked_list(
    DoublyLinkedList *list
) {
    if (list->head == NULL || list->size == 0) {
        return NULL;
    }

    DoublyLinkedNode *node = list->head;
    void *data = node->data;

    list->head = node->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    list->size--;
    free(node);

    return data;
}

void *remove_tail_doubly_linked_list(
    DoublyLinkedList *list
) {
    if (list->tail == NULL || list->size == 0) {
        return NULL;
    }

    DoublyLinkedNode *node = list->tail;
    void *data = node->data;

    list->tail = node->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    list->size--;
    free(node);

    return data;
}

void *remove_index_doubly_linked_list(DoublyLinkedList *list, const unsigned long long index) {
    if (index >= list->size) {
        return NULL;
    }

    if (index == 0) {
        return remove_head_doubly_linked_list(list);
    }

    if (index == list->size - 1) {
        return remove_tail_doubly_linked_list(list);
    }

    DoublyLinkedNode *node = get_index_doubly_linked_list(list, index);
    if (node == NULL) {
        return NULL;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    list->size--;

    void *data = node->data;
    free(node);

    return data;
}

void print_doubly_linked_list(
    const DoublyLinkedList *list,
    void (*print)(void *data)
) {
    const DoublyLinkedNode *current = list->head;
    if (current != NULL) {
        while (current->next != NULL) {
            print(current->data);
            current = current->next;

            if (current->next != NULL) {
                printf(" <-> ");
            }
        }
    }

    printf("\n");
}