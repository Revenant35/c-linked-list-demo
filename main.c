#include <stdio.h>
#include "singly-linked-list.h"
#include "doubly-linked-list.h"

void print ( void *data ) {
    printf("%d", (int)data);
}

void test_singly_linked_list() {
    const auto list = create_singly_linked_list();
    for (int i = 0; i < 10; i++) {
        insert_at_head_singly_linked_list(list, (void*)i);
    }

    printf("Singly Linked List: ");
    print_singly_linked_list(list, &print);

    printf("Removing %d from list\n", (int)remove_head_singly_linked_list(list));

    printf("Singly Linked List: ");
    print_singly_linked_list(list, &print);

    printf("Index 5 of the list is %d\n", (int)peek_index_singly_linked_list(list, 5));

    printf("Adding 0 to the end of the list.\n");
    insert_at_tail_singly_linked_list(list, (void*)0);

    printf("Singly Linked List: ");
    print_singly_linked_list(list, &print);

    printf("Freeing list\n");
    destroy_singly_linked_list(list);
}

void test_doubly_linked_list() {
    const auto list = create_doubly_linked_list();
    for (int i = 0; i < 10; i++) {
        insert_at_head_doubly_linked_list(list, (void*)i);
    }

    printf("Doubly Linked List: ");
    print_doubly_linked_list(list, &print);

    printf("Removing %d from list\n", (int)remove_head_doubly_linked_list(list));

    printf("Doubly Linked List: ");
    print_doubly_linked_list(list, &print);

    printf("Index 5 of the list is %d\n", (int)peek_index_doubly_linked_list(list, 5));

    printf("Adding 0 to the end of the list.\n");
    insert_at_tail_doubly_linked_list(list, (void*)0);

    printf("Doubly Linked List: ");
    print_doubly_linked_list(list, &print);

    printf("Freeing list\n");
    destroy_doubly_linked_list(list);
}

int main(void) {
    printf("\nTesting Singly Linked List\n");
    test_singly_linked_list();
    printf("\nTesting Doubly Linked List\n");
    test_doubly_linked_list();
    return 0;
}