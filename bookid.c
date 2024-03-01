#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#include "bookid.h"
int countBooks(Bookstore* bookstore) {
    int count = 0;
    BookNode* currentBook = bookstore->books;
    while (currentBook != NULL) {
        count++;
        currentBook = currentBook->next;
    }
    return count;
}

/*Retrieve books based on IDs*/
Book getBookAtIndex(Bookstore* bookstore, int index) {
    BookNode* currentBook = bookstore->books;
    int count = 0;
    Book emptyBook = {0, "", "", 0.0}; /*0 for ID, "" for title, "" for author, 0.0 for price*/
    while (currentBook != NULL) {
        if (count == index) {
            return currentBook->book;
        }
        count++;
        currentBook = currentBook->next;
    }
    return emptyBook;
}

void saveBook(Bookstore* bookstore) {
    int i;
    FILE* file;
    int bookIndex = 0;
    int charIndex = 0;
    unsigned char* bookIds;
    int numChars;
    int totalBooks;

    file = fopen("book_tracker.txt", "w");
    totalBooks = countBooks(bookstore);
    numChars = totalBooks / 2 + (totalBooks % 2 == 0 ? 0 : 1);
    bookIds = (unsigned char*)malloc(numChars * sizeof(unsigned char));
    while (bookIndex < totalBooks) {
        Book book = getBookAtIndex(bookstore, bookIndex);
        unsigned char firstId = (unsigned char)(book.bookID % 16);
        unsigned char secondId = (unsigned char)(book.bookID / 16);

        bookIds[charIndex] = (secondId << 4) | firstId;
        bookIndex++;
        charIndex++;
        /*Odd number handling*/
        if (bookIndex == totalBooks && totalBooks % 2 != 0) {
            bookIds[charIndex] |= 0xF0;
        }
    }
    /*hexadecimal format*/
    for (i = 0; i < numChars; i++) {
        fprintf(file, "%02X ", bookIds[i]);
    }
    fclose(file);
    free(bookIds);
}
