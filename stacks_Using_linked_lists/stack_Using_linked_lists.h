#ifndef STACK_LL_H
#define STACK_LL_H

// STD //
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

// STRUCTURES //

typedef struct node{
  int data;
  struct node* bottom;
}node;

typedef struct STACK_LL{
  node* NODE;
  int size;
} STACK_LL ;

// FUNCTIONS //
// Initializing the stack pointer and Returning it.
STACK_LL* init_ll_stack(void);
// USAGE:
//      STACK_LL* <name_of_stack> = init_ll_stack();
// IMPORTANT: Always run 'free_ll_stack(<name_of_stack>);' at the end of the program for each instance of an STACK_LL.
//
// Initializing the stack pointer with the first 'TOP' element and Returning it.
STACK_LL* init_ll_stack_element(int value);
// USAGE:
//      STACK_LL* <name_of_stack> = init_ll_stack_element(<Value_of_element>);
// IMPORTANT: Always run 'free_ll_stack(<name_of_stack>);' at the end of the program for each instance of an STACK_LL.
//
// Freeing OR De-allocating the hole stack.
void free_ll_stack(STACK_LL* stack);
// USAGE:
//      free_ll_stack(<name_of_stack>);

// CORE OPERATIONS. //
// Add a element to the stack.
void push_ll_stack(STACK_LL** stack, int value);
// USAGE:
//      push_ll_stack(&<name_of_stack>, <Value_of_element>);
//
// Removes and Returns the 'TOP' element in stack.
int pop_ll_stack(STACK_LL** stack);
// USAGE:
//      pop_ll_stack(&<name_of_stack>);
//
// Returns the value of 'TOP' element in stack.
int peek_ll_stack(STACK_LL* stack);
// USAGE:
//      peek_ll_stack(<name_of_stack>);

// UTILS.
// Returns 'True' if stack is empty OR there is no element in stack otherwise Returns 'False'
bool is_ll_stack_empty(STACK_LL* stack);
// USAGE:
//      is_ll_stack_empty(<name_of_stack>);
//
// Returns the size OR number of elements in the stack.
int ll_stack_size(STACK_LL* stack);
// USAGE:
//      ll_stack_size(<name_of_stack>);

// IMPLIMENTATION //

STACK_LL* init_ll_stack(void){
  STACK_LL* temp = (STACK_LL*)malloc(sizeof(STACK_LL));
  if (!temp) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  temp->size = 0;
  return temp;
}

STACK_LL* init_ll_stack_element(int value){
  node* temp = (node*)malloc(sizeof(node));
  if (!temp) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }
  temp->bottom = NULL;
  temp->data = value;
  
  STACK_LL* stack = (STACK_LL*)malloc(sizeof(STACK_LL));
  if (stack == NULL) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  stack->NODE = temp;
  stack->size++;
  return stack;
}

void free_ll_stack(STACK_LL* stack){
  if (is_stack_empty(stack)) {
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
void push_ll_stack(STACK_LL** stack, int value){
  node* temp = (node*)malloc(sizeof(node));
  if (temp == NULL) {
    printf("ERROR:      Memory Allocation failed.\n");
    exit(1);
  }

  temp->data = value;
  temp->bottom = (*stack)->NODE;
  (*stack)->size++;

  (*stack)->NODE = temp;
}

int pop_ll_stack(STACK_LL** stack){
  if (stack == NULL || *stack == NULL) {
    exit(1);
  }

  node* temp = (*stack)->NODE;
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

int peek_ll_stack(STACK_LL* stack){
  if (is_ll_stack_empty(stack)) {
    printf("ERROR:      Stack is Empty.\n");
    return -1;
  }
  return stack->NODE->data;
}

// UTILS //
bool is_ll_stack_empty(STACK_LL* stack){
  if (stack == NULL) {
    return true;
  }
  return false;
}

int ll_stack_size(STACK_LL* stack){
  if (is_stack_empty(stack)) {
    return 0;
  } else {
    return stack->size;
  }
}

#endif
