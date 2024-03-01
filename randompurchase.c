#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randompurchase.h"

/* Function to generate random purchases */
void generateRandomPurchases(Bookstore* bookstore) {
    int bookCount;
    int productCount;
    float totalprice;
    BookNode* currentBook;
    ProductNode* currentProduct;
    srand(time(NULL));

    bookCount = 0;
    productCount = 0;
    totalprice = 0.0f;
    printf("Name\t\t\t\t\tPrice\t\tQuantity\tSubtotal\n");

    /*random books*/
    currentBook = bookstore->books;
    while (currentBook != NULL && bookCount < 3) {
        Book book = currentBook->book;
        printf("%s\t$%.2f\t\t1\t\t$%.2f\n", book.bookTitle, book.bookPrice, book.bookPrice);
        totalprice += book.bookPrice;
        currentBook = currentBook->next;
        bookCount++;
    }
    /*random products*/
    currentProduct = bookstore->products;
    while (currentProduct != NULL && productCount < 2) {
        Product product = currentProduct->product;
        int quantity = rand() % 5 + 1; 
        float subtotalprice = product.productPriceCents / 100.0 * quantity;
        printf("%s\t$%.2f\t\t%d\t\t$%.2f\n", product.productName, product.productPriceCents / 100.0, quantity, subtotalprice);
        totalprice += subtotalprice;
        currentProduct = currentProduct->next;
        productCount++;
    }
    printf("Summary:\t\t\t$%.2f\n", totalprice);
}
/*90025338*/