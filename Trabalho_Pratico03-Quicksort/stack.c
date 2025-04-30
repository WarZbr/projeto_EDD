 #include <stdio.h>
 #include <stdlib.h>
 #include "stack.h"

 t_stack* stack_create() {
     t_stack *stack = (t_stack*) malloc(sizeof(t_stack));
     if (stack == NULL) {
         return NULL;
     }
     
     stack->top = NULL;
     stack->size = 0;
     
     return stack;
 }

 void stack_destroy(t_stack *stack) {
     if (stack == NULL) {
         return;
     }
     
     t_stack_node *current = stack->top;
     t_stack_node *next;
     
     while (current != NULL) {
         next = current->next;
         free(current);
         current = next;
     }
     
     free(stack);
 }

 int stack_is_empty(t_stack *stack) {
     if (stack == NULL || stack->top == NULL) {
         return 1;
     }
     return 0;
 }
 
 void stack_push(t_stack *stack, int low, int high) {
     if (stack == NULL) {
         return;
     }
     
     t_stack_node *new_node = (t_stack_node*) malloc(sizeof(t_stack_node));
     if (new_node == NULL) {
         return;
     }
     
     new_node->low = low;
     new_node->high = high;
     new_node->next = stack->top;
     
     stack->top = new_node;
     stack->size++;
 }

 int stack_pop(t_stack *stack, int *low, int *high) {
     if (stack == NULL || stack_is_empty(stack)) {
         return 0;
     }
     
     t_stack_node *top_node = stack->top;
     
     *low = top_node->low;
     *high = top_node->high;
     
     stack->top = top_node->next;
     stack->size--;
     
     free(top_node);
     
     return 1;
 }