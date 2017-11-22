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
    int i, j, k = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%i ", array[k]);
            k++;
        }
        printf("\n");
    }
}

// Sorts the array from lowest number to the highest
int sort(int array[]) {
    int i;
    
    for (i = 0; i < sizeof(array); i++) {
        //do something..
    }
    
    return 0;
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
    
    printf("Unsorted array: \n");
    print(unsorted_numbers);
    
    // Copying the unsorted list before modifying
    for (j = 0; j < sizeof(unsorted_numbers); j++) {
        sorted_numbers[j] = unsorted_numbers[j];
    }
    
    printf("Sorted array: \n");
    //sort(unsorted_numbers);
    print(sorted_numbers);
    printf("End?\n");
    
    return 0;
}
