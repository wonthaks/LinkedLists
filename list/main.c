#include <stdio.h>
#include <assert.h>

#include "list.h"

void init_test_list(list_t* l) {
  list_add_to_back(l, 3);
  list_add_to_back(l, 10);
  list_add_to_back(l, 15);
}

int main() {
  printf("Tests for linked list implementation\n");
  // Test for regular initialization (adding to and removing from back of the list) and freeing up the list.
  printf("Test one run. \n");
  list_t* test_one = list_alloc();
  init_test_list(test_one);
  list_print(test_one);
  assert(3 == list_length(test_one));
  
  list_remove_from_back(test_one);
  list_print(test_one);
  assert(2 == list_length(test_one));
  list_free(test_one);
  printf("Test one passed. \n");
  
  // Test for adding to and removing from the front of the list.
  printf("Test two run. \n");
  list_t* test_two = list_alloc();
  init_test_list(test_two);
  list_add_to_front(test_two, 1);
  list_print(test_two);
  assert(4 == list_length(test_two));
  
  list_remove_from_front(test_two);
  list_print(test_two);
  assert(3 == list_length(test_two));
  list_free(test_two);
  printf("Test two passed. \n");
  
  // Test for adding to and removing from the specified index of the list (and also out of bound removal).
  printf("Test three run. \n");
  list_t* test_three = list_alloc();
  init_test_list(test_three);
  list_add_at_index(test_three, 20, 1);
  list_print(test_three);
  assert(4 == list_length(test_three));
  
  list_remove_at_index(test_three, -10);
  list_remove_at_index(test_three, 10);
  list_remove_at_index(test_three, 1);
  list_print(test_three);
  assert(3 == list_length(test_three));
  list_free(test_three);
  printf("Test three passed. \n");
  
  // Test for checking if an element is in the list.
  printf("Test four run. \n");
  list_t* test_four = list_alloc();
  init_test_list(test_four);
  assert(1 == list_is_in(test_four, 15));
  assert(0 == list_is_in(test_four, 30));
  list_free(test_four);
  printf("Test four passed. \n");
  
  // Test for getting element at a specific index (and for out of bound indices).
  printf("Test five run. \n");
  list_t* test_five = list_alloc();
  init_test_list(test_five);
  assert(10 == list_get_elem_at(test_five, 1));
  assert(0 == list_get_elem_at(test_five, 10));
  assert(0 == list_get_elem_at(test_five, -1));
  list_free(test_five);
  printf("Test five passed. \n");
  
  // Test for getting the index of the first encountered element of the specified value (and also for non-existent values).
  printf("Test six run. \n");
  list_t* test_six = list_alloc();
  init_test_list(test_six);
  assert(1 == list_get_index_of(test_six, 10));
  assert(-1 == list_get_index_of(test_six, 30));
  list_free(test_six);
  printf("Test six passed. \n");
  return 0;
}