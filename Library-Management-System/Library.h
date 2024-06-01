
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/* Return status */
#define RET_OK  0;
#define RET_NOK 1;


// Create Structure of Library
typedef struct Book {
    char book_name[20];
    char author_name[20];
    uint32 pages;
    float32 price;
}Book_t;

void AddBookInfo();
void DisplayBookInfo();
void ListByAuthor();
void NumberOfBooks();


/******* idea of hiding struct members *******/
/*
typedef struct Library
{
    Book_t books[50];
    uint32 counter; // please don't modify this member
}Library_t;
*/

#endif
