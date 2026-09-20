#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr,n;
    int evencount=0;
    int oddcount=0;
    printf("enter the total number of Elements:\t",n);
    scanf("%d",&n);

    ptr= (int*)malloc(n*4);

    printf("Enter %d Elements:",n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }
    // Even Count
    printf("\nEven Numbers:");
    for(int i=0;i<n;i++){
        if(ptr[i] % 2==0){
            printf("%d\t",ptr[i]);
            evencount ++;
        }
    }

     // Odd Count
    printf("\nOdd Numbers:");
    for(int i=0;i<n;i++){
        if(ptr[i] % 2!=0){
            printf("%d",ptr[i]);
            oddcount ++;
        }
    }

    printf("\nEven:%d",evencount);
    printf("\nodd:%d",oddcount);


    return 0;
}