#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>


// Checks if the array contains the number from the input variable
int duplicate(int array[100], int number){
    int answer = 0, i;

    for (i = 0; i < sizeof(array); i++) {
        if (array[i] == number) {
            answer = 1;
        }
    }
    return answer;
}

// Prints the array of number in the correct format
void print(int array[]){
    int i;
    int rowsum = 0, val = 0, col, columsum[10] = {0}, row;
    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            printf("%i ", array[val]);
            rowsum += array[val];
            columsum[col] += array[val];

            val++;
        }
        printf(" :: Radsumman av rad %i är %i\n",row + 1,rowsum);
        rowsum = 0;
    }

    printf("Kolumnsumma: ");
    for (i = 0; i < 10; i++)
    {
        printf("%i ", columsum[i]);
    }
    printf("\n");
}

// Sorts the array from lowest number to the highest
int * sort(int array[]) {
    int i, j, temp;

    for (i = 0; i < 100 - 1; i++) {
        for (j = 0; j < 100 - 1; j++)
        {
            if (array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}

// Quicksort compare function
int cmpfunc (const void * a, const void * b) {
    return (* (int*) a - *(int*) b);
}

void count(int array[])
{
    int i, sum = 0;
    for (i = 0; i < 100; i++)
    {
        sum+=array[i];
    }
    sum/=100;
    printf("Medelvärdet är: %i\n", sum);
    printf("Medianen är: %i\n", (array[49] + array[50]) / 2);
    printf("Maxvärde: %i\n", array[99]);
    printf("Minvärde: %i\n", array[0]);
}


int main(){

    // Initialzing some variables
    int number, max = 800, min = 100, i, j;
    int unsorted_numbers[100], sorted_numbers[100];

    // Seed for the random number generator
    srand((int)time(NULL));

    // Adds random number between min and max, excludes duplicates
    for (i = 0; i < 100; i++) {
        number = rand() % max + min;

        while (duplicate(unsorted_numbers, number) == 1) {
            number = rand() % max + min;
        }
        unsorted_numbers[i] = number;
    }

    // Printing unsorted array (1)
    printf("Unsorted array: \n");
    print(unsorted_numbers);
    printf("\n");
    
    // Copying the unsorted list before modifying
    for (j = 0; j < sizeof(unsorted_numbers)/sizeof(int); j++) {
        sorted_numbers[j] = unsorted_numbers[j];
    }

    // Sorting and printing the array (2)
    printf("Sorted array: \n");
    sort(sorted_numbers);
    //qsort(sorted_numbers, 100, sizeof(int), cmpfunc);
    print(sorted_numbers);
    printf("\n");
    
    // Prints out Calculations (3)
    count(sorted_numbers);

    // Binary search for numbers (4)
    //search(sorted_numbers);

    return 0;
}
