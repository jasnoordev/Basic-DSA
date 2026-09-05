#ifndef F_STACK_LL_H
#define F_STACK_LL_H

// STD //
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

// STRUCTURES //
typedef struct ll_node{
  int data;
  struct ll_node* bottom;
} ll_node ;

typedef struct {
  ll_node* NODE;
  int size;
  int capacity;
} FIXED_LL_STACK ;

// FUNCTIONS //
// Initializing the stack pointer with given capacity and Returning it.
FIXED_LL_STACK* init_fixed_ll_stack(int capacity);
// USAGE:
//      FIXED_LL_STACK* <name_of_stack> = init_fixed_ll_stack(<Capacity_of_stack>);
// IMPORTANT: Always run 'free_fixed_ll_stack(<name_of_stack>);' at the end of the program for each instance of an FIXED_LL_STACK.
//
// Initializing the stack pointer with given capacity and the first 'TOP' element then Returning it.
FIXED_LL_STACK* init_stack_element(int capacity, int value);
// USAGE:
//      FIXED_LL_STACK* <name_of_stack> = init_fixed_ll_stack_element(<Capacity_of_stack>, <Value_of_element>);
// IMPORTANT: Always run 'free_fixed_ll_stack(<name_of_stack>);' at the end of the program for each instance of an FIXED_LL_STACK.
//
// Freeing OR De-allocating the hole stack.
void free_fixed_ll_stack(FIXED_LL_STACK* stack);
// USAGE:
//      free_fixed_ll_stack(<name_of_stack>);

// CORE OPERATIONS. //
// Add a element to the stack.
void push_fixed_ll_stack(FIXED_LL_STACK** stack, int value);
// USAGE:
//      push_fixed_ll_stack(&<name_of_stack>, <Value_of_element>);
//
// Removes and Returns the 'TOP' element in stack.
int pop_fixed_ll_stack(FIXED_LL_STACK** stack);
// USAGE:
//      pop_fixed_ll_stack(&<name_of_stack>);
//
// Returns the value of 'TOP' element in stack.
int peek_fixed_ll_stack(FIXED_LL_STACK* stack);
// USAGE:
//      peek_fixed_ll_stack(<name_of_stack>);

// UTILS.
// Returns 'True' if stack is empty OR there is no element in stack otherwise Returns 'False'
bool is_fixed_ll_stack_empty(FIXED_LL_STACK* stack);
// USAGE:
//      is_fixed_ll_stack_empty(<name_of_stack>);
//
// Returns the size OR number of elements in the stack.
int fixed_ll_stack_size(FIXED_LL_STACK* stack);
// USAGE:
//      fixed_ll_stack_size(<name_of_stack>);
//
// Returns 'True' if stack is full OR size = capacity of given stack otherwise Returns 'False'.
bool is_fixed_ll_stack_full(FIXED_LL_STACK *stack);
// USAGE:
//      is_fixed_ll_stack_full(<name_of_stack>);


// IMPLIMENTATION //

FIXED_LL_STACK* init_fixed_ll_stack(int capacity){
  FIXED_LL_STACK* temp = (FIXED_LL_STACK*)malloc(sizeof(FIXED_LL_STACK));
  if (!temp) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }
  
  temp->size = 0;
  temp->capacity = capacity;
  return temp;
}

FIXED_LL_STACK* init_fixed_ll_stack_element(int capacity, int value){
  ll_node* temp = (ll_node*)malloc(sizeof(ll_node));
  if (!temp) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }
  temp->bottom = NULL;
  temp->data = value;
  
  FIXED_LL_STACK* stack = (FIXED_LL_STACK*)malloc(sizeof(FIXED_LL_STACK));
  if (stack == NULL) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  stack->NODE = temp;
  stack->capacity = capacity;
  stack->size++;
  return stack;
}

void free_fixed_ll_stack(FIXED_LL_STACK* stack){
  if (is_fixed_ll_stack_empty(stack)) {
    free(stack);
    stack = NULL;
  } else if (stack->NODE != NULL) {
    free(stack->NODE);
    free(stack);
    stack = NULL;
    return;
  }
}

// CORE OPERATIONS //
void push_fixed_ll_stack(FIXED_LL_STACK **stack, int value){
  if ((*stack)->size == (*stack)->capacity) {
    printf("Stack is full!\nValue '%d' is discarded.\n",value);
    return;
  }
  ll_node* temp = (ll_node*)malloc(sizeof(ll_node));
  if (temp == NULL) {
    printf("ERROR:      Memory Allocation failed.\n");
    exit(1);
  }

  temp->data = value;
  temp->bottom = (*stack)->NODE;
  (*stack)->size++;

  (*stack)->NODE = temp;
}

int pop_fixed_ll_stack(FIXED_LL_STACK **stack){
  if (stack == NULL || *stack == NULL) {
    printf("ERROR:      Stack is not initialized.\n");
    exit(1);
  }

  ll_node* temp = (*stack)->NODE;
  if (temp == NULL) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  int data = temp->data;

  if ((*stack)->NODE->bottom != NULL) {
    (*stack)->NODE = (*stack)->NODE->bottom;
  } else {
    *stack = NULL;
  }
  free(temp);
  
  return data;
}

int peek_fixed_ll_stack(FIXED_LL_STACK *stack){
  if (is_fixed_ll_stack_empty(stack)) {
    printf("ERROR:      Stack is Empty.\n");
    return -1;
  }
  return stack->NODE->data;
}

// UTILS //
bool is_fixed_ll_stack_empty(FIXED_LL_STACK *stack){
  if (stack->NODE == NULL && stack->size == 0) {
    return true;
  }
  return false;
}

int fixed_ll_stack_size(FIXED_LL_STACK *stack){
  if (is_fixed_ll_stack_empty(stack)) {
    return 0;
  } else {
    return stack->size;
  }
}

bool is_fixed_ll_stack_full(FIXED_LL_STACK* stack){
  if (stack->size == stack->capacity) {
    return true;
  }
  return false;
}

#endif
