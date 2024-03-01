#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "randompurchase.h"
#include "bookid.h"
Bookstore* readBookstoreFromFiles(const char* bookFilename, const char* productFilename);
void freeBookstore(Bookstore* bookstore);

int main() {
    const char* bookFilename = "books.txt";
    const char* productFilename = "products.txt";
    BookNode* currentBook;
    ProductNode* currentProduct;
    Bookstore* bookstore;
    int choice;
    printf("----------Bookworms Bookstore----------\n");
    printf("1.      Display all books and products\n");
    printf("2.      Generate random purchases\n");
    printf("3.      Track and save books\n");
    bookstore = readBookstoreFromFiles(bookFilename, productFilename);
    if (bookstore != NULL) {
        printf("Enter option: \n");
        scanf("%d", &choice);
        if (choice == 1){
        
            currentBook = bookstore->books;
            while (currentBook != NULL) {
                Book book = currentBook->book;
                printf("Book ID: %d\n", book.bookID);
                printf("Title: %s\n", book.bookTitle);
                printf("Author: %s\n", book.bookAuthor);
                printf("Price: $%.2f\n", book.bookPrice);
                currentBook = currentBook->next;
            }
            currentProduct = bookstore->products;
            while (currentProduct != NULL) {
                Product product = currentProduct->product;
                printf("Product Code: %s\n", product.productCode);
                printf("Name: %s\n", product.productName);
                printf("Price: %.f cents\n", product.productPriceCents * 1.0);
                currentProduct = currentProduct->next;
            }
        }
        else if (choice == 2){
            generateRandomPurchases(bookstore);
        }
        else if (choice == 3){
            saveBook(bookstore);
        }
        else {
            printf("Enter option: \n");
            scanf("%d", &choice);
        }
        freeBookstore(bookstore);
    } 
    else {
        printf("Error: Unable to read the Bookstore from files.\n");
    }
    return 0;
}
/* free memory */
void freeBookstore(Bookstore* bookstore) {
    ProductNode* currentProduct;
    BookNode* currentBook = bookstore->books;
    
    while (currentBook != NULL) {
        BookNode* nextBook = currentBook->next;
        free(currentBook);
        currentBook = nextBook;
    }
    currentProduct = bookstore->products;
    while (currentProduct != NULL) {
        ProductNode* nextProduct = currentProduct->next;
        free(currentProduct);
        currentProduct = nextProduct;
    }

    free(bookstore);
}

/*90025338*/