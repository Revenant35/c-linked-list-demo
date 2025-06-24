#include "singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

static SinglyLinkedNode *create_singly_linked_node(
    void *data
) {
    SinglyLinkedNode *node = malloc(sizeof(SinglyLinkedNode));
    if (node != NULL) {
        node->data = data;
        node->next = nullptr;
    }
    return node;
}

static SinglyLinkedNode *get_index_singly_linked_list(
    const SinglyLinkedList *list,
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

static SinglyLinkedNode *get_tail_singly_linked_list(
    const SinglyLinkedList *list
) {
    auto current = list->head;
    if (current == NULL) {
        return nullptr;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

SinglyLinkedList *create_singly_linked_list() {
    return malloc(sizeof(SinglyLinkedList));
}

void destroy_singly_linked_list(
    SinglyLinkedList *list
) {
    free(list);
}

int insert_at_head_singly_linked_list(
    SinglyLinkedList *list,
    void *data
) {
    const auto new_node = create_singly_linked_node(data);
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
    const auto new_node = create_singly_linked_node(data);
    if (new_node == NULL) {
        return -1;
    }

    const auto tail = get_tail_singly_linked_list(list);

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

    const auto previous_node = get_index_singly_linked_list(list, index - 1);
    if (previous_node == NULL) {
        return -1;
    }

    const auto new_node = create_singly_linked_node(data);
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
    return list->head != NULL ? list->head->data : nullptr;
}

void *peek_tail_singly_linked_list(
    const SinglyLinkedList *list
) {
    const auto tail = get_tail_singly_linked_list(list);

    return tail != NULL ? tail->data : nullptr;
}

void *peek_index_singly_linked_list(
    const SinglyLinkedList *list,
    const unsigned long long index
) {
    const auto tail = get_index_singly_linked_list(list, index);

    return tail != NULL ? tail->data : nullptr;
}

void *remove_head_singly_linked_list(
    SinglyLinkedList *list
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

void *remove_tail_singly_linked_list(
    SinglyLinkedList *list
) {
    const auto before_tail = get_index_singly_linked_list(list, list->size - 2);

    if (before_tail == NULL) {
        return nullptr;
    }

    const auto tail = before_tail->next;
    before_tail->next = nullptr;
    list->size--;

    const auto data = tail->data;
    free(tail);

    return data;
}

void *remove_index_singly_linked_list(
    SinglyLinkedList *list,
    const unsigned long long index
) {
    const auto before_node = get_index_singly_linked_list(list, index - 1);

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

void print_singly_linked_list(
    const SinglyLinkedList *list,
    void (*print)(void *data)
) {
    auto current = list->head;
    if (current != NULL) {
        while (current->next != NULL) {
            print(current->data);
            current = current->next;

            if (current->next != NULL) {
                printf(" -> ");
            }
        }
    }

    printf("\n");
}
