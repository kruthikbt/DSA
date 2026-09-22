#include <stdio.h>

int main() {
    int n;


    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    
    int arr[n];

    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("\nThe Array Elements are: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    
    return 0;
}