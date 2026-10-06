#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Books{

    int Book_ID;
    char author[50];
    char title[50];
    char status[50];
    float price;
};

struct Books * create(int n){
    struct Books *b;
    b= (struct Books*)malloc(n * sizeof(struct Books));

    if(b == NULL){
        printf("\n Memory Alloocation failed.\n");
    }
    else{
    for(int i=0;i<n;i++){
        printf("\nEnter the Book_ID: ");
        scanf("%d",b[i].Book_ID);

        printf("\nEnter the Book Name: ");
        scanf(" %[^\n]",b[i].title);

        printf("\nEnter the Book Author: ");
        scanf(" %[^\n]",b[i].author);

        printf("\nEnter the price: ");
        scanf("%.2f",b[i].price);

        printf("\nAvailability Status:(Available / Issued) : ");
        scanf("%.s",b[i].status);
    }
}
return b;
}

void display(struct Books b[],int n){
    printf("\n---------BOOK RECORDS------------\n");
    for (int i=0;i<n;i++){
        printf("Book_ID:%d",b[i].Book_ID);
        printf("Author Name:%s",b[i].author);
        printf("Book Name:%s",b[i].title);
        printf("Available Status:%s",b[i].status);
        printf("Price of Book:%.2f",b[i].price);
    }
}

void search(struct Books b[],int n){
    int id;
    int found=0;
    printf("\nENter the Book_ID to be searched: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++ ){
        if(b[i].Book_ID== id){
            printf("\nBook Found\n");
            printf("Book_ID:%d",b[i].Book_ID);
            printf("Author Name:%s",b[i].author);
            printf("Book Name:%s",b[i].title);
            printf("Price of Book:%.2f",b[i].price);
            printf("Available Status:%s",b[i].status);
            found =1;
            break;
         } else{
             printf("\nBook is not Available.\n");
        }
     }
            
 }    
   

       


void issueBook(struct Books b[],int n){
    int id;
    printf("\nEnter the Book_ID to be searched: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(b[i].Book_ID == id){
            if(strcmp(b[i].status,"Available")==0){
                strcpy(b[i].status,"Issued");
                printf("\nBook Is Issued Successfully.\n");
            }
            else{
                printf("\nBook Is already issued.\n");
            }
            return;
        }
    }
    printf("\nBook Not Found\n");
    
}

void returnBook(struct Books b[],int n){
    int id;
    printf("\nEnter the Book_ID to be searched: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(b[i].Book_ID == id){
            if(strcmp(b[i].status,"Available")==0){
                strcpy(b[i].status,"Returned");
                printf("\nBook Is Returned Successfully.\n");
            }
            else{
                printf("\nBook Is not  issued to be returned.\n");
            }
            return;
        }
    }
    printf("\nBook Not Found\n");
    
}

int main(){
    struct Books *b=NULL;
    int n,choice;
    printf("\nEnter the number of books n: ");
    scanf("%d",&n);

    do{
        printf("============== LIBRARY MENU =============");
        printf("\n1.Add Book Records\n");
        printf("\n2.Display the Book Records\n");
        printf("\n3.Search the book based on Book_ID\n");
        printf("\n4.Issue a Book\n");
        printf("\n5.Return a Book\n");
        printf("\n6.Exit\n");
        printf("=========================================");

        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                b= create(n);
                if(b != NULL){
                    printf("\n\nBook Records added Successfully.\n");
                }
                break;

            case 2:
                if(b == NULL){
                    printf("\nPlease Add the book Records First.\n");
                }
                else{
                    display(b,n);
                }
                break;

              case 3:
                if(b == NULL){
                    printf("\nPlease Add the book Records First.\n");
                }
                else{
                    search(b,n);
                }
                break;

             case 4:
                if(b == NULL){
                    printf("\nPlease Add the book Records First.\n");
                }
                else{
                    issueBook(b,n);
                }
                break;

            case 5:
                if(b == NULL){
                    printf("Plaese add the book Records first.\n");
                }
                else{
                    returnBook(b,n);
                }
                break;

            case 6:
               printf("\nExiting the Program...\n");
               break;

            default:
                printf("\nInvalid Choice.\n");
                
        }

    }while( choice != 6);
    if(b != NULL){
        free(b);
    }
    return 0;
    
}


