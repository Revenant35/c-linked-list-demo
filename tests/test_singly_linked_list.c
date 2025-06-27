#include <check.h>
#include <stdlib.h>
#include "../include/singly-linked-list.h"

START_TEST(create_singly_linked_list_should_return_empty_list_when_called)
{
    // Arrange & Act
    SinglyLinkedList *list = create_singly_linked_list();

    // Assert
    ck_assert_ptr_nonnull(list);
    ck_assert_ptr_null(list->head);
    ck_assert_uint_eq(list->size, 0);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_head_singly_linked_list_should_add_node_when_list_is_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1;

    // Act
    insert_at_head_singly_linked_list(list, &data1);

    // Assert
    ck_assert_uint_eq(list->size, 1);
    ck_assert_ptr_eq(list->head->data, &data1);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_head_singly_linked_list_should_add_node_when_list_is_not_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2;
    insert_at_head_singly_linked_list(list, &data1);

    // Act
    insert_at_head_singly_linked_list(list, &data2);

    // Assert
    ck_assert_uint_eq(list->size, 2);
    ck_assert_ptr_eq(list->head->data, &data2);
    ck_assert_ptr_eq(list->head->next->data, &data1);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_tail_singly_linked_list_should_add_node_when_list_is_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1;

    // Act
    insert_at_tail_singly_linked_list(list, &data1);

    // Assert
    ck_assert_uint_eq(list->size, 1);
    ck_assert_ptr_eq(list->head->data, &data1);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_tail_singly_linked_list_should_add_node_when_list_is_not_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2;
    insert_at_tail_singly_linked_list(list, &data1);

    // Act
    insert_at_tail_singly_linked_list(list, &data2);

    // Assert
    ck_assert_uint_eq(list->size, 2);
    ck_assert_ptr_eq(list->head->data, &data1);
    ck_assert_ptr_eq(list->head->next->data, &data2);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_index_singly_linked_list_should_add_node_when_index_is_zero_and_list_is_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1;

    // Act
    insert_at_index_singly_linked_list(list, &data1, 0);

    // Assert
    ck_assert_uint_eq(list->size, 1);
    ck_assert_ptr_eq(list->head->data, &data1);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_index_singly_linked_list_should_add_node_at_end_when_index_is_equal_to_size)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2;
    insert_at_index_singly_linked_list(list, &data1, 0);

    // Act
    insert_at_index_singly_linked_list(list, &data2, 1);

    // Assert
    ck_assert_uint_eq(list->size, 2);
    ck_assert_ptr_eq(list->head->next->data, &data2);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_index_singly_linked_list_should_add_node_in_middle_when_index_is_valid)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2, data3 = 3;
    insert_at_tail_singly_linked_list(list, &data1);
    insert_at_tail_singly_linked_list(list, &data2);

    // Act
    insert_at_index_singly_linked_list(list, &data3, 1);

    // Assert
    ck_assert_uint_eq(list->size, 3);
    ck_assert_ptr_eq(list->head->data, &data1);
    ck_assert_ptr_eq(list->head->next->data, &data3);
    ck_assert_ptr_eq(list->head->next->next->data, &data2);
    
    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(insert_at_index_singly_linked_list_should_return_error_when_index_is_out_of_bounds)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1;

    // Act
    const int result = insert_at_index_singly_linked_list(list, &data1, 5);

    // Assert
    ck_assert_int_eq(result, -1);
    ck_assert_uint_eq(list->size, 0);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

