#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int duplicate(int array[100], int number){
    int answer = 0, i;
    
    for (i = 0; i < 100; i++) {
        if (array[i] == number) {
            answer = 1;
        }
    }
    return answer;
}

int main(){
    
    int number, max = 800, min = 100, i, j;
    int total_numbers[100];
    
    srand((int)time(NULL));
    
    
    for (i = 0; i < 100; i++) {
        
        number = rand() % max + min;
        printf("Första: %i\n", number);
        
        while (duplicate(total_numbers, number) == 1) {
            
            number = rand() % max + min;
            printf("Rest: %i\n", number);
        }
        
        total_numbers[i] = number;
        
    }
    
    for (j = 0; j < 100; j++) {
        printf("%i. %i\n", j + 1, total_numbers[j]);
    }
    
    return 0;
}
