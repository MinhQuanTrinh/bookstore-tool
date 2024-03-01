#ifndef READFILE_H
#define READFILE_H

#define MAX_BOOK_TITLE_LENGTH 64
#define MAX_BOOK_AUTHOR_LENGTH 128
#define MAX_PRODUCT_NAME_LENGTH 128
#define MAX_PRODUCT_CODE_LENGTH 6

typedef struct Book {
    int bookID;
    char bookTitle[MAX_BOOK_TITLE_LENGTH];
    char bookAuthor[MAX_BOOK_AUTHOR_LENGTH];
    float bookPrice;
} Book;

typedef struct BookNode {
    Book book;
    struct BookNode* next;
} BookNode;

typedef struct Product {
    char productCode[MAX_PRODUCT_CODE_LENGTH];
    char productName[MAX_PRODUCT_NAME_LENGTH];
    int productPriceCents;
} Product;

typedef struct ProductNode {
    Product product;
    struct ProductNode* next;
} ProductNode;

typedef struct Bookstore {
    BookNode* books;
    ProductNode* products;
} Bookstore;

BookNode* readBooksFromFile(const char* filename);
ProductNode* readProductsFromFile(const char* filename);
Bookstore* readBookstoreFromFiles(const char* bookFilename, const char* productFilename);

#endif  /* HEADER_FILE_H */
/*90025338*/