// Test cases for peeking
START_TEST(peek_should_return_null_when_list_is_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();

    // Act & Assert
    ck_assert_ptr_null(peek_head_singly_linked_list(list));
    ck_assert_ptr_null(peek_tail_singly_linked_list(list));
    ck_assert_ptr_null(peek_index_singly_linked_list(list, 0));
    
    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(peek_should_return_value_when_list_is_not_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2;
    insert_at_head_singly_linked_list(list, &data1);
    insert_at_tail_singly_linked_list(list, &data2);

    // Act & Assert
    ck_assert_ptr_eq(peek_head_singly_linked_list(list), &data1);
    ck_assert_ptr_eq(peek_tail_singly_linked_list(list), &data2);
    ck_assert_ptr_eq(peek_index_singly_linked_list(list, 0), &data1);
    ck_assert_ptr_eq(peek_index_singly_linked_list(list, 1), &data2);
    ck_assert_ptr_null(peek_index_singly_linked_list(list, 2));
    
    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(remove_head_singly_linked_list_should_return_null_when_list_is_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();

    // Act
    const void *removed_data = remove_head_singly_linked_list(list);

    // Assert
    ck_assert_ptr_null(removed_data);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(remove_head_singly_linked_list_should_remove_head_when_list_is_not_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2;
    insert_at_head_singly_linked_list(list, &data2);
    insert_at_head_singly_linked_list(list, &data1);

    // Act
    const void *removed_data = remove_head_singly_linked_list(list);

    // Assert
    ck_assert_ptr_eq(removed_data, &data1);
    ck_assert_uint_eq(list->size, 1);
    ck_assert_ptr_eq(list->head->data, &data2);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(remove_tail_singly_linked_list_should_return_null_when_list_is_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();

    // Act
    const void *removed_data = remove_tail_singly_linked_list(list);

    // Assert
    ck_assert_ptr_null(removed_data);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(remove_tail_singly_linked_list_should_remove_tail_when_list_is_not_empty)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2;
    insert_at_head_singly_linked_list(list, &data2);
    insert_at_head_singly_linked_list(list, &data1);

    // Act
    const void *removed_data = remove_tail_singly_linked_list(list);

    // Assert
    ck_assert_ptr_eq(removed_data, &data2);
    ck_assert_uint_eq(list->size, 1);
    ck_assert_ptr_null(list->head->next);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(remove_index_singly_linked_list_should_return_null_when_index_is_out_of_bounds)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();

    // Act
    const void *removed_data = remove_index_singly_linked_list(list, 0);

    // Assert
    ck_assert_ptr_null(removed_data);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

START_TEST(remove_index_singly_linked_list_should_remove_node_when_index_is_valid)
{
    // Arrange
    SinglyLinkedList *list = create_singly_linked_list();
    int data1 = 1, data2 = 2, data3 = 3;
    insert_at_tail_singly_linked_list(list, &data1);
    insert_at_tail_singly_linked_list(list, &data2);
    insert_at_tail_singly_linked_list(list, &data3);

    // Act
    const void *removed_data = remove_index_singly_linked_list(list, 1);

    // Assert
    ck_assert_ptr_eq(removed_data, &data2);
    ck_assert_uint_eq(list->size, 2);
    ck_assert_ptr_eq(list->head->data, &data1);
    ck_assert_ptr_eq(list->head->next->data, &data3);

    // Cleanup
    destroy_singly_linked_list(list);
}
END_TEST

Suite *singly_linked_list_suite(void)
{
    Suite *s = suite_create("SinglyLinkedList");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, create_singly_linked_list_should_return_empty_list_when_called);
    tcase_add_test(tc_core, insert_at_head_singly_linked_list_should_add_node_when_list_is_empty);
    tcase_add_test(tc_core, insert_at_head_singly_linked_list_should_add_node_when_list_is_not_empty);
    tcase_add_test(tc_core, insert_at_tail_singly_linked_list_should_add_node_when_list_is_empty);
    tcase_add_test(tc_core, insert_at_tail_singly_linked_list_should_add_node_when_list_is_not_empty);
    tcase_add_test(tc_core, insert_at_index_singly_linked_list_should_add_node_when_index_is_zero_and_list_is_empty);
    tcase_add_test(tc_core, insert_at_index_singly_linked_list_should_add_node_at_end_when_index_is_equal_to_size);
    tcase_add_test(tc_core, insert_at_index_singly_linked_list_should_add_node_in_middle_when_index_is_valid);
    tcase_add_test(tc_core, insert_at_index_singly_linked_list_should_return_error_when_index_is_out_of_bounds);
    tcase_add_test(tc_core, peek_should_return_null_when_list_is_empty);
    tcase_add_test(tc_core, peek_should_return_value_when_list_is_not_empty);
    tcase_add_test(tc_core, remove_head_singly_linked_list_should_return_null_when_list_is_empty);
    tcase_add_test(tc_core, remove_head_singly_linked_list_should_remove_head_when_list_is_not_empty);
    tcase_add_test(tc_core, remove_tail_singly_linked_list_should_return_null_when_list_is_empty);
    tcase_add_test(tc_core, remove_tail_singly_linked_list_should_remove_tail_when_list_is_not_empty);
    tcase_add_test(tc_core, remove_index_singly_linked_list_should_return_null_when_index_is_out_of_bounds);
    tcase_add_test(tc_core, remove_index_singly_linked_list_should_remove_node_when_index_is_valid);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    Suite *s = singly_linked_list_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    const int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
