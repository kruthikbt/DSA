#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    struct stack *s;
    s->size=100;
    s->top=-1;
    s->arr = (int *)malloc(s->size *sizeof(int));

    s->arr[0]= 5;
    s->top++;
    //Check if stack is empty 
    if(isEmpty(s)){
        printf("\nStack is Empty");
    }
    else{
        printf("\nStack is not empty");
    }
    
    if(isFull(s)){
        printf("\nStack is Full");
    }
    else{
        printf("\nStack is not Full");
    }
    
   
    return 0;

    
}

