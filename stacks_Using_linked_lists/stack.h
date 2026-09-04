#ifndef STACK_H
#define STACK_H

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

typedef struct STACK{
  node* NODE;
  int size;
}STACK;

// FUNCTIONS //
// Initializing the stack pointer and Returning it.
STACK* init_stack(void);
// USAGE:
//      STACK* <name_of_stack> = init_stack();
// IMPORTANT: Always run 'free_stack(<name_of_stack>);' at the end of the program for each instance of an STACK.
//
// Initializing the stack pointer with the first 'TOP' element and Returning it.
STACK* init_stack_element(long int value);
// USAGE:
//      STACK* <name_of_stack> = init_stack_element(<Value_of_element>);
// IMPORTANT: Always run 'free_stack(<name_of_stack>);' at the end of the program for each instance of an STACK.
//
// Freeing OR De-allocating the hole stack.
void free_stack(STACK* stack);
// USAGE:
//      free_stack(<name_of_stack>);

// CORE OPERATIONS. //
// Add a element to the stack.
void push_stack(STACK** stack, long int value);
// USAGE:
//      push_stack(&<name_of_stack>, <Value_of_element>);
//
// Removes and Returns the 'TOP' element in stack.
int pop_stack(STACK** stack);
// USAGE:
//      pop_stack(&<name_of_stack>);
//
// Returns the value of 'TOP' element in stack.
int peek_stack(STACK* stack);
// USAGE:
//      peek_stack(<name_of_stack>);

// UTILS.
// Returns 'True' if stack is empty OR there is no element in stack otherwise Returns 'False'
bool is_stack_empty(STACK* stack);
// USAGE:
//      is_stack_empty(<name_of_stack>);
//
// Returns the size OR number of elements in the stack.
int stack_size(STACK* stack);
// USAGE:
//      stack_size(<name_of_stack>);

// IMPLIMENTATION //

STACK* init_stack(void){
  STACK* temp = (STACK*)malloc(sizeof(STACK));
  if (!temp) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  temp->size = 0;
  return temp;
}

STACK* init_stack_element(long int value){
  node* temp = (node*)malloc(sizeof(node));
  if (!temp) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }
  temp->bottom = NULL;
  temp->data = value;
  
  STACK* stack = (STACK*)malloc(sizeof(STACK));
  if (stack == NULL) {
    printf("ERROR:      Memory allocation failed.\n");
    exit(1);
  }

  stack->NODE = temp;
  stack->size++;
  return stack;
}

void free_stack(STACK* stack){
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
void push_stack(STACK **stack, long int value){
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

int pop_stack(STACK **stack){
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

int peek_stack(STACK *stack){
  if (is_stack_empty(stack)) {
    printf("ERROR:      Stack is Empty.\n");
    return -1;
  }
  return stack->NODE->data;
}

// UTILS //
bool is_stack_empty(STACK *stack){
  if (stack == NULL) {
    return true;
  }
  return false;
}

int stack_size(STACK *stack){
  if (is_stack_empty(stack)) {
    return 0;
  } else {
    return stack->size;
  }
}

#endif
