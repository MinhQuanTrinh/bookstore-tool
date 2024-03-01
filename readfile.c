#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

#define MAX_LINE_LENGTH 256

/*create a new BookNode */
BookNode* createBookNode(Book book) {
    BookNode* newNode = (BookNode*)malloc(sizeof(BookNode));
    if (newNode != NULL) {
        newNode->book = book;
        newNode->next = NULL;
    }
    return newNode;
}

/*create a new ProductNode */
ProductNode* createProductNode(Product product) {
    ProductNode* newNode = (ProductNode*)malloc(sizeof(ProductNode));
    if (newNode != NULL) {
        newNode->product = product;
        newNode->next = NULL;
    }
    return newNode;
}

/*read Books from a file and create a linked list */
BookNode* readBooksFromFile(const char* filename) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    int bookID;
    char bookTitle[64];
    char bookAuthor[128];
    float bookPrice;
    Book book;
    BookNode* newNode;
    BookNode* head = NULL;
    BookNode* current = NULL;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file '%s' \n", filename);
        return NULL; /*Return NULL if the file cannot be opened*/
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        /*in case if gonna wonder why there is != 1 in the following line, i typed in == 4 at first
        place and if i did so and executed the code, nothing would be printed on the terminal (which I'm not
        sure if it was the empty spaces between the characters), so just make things simple with != 1*/
        if (sscanf(line, "%d %[^|] | %[^|] | $%f", &bookID, bookTitle, bookAuthor, &bookPrice) != 1) {
            strncpy(book.bookTitle, bookTitle, sizeof(book.bookTitle) - 1);
            strncpy(book.bookAuthor, bookAuthor, sizeof(book.bookAuthor) - 1);
            book.bookPrice = bookPrice;
            book.bookID = bookID;
            /*printf("Book ID: %d\n", book.bookID);
            printf("Book Title: %s\n", book.bookTitle);
            printf("Book Author: %s\n", book.bookAuthor);
            printf("Book Price:$%.2f\n", book.bookPrice);*/
            newNode = createBookNode(book);
            if (newNode != NULL) {
                if (head == NULL) {
                    head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = newNode;
                }
            }
        }
    }

    fclose(file);
    return head;
}

/*read Products from a file and create a linked list */
ProductNode* readProductsFromFile(const char* filename) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    
    Product product;
    ProductNode* newNode;
    ProductNode* head = NULL;
    ProductNode* current = NULL;   
    
    file = fopen(filename, "r");
    if (file == NULL) {
        return NULL; /*Return NULL if the file cannot be opened*/
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char productCode[6];
        char productName[128];
        float productPrice;
        /*same idea as the function above*/
        if (sscanf(line, "%5s - %[^-] - $%f", productCode, productName, &productPrice) != 1) {
            strncpy(product.productCode, productCode, sizeof(product.productCode) - 1);
            strncpy(product.productName, productName, sizeof(product.productName) - 1);
            product.productPriceCents = (int)(productPrice * 100);

            newNode = createProductNode(product);
            if (newNode != NULL) {
                if (head == NULL) {
                    head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = newNode;
                }
            }
        }
    }

    fclose(file);
    return head;
}

/*read a Bookstore from text files */
Bookstore* readBookstoreFromFiles(const char* bookFilename, const char* productFilename) {
    Bookstore* bookstore = (Bookstore*)malloc(sizeof(Bookstore));
    if (bookstore == NULL) {
        return NULL; /*Return NULL if memory allocation fails*/
    }

    bookstore->books = readBooksFromFile(bookFilename);
    bookstore->products = readProductsFromFile(productFilename);

    return bookstore;
}
/*90025338*/
