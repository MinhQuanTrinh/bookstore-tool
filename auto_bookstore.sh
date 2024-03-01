#!/bin/bash
make
grep -r '".*"' *.c
./main < books.txt
if [ $? -ne 0 ]; then
    echo "Error"
fi
./main < products.txt
if [ $? -ne 0 ]; then
    echo "Error"
fi
