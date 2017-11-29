#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>


// Checks if the array contains the number from the input variable
int duplicate(int array[100], int number){
    int answer = 0, i;

    for (i = 0; i < 100; i++) {
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
        printf(" :: Rowsum of row %i is %i\n",row + 1,rowsum);
        rowsum = 0;
    }

    printf("Kolumnsumma: \n");
    for (i = 0; i < 10; i++)
    {
        printf("Kolumn %i %i\n", i + 1, columsum[i]);
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
        sum += array[i];
    }
    sum /= 100;
    printf("Average value: %i\n", sum);
    printf("Median: %i\n", (array[49] + array[50]) / 2);
    printf("Max value: %i\n", array[99]);
    printf("Minimum value: %i\n", array[0]);
}

// Binary seach function
void search (int array[], int comp)
{
    int high = 100, low = 0, mid;
    
    while ((high - low) > 1) {
    
        mid = (high + low) / 2;
        
        if (comp >= array[mid]) {
            low = mid;
        }
        
        else {
            high = mid;
        }
    }
    
    // Returns the searched value if it exist
    if (comp == array[low]) {
        printf("Number searched: %i found on position %i\n", comp, low + 1);
        }
    
    //Returns a faulty value telling the code that the searched number does not exist
    else {
        printf("Number not found: %i\n", comp);
        }
}

// Checks an array
int choice(int array[], int number) {
    int answer = -1, i;
    
    if (number == 1) {
        answer = 1;
    }
    
    else if (number == 2) {
        for (i = 0; i < 50; i++) {
            if (array[i] == 1) {
                answer = 2;
                break;
            }
            else {
                answer = -1;
            }
        }
    }
    
    else if (number == 3 || number == 4 || number == 5){
        int temp1 = 0, temp2 = 0;
        
        for (i = 0; i < 50; i++) {
            if (array[i] == 1) {
                temp1 = 1;
            }
            else if (array[i] == 2) {
                temp2 = 1;
            }
            
            if (temp1 == 1 && temp2 == 1) {
                answer = number;
            }
            else {
                answer = -1;
            }
        }
    }
    return answer;
}

int main(){

    // Initialzing some variables
    int number, max = 800, min = 100, input, value = 0, temp = 0;
    
    // Fixed size for array, quick fix
    int log[50] = {0};
    int unsorted_numbers[100], sorted_numbers[100];

    do {
        printf("Enter a number: ");
        scanf("%i", &input);
        printf("\n");
        
        log[temp] = input;
        
        switch (choice(log, input)) {
            case 1:
                // Seed for the random number generator
                srand((int)time(NULL));
                
                // Adds random number between min and max, excludes duplicates
                int i, j;
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
                printf("\n");
                break;
                
            case 2:

                // Sorting and printing the array (2)
                printf("Sorted array: \n");
                sort(sorted_numbers);
                //qsort(sorted_numbers, 100, sizeof(int), cmpfunc);
                print(sorted_numbers);
                printf("\n");
                break;
                
                
            case 3:
                // Prints out Calculations (3)
                count(sorted_numbers);
                printf("\n");
                break;
            
            case 4:
                // Binary search for numbers (4)
                printf("Search for a number: ");
                scanf("%i", &value);
                search(sorted_numbers, value);
                printf("\n");
                break;
                
            default:
                printf("No menu choice for that number\n");
                printf("\n");
                break;
        }
        temp++;
        printf("Enter '0' to exit\n");
    } while (input != 0);

    return 0;
}
