#include <stdio.h>
#define MAX 100
int stack[MAX];
int top =-1;

void push(){
    int x;
    if( top == MAX -1){
        printf("Overflow! The Stack is full");
    }else{
        printf("Enter the element to enter the stack: ");
        scanf("%d",&x);
        stack[++top]= x;
        printf("Successfully Added the element ");
        printf("\n");
    }
}

void pop(){
    if(top == -1){
        printf("Underflow! Stack is empty");
    }else{
        printf("deleted Element :%d",stack[top--]);
    }
}

void display(){
    if(top == -1){
        printf("Underflow!");
    }else{
        for(int i=top;i>=top;i--){
            printf("\nStack Elements: \n%d",stack[i]);
        }
    }
    printf("\n");
}

int main(){
    int choice;
    do{
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter the Operation to be performed: ");
        scanf("%d",&choice);

    switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program...");
        default:
            printf("Invalid Choice ");
        }
    }while( choice != 4);
return 0 ;
}