#include "doubly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

static DoublyLinkedNode *create_doubly_linked_node(
    void *data
) {
    DoublyLinkedNode *node = malloc(sizeof(DoublyLinkedNode));
    if (node != NULL) {
        node->data = data;
        node->next = nullptr;
        node->prev = nullptr;
    }
    return node;
}

static DoublyLinkedNode *get_index_doubly_linked_list(
    const DoublyLinkedList *list,
    const unsigned long long index
) {
    if (list->head == NULL || list->size == 0) {
        return nullptr;
    }

    auto current = list->head;
    for (unsigned long long i = 0; i < index; i++) {
        current = current->next;
        if (current == NULL) {
            return nullptr;
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
    const auto new_node = create_doubly_linked_node(data);
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
    const auto new_node = create_doubly_linked_node(data);
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

    const auto node = get_index_doubly_linked_list(list, index);
    if (node == NULL) {
        return -1;
    }

    const auto new_node = create_doubly_linked_node(data);
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
    return list->head != NULL ? list->head->data : nullptr;
}

void *peek_tail_doubly_linked_list(
    const DoublyLinkedList *list
) {
    return list->tail != NULL ? list->tail->data : nullptr;
}

void *peek_index_doubly_linked_list(
    const DoublyLinkedList *list,
    const unsigned long long index
) {
    const auto tail = get_index_doubly_linked_list(list, index);

    return tail != NULL ? tail->data : nullptr;
}

void *remove_head_doubly_linked_list(
    DoublyLinkedList *list
) {
    if (list->head == NULL) {
        return nullptr;
    }

    const auto node = list->head;
    list->head = list->head->next;
    list->size--;

    const auto data = node->data;
    free(node);

    return data;
}

void *remove_tail_doubly_linked_list(
    DoublyLinkedList *list
) {
    if (list->tail == NULL) {
        return nullptr;
    }

    const auto node = list->tail;
    list->tail = list->tail->prev;
    list->size--;

    const auto data = node->data;
    free(node);

    return data;
}

void *remove_index_doubly_linked_list(DoublyLinkedList *list, const unsigned long long index) {
    const auto before_node = get_index_doubly_linked_list(list, index - 1);

    if (before_node == NULL) {
        return nullptr;
    }

    const auto node = before_node->next;
    before_node->next = before_node->next->next;
    list->size--;

    const auto data = node->data;
    free(node);

    return data;
}

void print_doubly_linked_list(
    const DoublyLinkedList *list,
    void (*print)(void *data)
) {
    auto current = list->head;
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