 #ifndef STACK_H
 #define STACK_H
 
 typedef struct stack_node {
     int low;                 
     int high;                
     struct stack_node *next;  
 } t_stack_node;
 
 typedef struct stack {
     t_stack_node *top;     
     int size;               
 } t_stack;
 
 t_stack* stack_create();                 
 void stack_destroy(t_stack *stack);     
 int stack_is_empty(t_stack *stack);      
 void stack_push(t_stack *stack, int low, int high);  
 int stack_pop(t_stack *stack, int *low, int *high);  
 
 #endif 