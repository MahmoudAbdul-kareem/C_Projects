
#include "Library.h"

// create library of 100 books
static Book_t Library[100];
// To count the number of books in the library
static uint32 BookCounter = 0;


void AddBookInfo()
{
    printf("Enter book name = ");
    scanf("%s", Library[BookCounter].book_name);

    printf("Enter author name = ");
    scanf("%s", Library[BookCounter].author_name);

    printf("Enter pages = ");
    scanf("%d", &(Library[BookCounter].pages));

    printf("Enter price = ");
    scanf("%f", &(Library[BookCounter].price));
    BookCounter++;
}

void DisplayBookInfo()
{
    uint32 iterator = 0;

    printf("==========Books in the library==========\n");
    printf("name\t author\t pages\t price\n");
    for(iterator = 0; iterator < BookCounter; iterator++)
    {
        printf("%s\t", Library[iterator].book_name);
        printf(" %s\t", Library[iterator].author_name);
        printf(" %d\t", Library[iterator].pages);
        printf(" %0.2f\n", Library[iterator].price);
        printf("====================================\n");
    }
}

void ListByAuthor()
{
    uint32 iterator = 0;
    char author[20] = "";

    printf("Enter author name: ");
    scanf("%s", author);
    printf("==========Books by %s ==========\n", author);
    printf("name\t author\t pages\t price\n");
    for(iterator = 0; iterator < BookCounter; iterator++)
    {
        if(0 == strcmp(author, Library[iterator].author_name))
        {
            printf("%s\t", Library[iterator].book_name);
            printf(" %s\t", Library[iterator].author_name);
            printf(" %d\t", Library[iterator].pages);
            printf(" %0.2f\n", Library[iterator].price);
            printf("====================================\n");
        }
        else{}
    }
}

void NumberOfBooks()
{
    printf("Number of books in the library is: %i", BookCounter);
}
