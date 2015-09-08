#include <stdio.h>
#include <stdlib.h>

unsigned long global_assignment_count;
unsigned long global_comparison_count;

void count_bubble_sort(unsigned long numbers[], unsigned long size);
void count_bubble_sort_improved(unsigned long numbers[], unsigned long size);
void count_selection_sort(unsigned long numbers[], unsigned long size);
void count_insertion_sort(unsigned long numbers[], unsigned long size);
void count_insertion_sort_improved(unsigned long numbers[], unsigned long size);
void count_heap_sort(unsigned long* numbers, unsigned long size);
void heapify(unsigned long* numbers, unsigned long size);
void heap_down(unsigned long* numbers, unsigned long size, signed long i);
void remove_min(unsigned long numbers[], signed long* size);
void count_quicksort(unsigned long numbers[], unsigned long size);

int main(int argc, char* argv[])
{
   const unsigned long SIZE = 100;
   unsigned long* pNumbers1;
   unsigned long* pNumbers2;
   unsigned long* pNumbers3;
   unsigned long* pNumbers4;
   unsigned long* pNumbers5;
   unsigned long* pNumbers6;
   unsigned long* pNumbers7;
   long double total_count1 = 0;
   long double total_comparison1 = 0;
   long double total_count2 = 0;
   long double total_comparison2 = 0;
   long double total_count3 = 0;
   long double total_comparison3 = 0;
   long double total_count4 = 0;
   long double total_comparison4 = 0;
   long double total_count5 = 0;
   long double total_comparison5 = 0;
   long double total_count6 = 0;
   long double total_comparison6 = 0;
   long double total_count7 = 0;
   long double total_comparison7 = 0;
   unsigned int i, j;

   pNumbers1 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers1 == NULL){
      printf("Failed to allocate pNumbers1\n");
      exit(1);
   }

   pNumbers2 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers2 == NULL){
      printf("Failed to allocate pNumbers2\n");
      exit(1);
   }

   pNumbers3 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers3 == NULL){
      printf("Failed to allocate pNumbers3\n");
      exit(1);
   }

   pNumbers4 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers4 == NULL){
      printf("Failed to allocate pNumbers4\n");
      exit(1);
   }

   pNumbers5 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers5 == NULL){
      printf("Failed to allocate pNumbers5\n");
      exit(1);
   }

   pNumbers6 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers6 == NULL){
      printf("Failed to allocate pNumbers6\n");
      exit(1);
   }

   pNumbers7 = (unsigned long*)malloc(sizeof(unsigned long int) * SIZE);
   if(pNumbers7 == NULL){
      printf("Failed to allocate pNumbers6\n");
      exit(1);
   }

   for(i=0; i<100; i++)
   {
      for(j=0; j<SIZE; j++)
      {
         pNumbers1[j] = ((unsigned long)rand() << (sizeof(unsigned long) - sizeof(int))*8) + rand();
         pNumbers7[j] = 
	 pNumbers6[j] = 
	 pNumbers5[j] = 
	 pNumbers4[j] = 
	 pNumbers3[j] = 
	 pNumbers2[j] = 
	 pNumbers1[j];
      }
      //Bubble Sort
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_bubble_sort(pNumbers1, SIZE);
      total_count1 += global_assignment_count;
      total_comparison1 += global_comparison_count;

      //Bubble Sort Improved
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_bubble_sort_improved(pNumbers2, SIZE);
      total_count2 += global_assignment_count;
      total_comparison2 += global_comparison_count;

      //Selection Sort
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_selection_sort(pNumbers3, SIZE);
      total_count3 += global_assignment_count;
      total_comparison3 += global_comparison_count;

      //Insertion Sort
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_insertion_sort(pNumbers4, SIZE);
      total_count4 += global_assignment_count;
      total_comparison4 += global_comparison_count;

      //Improved Insertion Sort
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_insertion_sort_improved(pNumbers5, SIZE);
      total_count5 += global_assignment_count;
      total_comparison5 += global_comparison_count;

      //Heap Sort
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_heap_sort(pNumbers6, SIZE);
      total_count6 += global_assignment_count;
      total_comparison6 += global_comparison_count;	  
      
      //Quick Sort
      global_assignment_count = 0;
      global_comparison_count = 0;
      count_quicksort(pNumbers7, SIZE);
      total_count7 += global_assignment_count;
      total_comparison7 += global_comparison_count;	  
   }

   printf("Bubble Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count1/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison1/100);
   printf("Improved Bubble Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count2/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison2/100);
   printf("Selection Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count3/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison3/100);
   printf("Insertion Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count4/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison4/100);
   printf("Improved Insertion Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count5/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison5/100);
   printf("Heap Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count6/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison6/100);
   printf("Quick Sort:\n");
   printf("\tglobal assignment average: %Lf\n", total_count7/100);
   printf("\tglobal comparison average: %Lf\n", total_comparison7/100);

   free(pNumbers1);
   free(pNumbers2);
   free(pNumbers3);
   free(pNumbers4);
   free(pNumbers5);
   free(pNumbers6);
   free(pNumbers7);
   return 0;
}


void count_bubble_sort(unsigned long numbers[], unsigned long size)
{
   int something_swapped = 1;
   unsigned long i;
   unsigned long temp;
   while(something_swapped)
   {
      global_comparison_count++;
      something_swapped = 0; global_assignment_count++;
      global_assignment_count++; //for loop initialization
      for(i = 0; i<size-1; i++)
      {
         global_comparison_count++; //for loop condition
         global_assignment_count++; //for loop i++
         global_comparison_count++; //if statement
         if(numbers[i] > numbers[i+1])
         {
            temp = numbers[i]; global_assignment_count++;
            numbers[i] = numbers[i+1]; global_assignment_count++;
            numbers[i+1] = temp; global_assignment_count++;
            something_swapped = 1; global_assignment_count++;
         }
      }
      global_comparison_count++; //for loop condition
   }
   global_comparison_count++;
}

void count_bubble_sort_improved(unsigned long numbers[], unsigned long size)
{
   int something_swapped = 1;
   unsigned long i;
   unsigned long temp;
   int count = 0;
   while(something_swapped)
   {
      global_comparison_count++;
      something_swapped = 0; global_assignment_count++;
      global_assignment_count++; //for loop initialization
      for(i = 0; i<size-1-count; i++)
      {
         global_comparison_count++; //for loop condition
         global_assignment_count++; //for loop i++
         global_comparison_count++; //if statement
         if(numbers[i] > numbers[i+1])
         {
            temp = numbers[i]; global_assignment_count++;
            numbers[i] = numbers[i+1]; global_assignment_count++;
            numbers[i+1] = temp; global_assignment_count++;
            something_swapped = 1; global_assignment_count++;
         }
      }
      global_comparison_count++; //for loop condition
      count++; global_assignment_count++;
   }
   global_comparison_count++;
}

void count_selection_sort(unsigned long numbers[], unsigned long size)
{
   unsigned long i, j;
   unsigned long min_index;
   unsigned long temp;

   global_assignment_count++; //for loop initialization
   for(i = 0; i<size-1; i++)
   {
      //find the minimum starting at i and ending at size -1
      global_comparison_count++; //for loop condition
      global_assignment_count++; //for loop i++
      global_assignment_count++; //for loop initialization
      min_index = i; global_assignment_count++;
      for(j=i; j<size-1; j++)
      {
         global_comparison_count++; //for loop condition
         global_assignment_count++; //for loop j++
         global_comparison_count++; //if statement
         if(numbers[j] < numbers[min_index])
         {
            min_index = j; global_assignment_count++;
         }
      }
      global_comparison_count++; //for loop condition
      //swap the mimimum into position i
      temp = numbers[i]; global_assignment_count++;
      numbers[i] = numbers[min_index]; global_assignment_count++;
      numbers[min_index] = temp; global_assignment_count++;
   }
   global_comparison_count++; //for loop condition
}

//1. Naive Insertion Sort
void count_insertion_sort(unsigned long numbers[], unsigned long size)
{
	unsigned long i, j;
	unsigned long temp;

	global_assignment_count++; //for loop initialization
	for(i = 0; i < size; i++){
		global_comparison_count++; //for loop condition
		global_assignment_count++; //for i++

		j = i; global_assignment_count++; 
		while(j > 0 && numbers[j] < numbers[j-1]){
			global_comparison_count++; global_comparison_count++; //while loop condition
			temp = numbers[j]; global_assignment_count++;
			numbers[j] = numbers[j-1];global_assignment_count++;
			numbers[j-1] = temp;global_assignment_count++;
			j--; global_assignment_count++;
		}
		global_comparison_count++; //last check to exit while loop
	}
	global_comparison_count++; //last check to exit for loop
}

//2. Improved Insertion Sort
void count_insertion_sort_improved(unsigned long numbers[], unsigned long size)
{
	unsigned long i, j, min_index = 0; 
	unsigned long temp;
	
	global_assignment_count++; //initialize min_index
	global_assignment_count++; //for loop initialization
	for(i = 0; i < size; i++){
		global_comparison_count++; //for loop condition
		global_assignment_count++; //for i++
		
		global_comparison_count++; //if condition
		if(numbers[min_index] > numbers[i]){
			min_index = i; global_assignment_count++;
		}
	}
	temp = numbers[min_index]; global_assignment_count++;
	numbers[min_index] = numbers[0]; global_assignment_count++;
	numbers[0] = temp; global_assignment_count++;

	global_assignment_count++; //for loop initialization
	for(i = 1; i < size; i++){
		global_comparison_count++; //for loop condition
		global_assignment_count++; //for i++
		
		j = i; global_assignment_count++;
		temp = numbers[j]; global_assignment_count++;
		while(temp < numbers[j-1]){
			global_comparison_count++; //while loop condition
			numbers[j] = numbers[j-1]; global_assignment_count++;
			j--; global_assignment_count++;
		}
		numbers[j] = temp; global_assignment_count++;
		global_comparison_count++; //last check to exit while loop
	}
	global_comparison_count++; //last check to exit for loop
}

//3. Heap Sort
void count_heap_sort(unsigned long numbers[], unsigned long size)
{
        unsigned long i;
	signed long temp_size = size;

	global_assignment_count++; //for temp_size
        heapify(numbers, size);
	global_assignment_count += 2; //for function call, 2 formal parameters

	global_assignment_count++; //for loop initialization
        for(i = 0; i < size; i++){
		global_comparison_count++; //for loop condition
		global_assignment_count++; //for i++

                remove_min(numbers, &temp_size);
		global_assignment_count += 2; //for function call, 2 formal parameters
        }

}

void heapify(unsigned long numbers[], unsigned long size)
{
        signed long i;

	global_assignment_count++; //for loop initialization
        for(i = (size/2) - 1; i >= 0; i--){
		global_comparison_count++; //for loop condition
                global_assignment_count++; //for i++

                heap_down(numbers, size, i);
		global_assignment_count += 3; //for function call, 3 formal parameters

        }
}

void heap_down(unsigned long numbers[], unsigned long size, signed long i)
{
        unsigned long max_child_index, left, right;
        unsigned long temp;

	global_comparison_count++; //if condition
	if(size <= 1){
		return;
	}

	global_comparison_count++; //if condition
        if(i <= (size/2) - 1){
                left = i*2 + 1; global_assignment_count++;
                right = i*2 + 2; global_assignment_count++;

                max_child_index = left; global_assignment_count++;

		global_comparison_count++; //if condition
                if(right < size){
                        max_child_index = (numbers[left] > numbers[right])? left:right;
			global_comparison_count++; global_assignment_count++; //ternary operator
                }

		global_comparison_count++; //if condition
                if(numbers[i] < numbers[max_child_index]){
                        temp = numbers[i]; global_assignment_count++;
                        numbers[i] = numbers[max_child_index]; global_assignment_count++;
                        numbers[max_child_index] = temp; global_assignment_count++;
                }

                heap_down(numbers, size, max_child_index);
		global_assignment_count += 3; //for function call, 3 formal parameters
        }
}

void remove_min(unsigned long numbers[], signed long* size)
{
        unsigned long temp;

	global_comparison_count++; //if condition
        if(*size <= 0){
                return;
        }

        temp = numbers[0]; global_assignment_count++;
        numbers[0] = numbers[*size - 1]; global_assignment_count++;
        numbers[*size - 1] = temp; global_assignment_count++;
        (*size)--; global_assignment_count++;

        heap_down(numbers, *size, 0);
	global_assignment_count += 3; //for function call, 3 formal parameters
}

//4. Quicksort
void count_quicksort(unsigned long numbers[], unsigned long size)
{
	unsigned long pivot, L, R;
	unsigned long temp;

	global_comparison_count++; //if condition
	if(size < 2){
		return;
	}

	pivot = rand() % size; global_assignment_count++;
	temp = numbers[0]; global_assignment_count++;
	numbers[0] = numbers[pivot]; global_assignment_count++;
	numbers[pivot] = temp; global_assignment_count++;
	pivot = numbers[0]; global_assignment_count++;

	global_assignment_count++; //for loop initialization
	for(L = 0, R = size-1;; L++, R--){
		global_comparison_count += 2; //for loop conditions
		global_assignment_count += 2; //for L++, R--
		
		while(pivot < numbers[R]){
			global_comparison_count++; //while condition
			R--; global_assignment_count++;
		}
		global_comparison_count++; //last check to exit while loop
		while(pivot > numbers[L]){
			global_comparison_count++; //while condition
			L++; global_assignment_count++;
		}
		global_comparison_count++; //last check to exit while loop

		global_comparison_count++; //if condition
		if(L >= R){
			break;
		}

		temp = numbers[L]; global_assignment_count++;
		numbers[L] = numbers[R]; global_assignment_count++;
		numbers[R] = temp; global_assignment_count++;
	}
	count_quicksort(numbers, L);
        global_assignment_count += 2; //for function call, 2 formal parameters
	count_quicksort(numbers + L, size - L);
	global_assignment_count += 2; //for function call, 2 formal parameters
}
