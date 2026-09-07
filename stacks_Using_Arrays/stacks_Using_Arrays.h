#ifndef STACK_A_H
#define STACK_A_H

// STD //
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

// Structure //
typedef struct {
  int* data;
  int size;
  int capacity;
} a_stack ;

// Functions //
// Initializing stack.
a_stack* init_a_stack(void);
// USAGE:
//      a_stack* <name_of_stack> = init_a_stack();
// IMPORTANT: Always run free_a_stack(<name_of_stack>); for every instance of a_stack.
//
// freeing OR De-allocating stack.
void free_a_stack(a_stack* stack);
// USAGE:
//      free_a_stack(<name_of_stack>);

// CORE OPERATIONS.
// ADD a value to the stack.
void push_a_stack(int value, a_stack* stack);
// USAGE:
//      push_a_stack(<Value>, <name_of_stack>);
//
// removes and returns the 'TOP' value of the stack.
int pop_a_stack(a_stack* stack);
// USAGE:
//      pop_a_stack(<name_of_stack>);
//
// returns the 'TOP' va;ue of stack.
int peek_a_stack(a_stack* stack);
// USAGE:
//      peek_a_stack(<name_of_stack>);

// Utils.
// returns true if no element is present in stack otherwise returns false.
bool is_a_stack_empty(a_stack* stack);
// USAGE:
//      is_a_stack_empty(<name_of_stack>);
//
// returns size OR number of element in the stack.
int size_a_stack(a_stack* stack);
// USAGE:
//      size_a_stack(<name_of_stack>);

// IMPLEMENTATION //

a_stack* init_a_stack(void)
{
  a_stack* temp = (a_stack*)malloc(sizeof(a_stack));
  if (temp == NULL) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  temp->data = (int*)malloc(sizeof(int) * 1);
  temp->capacity = 1;
  temp->size = 0;

  return temp;
}

void free_a_stack(a_stack* stack)
{
  if (stack == NULL) {
    printf("Stack is not initialized.\n");
    return;
  }
  if (stack->data == NULL){
    printf("Stacks Data is not initialized.\n");
    return;
  }
  free(stack->data);
  stack->data = NULL;
  free(stack);
  stack = NULL;
}

void push_a_stack(int value, a_stack* stack)
{
  if (stack == NULL) {
    printf("Stack is not initialized.\n");
    return;
  }
  if (stack->data == NULL)
  {
    stack->data = (int*)malloc(sizeof(int) * 1);
    if (stack->data == NULL)
    {
      printf("ERROR:    Memory allocation failed.\n");
      return;
    }
    stack->capacity = 1;
  }
  if (stack->size == stack->capacity)
  {
    int* temp_data = realloc(stack->data,2 * stack->capacity * sizeof(int));
    if (temp_data == NULL) {
      printf("EROOR:    Memory allocation failed.\n");
      free(temp_data);
      return;
    }
    stack->capacity *= 2;
    stack->data[stack->size] = value;
    stack->size++;
    return;
  }
  stack->data[stack->size] = value;
  stack->size++;
}

int pop_a_stack(a_stack* stack)
{
  if (stack == NULL || stack->data == NULL) {
    printf("Stack is not initialized.\n");
    return -1;
  }
  int temp_top = -1;
  if (stack->size > 0)
  {
    temp_top = stack->data[stack->size - 1];
    stack->data[stack->size - 1] = 0;
    stack->size--;
  }
  return temp_top;
}

int peek_a_stack(a_stack* stack)
{
  if (stack == NULL || stack->data == NULL) {
    printf("Stack is not initialized.\n");
    return -1;
  }
  int temp_top = -1;
  if (stack->size > 0)
  {
    temp_top = stack->data[stack->size - 1];
  }
  return temp_top;
}

bool is_a_stack_empty(a_stack* stack)
{
  if (stack == NULL || stack->data == NULL) {
    printf("Stack is not initialized.\n");
    exit(1);
  }
  switch (stack->size) {
    case 0:
      return true;
      break;
    default:
      return false;
  }
}

int size_a_stack(a_stack* stack)
{
  if (stack == NULL || stack->data == NULL) {
    printf("Stack is not initialized.\n");
    exit(1);
  }
  return stack->size;
}

#endif
