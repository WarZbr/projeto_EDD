 #include <stdio.h>
 #include "stack.h"
 #include "quicksort.h"
 
 void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

 int partition(int arr[], int low, int high) {
     int pivot = arr[high];  
     int i = low - 1;        
     
     for (int j = low; j < high; j++) {
         if (arr[j] <= pivot) {
             i++;   
             swap(&arr[i], &arr[j]);
         }
     }
     swap(&arr[i + 1], &arr[high]);
     
     return i + 1; 
 }

 void quicksort_iterative(int arr[], int n) {
     t_stack *stack = stack_create();
     
     int low = 0;
     int high = n - 1;
     
     stack_push(stack, low, high);
     
     while (!stack_is_empty(stack)) {
         stack_pop(stack, &low, &high);
         int pivot_pos = partition(arr, low, high);

         if (pivot_pos - low > 0) {
             int left_size = pivot_pos - low;

             if (high - pivot_pos > 0) {
                 int right_size = high - pivot_pos;

                 if (left_size > right_size) {
                     stack_push(stack, low, pivot_pos - 1);
                     stack_push(stack, pivot_pos + 1, high);
                 } else {
                     stack_push(stack, pivot_pos + 1, high);
                     stack_push(stack, low, pivot_pos - 1);
                 }
             } else {
                 stack_push(stack, low, pivot_pos - 1);
             }
         } else if (high - pivot_pos > 0) {
             stack_push(stack, pivot_pos + 1, high);
         }
     }
     
     
     stack_destroy(stack);
 }