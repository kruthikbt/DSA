#include <stdio.h>
void input(int arr[],int size){
    printf("Enter the elements of the array:\n");
    for(int  i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int size){
    // Traversal Code
    printf("The elements are:\n");
    for(int  i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void display1(int arr[],int size){
    // Traversal Code
    printf("\nThe elements after deletion are:\n");
    for(int  i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
}


    

        // Deletion Code
int  deletion(int arr[],int size,int index){
    if(index > size ){
        return -1;
    }
    else{
        for ( int i = index ; i < size -1; i++)
        {
            arr[i]= arr[i+1];
        }
        
        return 1;
        
    }

}



int main() {
    int size=4;
    int index= 2;
    int arr[10];
    input(arr,size);

    printf("\n");
    display(arr,size);

    printf("\n");
    int result = deletion(arr,size,index);

    printf("\n");

    if(result == 1){
        printf("\nThe return Value:%d\n",result);
        size -= 1;
        display1(arr,size);
    }
    else{
        printf("\nNo Deletion took place as index is greater than the size of array");
    }
    printf("\n");
   
    

     return 0;
}     
    
    
   

