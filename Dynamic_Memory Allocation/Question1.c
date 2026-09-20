// Write a C program to:
// Dynamically allocate memory for 5 integers using malloc().
// Take 5 numbers from the user.
// Print all 5 numbers.
// Free the allocated memory.

#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr,n;
    ptr= (int*) malloc(n *4);
    printf("Enter the Numbers:\n");

    for(int i=0;i<5;i++){
        scanf("%d",&ptr[i]);
    }

    printf("The numbers are:\n");

    for(int i=0;i<5;i++){
        printf("%d\t",ptr[i]);
    }

    free(ptr);

    return 0;
}

