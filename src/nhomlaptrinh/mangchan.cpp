#include<stdio.h>
#define MAX_SIZE  100
typedef struct Array{
    int numbers[MAX_SIZE];
    int size;
};
void swap(int &number1, int number2);
void enter(Array &input);
void printValue(Array output);
void printEvenNumbers(Array source);
Array findEvenNumbers(Array source);
int main(){
    Array list;
    enter(list);
    printValue(list);
    printEvenNumbers(list);
    return 0;
}
void enter(Array &input){
    int temp;
    printf("Enter the size of array: ");
    scanf("%d", &input.size); 
    for(int index = 0; index < input.size; index++){
        printf("enter number a[%d]: ",index);
        scanf("%d", &temp);
        input.numbers[index] = temp;
    }
}
void swap(int &number1, int number2){
    
}
void printValue(Array output){
    for(int index = 0; index < output.size; index++){
        printf("%4d ",output.numbers[index]);
    }
}
Array findEvenNumbers(Array source){
    Array even_numbers;
    even_numbers.size = 0;
    for(int index = 0; index < source.size; index++){
        if(source.numbers[index] % 2 == 0){
            even_numbers.size++;
            even_numbers.numbers[even_numbers.size-1] = source.numbers[index]; 
        }
    }
    return even_numbers;     
}
void printEvenNumbers(Array source){
    Array even_numbers = findEvenNumbers(source);
    printf("\nyour result: ");
    printValue(even_numbers);
}
