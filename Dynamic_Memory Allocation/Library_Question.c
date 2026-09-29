
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing book details
struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
    int status;          // 1 = Available, 0 = Issued
};

// Global variables
struct Book *books = NULL;
int count = 0;


// Function to add book records
void create() {
    int n, i;

    printf("\nHow many books do you want to add? ");
    scanf("%d", &n);

    books = (struct Book *)realloc(
        books,
        (count + n) * sizeof(struct Book)
    );

    if (books == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (i = count; i < count + n; i++) {

        printf("\nEnter details of Book %d\n", i + 1);

        printf("Book ID : ");
        scanf("%d", &books[i].id);

        printf("Title   : ");
        scanf(" %[^\n]", books[i].title);

        printf("Author  : ");
        scanf(" %[^\n]", books[i].author);

        printf("Price   : ");
        scanf("%f", &books[i].price);

        printf("Status (1 = Available, 0 = Issued): ");
        scanf("%d", &books[i].status);
    }

    count = count + n;

    printf("\nBook records added successfully!\n");
}


// Function to display all books
void display() {
    int i;

    if (count == 0) {
        printf("\nNo books in the library.\n");
        return;
    }

    printf("\n===== ALL BOOK RECORDS =====\n");

    for (i = 0; i < count; i++) {

        printf("\nBook %d\n", i + 1);
        printf("ID     : %d\n", books[i].id);
        printf("Title  : %s\n", books[i].title);
        printf("Author : %s\n", books[i].author);
        printf("Price  : %.2f\n", books[i].price);

        if (books[i].status == 1)
            printf("Status : Available\n");
        else
            printf("Status : Issued\n");
    }
}


// Function to search for a book
void search() {
    int id;
    int pos = -1;
    int i;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {

        if (books[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nBook not found.\n");
    }
    else {
        printf("\n===== BOOK FOUND =====\n");
        printf("ID     : %d\n", books[pos].id);
        printf("Title  : %s\n", books[pos].title);
        printf("Author : %s\n", books[pos].author);
        printf("Price  : %.2f\n", books[pos].price);

        if (books[pos].status == 1)
            printf("Status : Available\n");
        else
            printf("Status : Issued\n");
    }
}


// Function to issue a book
void issueBook() {
    int id;
    int pos = -1;
    int i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {

        if (books[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nBook not found.\n");
    }
    else if (books[pos].status == 0) {
        printf("\nSorry, this book is already issued.\n");
    }
    else {
        books[pos].status = 0;

        printf(
            "\nBook '%s' has been issued successfully.\n",
            books[pos].title
        );
    }
}


// Function to return a book
void returnBook() {
    int id;
    int pos = -1;
    int i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {

        if (books[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nBook not found.\n");
    }
    else if (books[pos].status == 1) {
        printf("\nThis book was not issued.\n");
    }
    else {
        books[pos].status = 1;

        printf(
            "\nBook '%s' has been returned successfully.\n",
            books[pos].title
        );
    }
}


// Main function
int main() {
    int choice;

    do {

        printf("\n============================\n");
        printf("       LIBRARY MENU\n");
        printf("============================\n");

        printf("1. Add Book Records\n");
        printf("2. Display All Book Records\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    // Free dynamically allocated memory
    free(books);

    return 0;
}

