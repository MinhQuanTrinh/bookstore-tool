CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o readfile.o randompurchase.o bookid.o
EXEC=bookstore

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c readfile.h randompurchase.h bookid.h
	$(CC) $(CFLAGS) -c main.c

readfile.o: readfile.c readfile.h 
	$(CC) $(CFLAGS) -c readfile.c

randompurchase.o: randompurchase.c randompurchase.h
	$(CC) $(CFLAGS) -c randompurchase.c

bookid.o: bookid.c bookid.h
	$(CC) $(CFLAGS) -c bookid.c

clean:
	rm -f $(OBJ) $(EXEC)
