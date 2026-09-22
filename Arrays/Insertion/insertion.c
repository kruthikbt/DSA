#include <stdio.h>
void input(int arr[],int n){
    printf("Enter the elements of the array:\n");
    for(int  i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int n){
    // Traversal Code
    printf("The elements are:");
    for(int  i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void display1(int arr[],int n){
    // Traversal Code
    printf("The elements after sorting are:");
    for(int  i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
}

    

        // Insertion Code
int  insertion(int arr[],int size,int index,int element ,int capacity){
    if(size >=capacity ){
        return -1;
    }
    else{
        for ( int i = size-1; i >= index; i--)
        {
            arr[i+1]= arr[i];
        }
        arr[index]=element;
        return 1;
        
    }

}



int main() {
    int size=4;
    int index= 1,element =54;
    int arr[3];
    input(arr,size);
    display(arr,size);
    int result= insertion(arr,size,index,element,3);
    size +=1;
    printf("\n");
    printf("\n");
    

    if(result == -1){
        printf("The Array is not Inserted with given element\n");
    }
    else{
        display1(arr,size);
    }
    
    return 0;
}
