// Write a C program to:
// Find the largest number of all

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int *ptr;
    int largest;

    printf("Enter the value of n:");
    scanf("%d",&n);

    ptr= (int*)calloc(n,4);
    printf("Enter %d numbers:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }

    largest=ptr[0];
    for(int i=0;i<n;i++){
        if(ptr[i]>largest){
            largest= ptr[i];
        }
    }

    printf("The Largest number is :%d",largest);
    free(ptr);
    return 0;
}
   
 

