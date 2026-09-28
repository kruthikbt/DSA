#include <stdio.h>
int lenear_search(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[]={1,2,3,56,47,89};
    int size= sizeof(arr)/sizeof(int);
    int element =67;
    int result = lenear_search(arr,size,element);
    printf("The element %d is found at index %d ",element,result);
    
    return 0;
}