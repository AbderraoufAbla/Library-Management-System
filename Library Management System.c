#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_ISBN_LEN 20
#define MAX_BOOKS 100

// define a struct to represent a book
struct Book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char isbn[MAX_ISBN_LEN];
    int available_copies;
};

// function to add a book to the library
void addBook(struct Book *library, int *num_books) {
    struct Book new_book;

    // get user input for the new book's information
    printf("Enter title: ");
    fgets(new_book.title, MAX_TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;
    printf("Enter author: ");
    fgets(new_book.author, MAX_AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;
    printf("Enter ISBN: ");
    fgets(new_book.isbn, MAX_ISBN_LEN, stdin);
    new_book.isbn[strcspn(new_book.isbn, "\n")] = 0;
    printf("Enter number of copies: ");
    scanf("%d", &new_book.available_copies);
    getchar(); // consume newline character

    // add the new book to the library
    library[*num_books] = new_book;
    *num_books += 1;

    printf("Book added successfully.\n");
}

// function to remove a book from the library
void removeBook(struct Book *library, int *num_books, char *isbn) {
    int index = -1;

    // find the index of the book to remove
    for (int i = 0; i < *num_books; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found.\n");
    } else {
        // remove the book by shifting the array
        for (int i = index; i < *num_books - 1; i++) {
            library[i] = library[i+1];
        }
        *num_books -= 1;
        printf("Book removed successfully.\n");
    }
}

// function to borrow a book from the library
void borrowBook(struct Book *library, int num_books, char *isbn) {
    int index = -1;

    // find the index of the book to borrow
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].isbn, isbn) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found.\n");
    } else if (library[index].available_copies == 0) {
        printf("No copies of book available to borrow.\n");
    } else {
        // borrow the book by decrementing the available copies
        library[index].available_copies -= 1;
        printf("Book borrowed successfully.\n");
    }
}

 return 0;
}
