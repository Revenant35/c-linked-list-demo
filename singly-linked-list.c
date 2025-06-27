#include "singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

static SinglyLinkedNode *create_singly_linked_node(
    void *data
) {
    SinglyLinkedNode *node = malloc(sizeof(SinglyLinkedNode));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

static SinglyLinkedNode *get_index_singly_linked_list(
    const SinglyLinkedList *list,
    const unsigned long long index
) {
    if (list->head == NULL || list->size == 0) {
        return NULL;
    }

    SinglyLinkedNode *current = list->head;
    for (unsigned long long i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) {
            return NULL;
        }
    }

    return current;
}

static SinglyLinkedNode *get_tail_singly_linked_list(
    const SinglyLinkedList *list
) {
    SinglyLinkedNode *current = list->head;
    if (current == NULL) {
        return NULL;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

SinglyLinkedList *create_singly_linked_list() {
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

void destroy_singly_linked_list(
    SinglyLinkedList *list
) {
    SinglyLinkedNode *current = list->head;
    while (current != NULL) {
        SinglyLinkedNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int insert_at_head_singly_linked_list(
    SinglyLinkedList *list,
    void *data
) {
    SinglyLinkedNode *new_node = create_singly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return 0;
}

int insert_at_tail_singly_linked_list(
    SinglyLinkedList *list,
    void *data
) {
    SinglyLinkedNode *new_node = create_singly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    SinglyLinkedNode *tail = get_tail_singly_linked_list(list);

    if (tail == NULL) {
        list->head = new_node;
        list->size++;
        return 0;
    }

    tail->next = new_node;
    list->size++;

    return 0;
}

int insert_at_index_singly_linked_list(
    SinglyLinkedList *list,
    void *data,
    const unsigned long long index
) {
    if (index > list->size) {
        return -1;
    }

    if (index == 0) {
        return insert_at_head_singly_linked_list(list, data);
    }

    if (index == list->size) {
        return insert_at_tail_singly_linked_list(list, data);
    }

    SinglyLinkedNode *previous_node = get_index_singly_linked_list(list, index - 1);
    if (previous_node == NULL) {
        return -1;
    }

    SinglyLinkedNode *new_node = create_singly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    new_node->next = previous_node->next;
    previous_node->next = new_node;
    list->size++;

    return 0;
}

void *peek_head_singly_linked_list(
    const SinglyLinkedList *list
) {
    return list->head != NULL ? list->head->data : NULL;
}

void *peek_tail_singly_linked_list(
    const SinglyLinkedList *list
) {
    SinglyLinkedNode *tail = get_tail_singly_linked_list(list);

    return tail != NULL ? tail->data : NULL;
}

void *peek_index_singly_linked_list(
    const SinglyLinkedList *list,
    const unsigned long long index
) {
    const SinglyLinkedNode *tail = get_index_singly_linked_list(list, index);

    return tail != NULL ? tail->data : NULL;
}

void *remove_head_singly_linked_list(
    SinglyLinkedList *list
) {
    if (list->head == NULL) {
        return NULL;
    }

    SinglyLinkedNode *node = list->head;
    void *data = node->data;

    list->head = list->head->next;
    list->size--;
    free(node);

    return data;
}

void *remove_tail_singly_linked_list(
    SinglyLinkedList *list
) {
    if (list->head == NULL) {
        return NULL;
    }

    if (list->head->next == NULL) {
        return remove_head_singly_linked_list(list);
    }

    SinglyLinkedNode *before_tail = get_index_singly_linked_list(list, list->size - 2);
    SinglyLinkedNode *tail = before_tail->next;

    void *data = tail->data;
    before_tail->next = NULL;
    free(tail);
    list->size--;

    return data;
}

void *remove_index_singly_linked_list(
    SinglyLinkedList *list,
    const unsigned long long index
) {
    if (index >= list->size) {
        return NULL;
    }

    if (index == 0) {
        return remove_head_singly_linked_list(list);
    }

    if (index == list->size - 1) {
        return remove_tail_singly_linked_list(list);
    }

    SinglyLinkedNode *before_node = get_index_singly_linked_list(list, index - 1);

    SinglyLinkedNode *node = before_node->next;
    void *data = node->data;

    before_node->next = node->next;
    free(node);
    list->size--;

    return data;
}

void print_singly_linked_list(
    const SinglyLinkedList *list,
    void (*print)(void *data)
) {
    SinglyLinkedNode *current = list->head;
    while (current != NULL) {
        print(current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}
