#ifndef FIXED_STACK_A_H
#define FIXED_STACK_A_H

// STD //
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct fixed_stack_a {
  int* data;
  int size;
  int capacity;
} fixed_stack_a ;

// FUNCTIONS //
// Initializing the stack pointer with a given capacity and Returning it.
fixed_stack_a* init_fixed_stack(int size);
// USAGE:
//      stack* <name_of_stack> = init_stack();
// IMPORTANT: Always run 'free_fixed_stack(<name_of_stack>);' at the end of the program for each instance of an fixed_stack_a.
//
// Freeing OR De-allocating the given stack
void free_fixed_stack(fixed_stack_a* stack);

// CORE OPERATIONS.
// Add the value to the stack.
void push_fixed_stack(fixed_stack_a* stack, int value);
// USAGE:
//      push_fixed_stack(<Address_of_stack>,<Value_of_element>);
//
// Removes and Returns the 'TOP' element in stack.
int pop_fixed_stack(fixed_stack_a* stack);
// USAGE:
//      pop_fixed_stack(<Address_of_stack>);
//
// Returns the value of 'TOP' element in stack.
int peek_fixed_stack(fixed_stack_a* stack);
// USAGE:
//      peek_fixed_stack(<Address_of_stack>);

// UTILS.
// Returns 'True' if stack is empty PO there is no element in stack otherwise Returns 'False'
bool is_fixed_stack_empty(fixed_stack_a* stack);
// USAGE:
//      is_fixed_stack_empty(<Address_of_stack>);
//
// Returns the size OR number_of_element in the stack
int fixed_stack_size(fixed_stack_a* stack);
//
// Returns 'True' if stack is full OR number_of_element = capacity_of_stack otherwise Returns 'False'
bool is_fixed_stack_full(fixed_stack_a* stack);
// USAGE:
//      is_fixed_stack_full(<Address_of_stack>);

// IMPLIMENTATION //

fixed_stack_a* init_fixed_stack(int size){
  fixed_stack_a* temp = (fixed_stack_a*)malloc(sizeof(fixed_stack_a));
  if (temp == NULL) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  int* arr = (int*)malloc(sizeof(int) * size);
  if (arr == NULL) {
    printf("ERROR:      Memory allocation Failed.\n");
    exit(1);
  }
  temp->data = arr;

  temp->capacity = size;
  temp->size = 0;

  return temp;
}

void free_fixed_stack(fixed_stack_a* stack){
  if (stack != NULL && stack->data != NULL){
    free(stack->data);
    stack->data = NULL;
    free(stack);
    stack = NULL;
  } else {
    return;
  }
}

// CORE OPRATIONS.
void push_fixed_stack(fixed_stack_a *stack, int value){
  if (stack == NULL) {
    printf("ERROR:      Stack is not initialized.\n");
    exit(2);
  }

  if (stack->size >= 0 && !is_fixed_stack_full(stack)) {
    stack->data[stack->size] = value;
    stack->size++;
  } else {
    printf("Warning:    Stack is full.\n\
            Value '%d' is discarded.\n",value);
    return;
  }
}

int pop_fixed_stack(fixed_stack_a *stack){
  if (stack == NULL){
    printf("ERROR:      Stack is not initialized.\n");
    exit(2);
  }
  int temp = -1;
  if (stack->size != 0 || stack->size > 0) {
    int temp = stack->data[stack->size-1];
    stack->data[stack->size-1] = 0;
    stack->size--;
  }

  return temp;
}

int peek_fixed_stack(fixed_stack_a *stack){
  if (stack == NULL){
    printf("ERROR:      Stack is not initialized.\n");
    exit(2);
  }
  int temp = 0;
  if (stack->size > 0) {
    int temp = stack->data[stack->size-1];
    return temp;
  }
  return temp;
}

// UIILS.
bool is_fixed_stack_empty(fixed_stack_a *stack){
  if (stack == NULL){
    printf("Error:      Stack is not initialized.\n");
    exit(2);
  }
  switch (stack->size) {
    case 0:
      return true;
      break;
    default:
      return false;
  }
}

int fixed_stack_size(fixed_stack_a *stack){
  if (is_fixed_stack_empty(stack)) {
    return 0;
  } else {
    return stack->size;
  }
}

bool is_fixed_stack_full(fixed_stack_a *stack){
  if (stack == NULL) {
    printf("ERROR:      Stack is not initialized.\n");
    exit(2);
  }
  if (stack->size == stack->capacity) {
    return true;
  }
  return false;
}
#endif
